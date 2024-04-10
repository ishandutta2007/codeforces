// What am I doing ??? 
#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
//------------------polynomial begin------------------
const int maxn=1048576;
const int mod=998244353,_k=119,_b=23,_g=3; //mod=_k*2^_b+1 _gmod
//const int mod=950009857,_k=453,_b=21,_g=7; //mod=_k*2^_b+1 _gmod
//const int mod=786433,_k=3,_b=18,_g=10; //mod=_k*2^_b+1 _gmod
inline void inc(int &x,int y){x+=y;if (x>=mod) x-=mod;}
inline void dec(int &x,int y){x-=y;if (x<0) x+=mod;}
inline int qp(int x,int y){int z=1;while(y){if(y&1)z=1ll*z*x%mod;y>>=1;x=1ll*x*x%mod;}return z;}
namespace polynomial
{
    namespace basic
    {
        int fac[maxn+5],inv[maxn+5],fi[maxn+5],lg[maxn+5],pw[maxn+5],w[maxn+5],iw[maxn+5];
        bool tag=0;
        inline void init()
        {
            tag=1;int i;fz(i,2,maxn) lg[i]=lg[i>>1]+1;pw[0]=1;fz1(i,lg[maxn]) pw[i]=pw[i-1]*2; 
            fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,maxn){
                fac[i]=1ll*fac[i-1]*i%mod;inv[i]=(mod-mod/i)*1ll*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;
            }
            w[0]=1;w[1]=qp(_g,(mod-1)/maxn);fz(i,2,maxn) w[i]=1ll*w[i-1]*w[1]%mod;
            iw[maxn]=qp(w[maxn],mod-2);fd0k(i,maxn) iw[i]=1ll*iw[i+1]*w[1]%mod;
            if (iw[0]!=1){puts("wrong iw!!!!!!!!!!!!!!!!!");exit(-1);}
        }
        int rev[maxn+5],a[maxn+5],b[maxn+5];
        inline int getrev(int x)
        {
            if (!tag) init();int i,s=1;while (s<x) s*=2;rev[0]=0;fz1(i,s-1) rev[i]=((rev[i>>1]>>1)|((i&1)<<(lg[s]-1)));return s;
        }
        inline void ntt(int *a,int n,int *w)
        {
            if (!tag) init();int i,j,k;
            fz0k(i,n) if (rev[i]<i) swap(a[i],a[rev[i]]);
            for (i=1;i<n;i<<=1){int ys=maxn/i/2;
                for (j=0;j<n;j+=i+i){
                    int *t=w;
                    fz0k(k,i){
                        int x=a[j+k],y=1ll*a[j+k+i]*(*t)%mod;
                        a[j+k]=x+y;if (a[j+k]>=mod) a[j+k]-=mod;
                        a[j+k+i]=x-y;if (a[j+k+i]<0) a[j+k+i]+=mod;
                        t+=ys;
                    }
                }
            }
        }
        inline vector<int> mul(const vector<int> &aa,const vector<int> &bb) //aa*bb
        {
            vector<int> ans;long long br=1ll*aa.size()*bb.size(),ft=1ll*(aa.size()+bb.size())*lg[aa.size()+bb.size()]*10+100;
            if (br<ft){
                while (ans.size()+1<aa.size()+bb.size()) ans.push_back(0);
                int i,j;fz0k(i,aa.size()) fz0k(j,bb.size()) inc(ans[i+j],1ll*aa[i]*bb[j]%mod);
            }
            else{
                int len=getrev(aa.size()+bb.size()),i;
                fz0k(i,len) a[i]=b[i]=0;
                fz0k(i,aa.size()) a[i]=aa[i];
                fz0k(i,bb.size()) b[i]=bb[i];
                ntt(a,len,w);ntt(b,len,w);
                fz0k(i,len) a[i]=1ll*a[i]*b[i]%mod;
                ntt(a,len,iw);int inv=qp(len,mod-2);
                fz0k(i,len) ans.push_back(1ll*a[i]*inv%mod);
            }
            while (!ans.empty()&&!ans.back()) ans.pop_back();
            return ans;
        }
        inline vector<int> mul2(const vector<int> &aa,const vector<int> &bb) //aa^2*bb
        {
            int len=getrev(aa.size()+aa.size()+bb.size()),i;
            fz0k(i,len) a[i]=b[i]=0;fz0k(i,aa.size()) a[i]=aa[i];fz0k(i,bb.size()) b[i]=bb[i];
            ntt(a,len,w);ntt(b,len,w);fz0k(i,len) a[i]=1ll*a[i]*b[i]%mod*a[i]%mod;ntt(a,len,iw);
            vector<int> ans;int inv=qp(len,mod-2);fz0k(i,len) ans.push_back(1ll*a[i]*inv%mod);while (!ans.empty()&&!ans.back()) ans.pop_back();
            return ans;
        }
    };
    struct poly
    {
        vector<int> v;
        inline void clear(){v.clear();}
        inline int size(){return v.size();}
        inline bool empty(){return v.empty();}
        inline int back(){return v.back();}
        inline void pop_back(){v.pop_back();}
        inline void push_back(int x){v.push_back(x);}
        inline void read(int n){clear();while (n--){int x;scanf("%d",&x);v.push_back(x);}}
        inline void print(){ff(v,it) printf("%d ",*it);puts("");} 
        inline void print(int n){int i;for(i=0;i<n;i++)if(i<v.size())printf("%d ",v[i]);else printf("0 ");puts("");}
        inline poly operator+(const poly &x)const{vector<int> s;int i;for (i=0;i<x.v.size()||i<v.size();i++){int t=0;if(i<v.size())inc(t,v[i]);if(i<x.v.size())inc(t,x.v[i]);s.push_back(t);}return(poly){s};}
        inline poly operator-(const poly &x)const{vector<int> s;int i;for (i=0;i<x.v.size()||i<v.size();i++){int t=0;if(i<v.size())inc(t,v[i]);if(i<x.v.size())dec(t,x.v[i]);s.push_back(t);}return(poly){s};}
        inline poly operator*(const int &x)const{vector<int> s;int i;for (i=0;i<v.size();i++)s.push_back(1ll*x*v[i]%mod);return(poly){s};}
        inline poly operator*(const poly &x)const{return (poly){basic::mul(v,x.v)};}
        inline void mul_x(){int i;v.push_back(0);fd1(i,v.size()-1)v[i]=v[i-1];v[0]=0;} // this*=x
        inline void divi_x(){int i;fz0k(i,((int)v.size())-1)v[i]=v[i+1];v.pop_back();} // this/=x
        inline void derivation(){int i;fz0k(i,((int)v.size())-1)v[i]=1ll*v[i+1]*(i+1)%mod;v.pop_back();} // this=this
        inline void integral(){int i;v.push_back(0);fd1(i,v.size()-1)v[i]=1ll*v[i-1]*basic::inv[i]%mod;v[0]=0;} // this=this 
        inline void size_down(int x){while (v.size()>x)v.pop_back();}
        inline void size_up(int x){while (v.size()<x)v.push_back(0);}
        inline void resize(int x){size_down(x);size_up(x);}
        inline int &operator[](const int &x){if (v.size()<=x)size_up(x+1);return v[x];}
    };
    inline poly derivation(poly a){a.derivation();return a;}
    inline poly integral(poly a){a.integral();return a;}
    inline poly mul_x(poly a){a.mul_x();return a;}
    inline poly divi_x(poly a){a.divi_x();return a;}
    inline poly poly_inv(poly a,int n)
    {
    	while (!a.empty()&&!a.back()) a.pop_back();
    	if (a.empty()){fprintf(stderr,"wrong poly_inv(0) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");return a;}
    	poly ta,tb;ta.push_back(a[0]);tb.push_back(qp(a[0],mod-2));int i,j;
    	for (i=1;i<n;i<<=1){
    		for (j=i;j<(i<<1)&&j<n;j++){
    			ta.push_back(a[j]);
    		}
    		tb=tb*2-((poly){basic::mul2(tb.v,ta.v)});
    		tb.size_down(min((i<<1),n));
    	}
    	return tb;
    }
    inline poly poly_ln(poly a,int n)
    {
    	while (!a.empty()&&!a.back()) a.pop_back();
    	if (a.empty()){fprintf(stderr,"wrong poly_ln(0) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");return a;}
    	if (a[0]!=1){
    		fprintf(stderr,"bad template poly_ln a[0]!=1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");return a;
    	}
    	a=integral(derivation(a)*poly_inv(a,n));a.size_down(n);
    	return a;
    }
    inline poly poly_exp(poly a,int n)
    {
    	while (!a.empty()&&!a.back()) a.pop_back();
    	if (a.empty()){a.push_back(1);return a;}
    	if (a[0]!=0){
    		fprintf(stderr,"bad template poly_exp a[0]!=0 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");return a;
    	}
    	poly ta,tb,uit;uit.push_back(1);ta.push_back(a[0]);tb.push_back(1);int i,j;
    	for (i=1;i<n;i<<=1){
    		for (j=i;j<n&&j<(i<<1);j++){
    			ta.push_back(a[j]);
    		}
    		tb=tb*(uit-poly_ln(tb,(i<<1))+ta);
    		tb.size_down(min((i<<1),n));
    	}
    	return tb;
    }
    inline poly poly_sqrt(poly a,int n)
    {
    	while (!a.empty()&&!a.back()) a.pop_back();
    	if (a.empty()){return a;}
    	poly ta,tb;ta.push_back(a[0]);
    	if (a[0]==1){
    		tb.push_back(1);
    	}
    	else{
    		fprintf(stderr,"bad template in poly_sqrt a[0]!=1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");return a;
    	}
    	int i,inv2=qp(2,mod-2),j;for (i=1;i<n;i<<=1){
    		for (j=i;j<(i<<1)&&j<n;j++) ta.push_back(a[j]);
    		tb=(tb+(ta*poly_inv(tb,(i<<1))))*inv2;
    		tb.size_down(min((i<<1),n));
    	}
    	if (tb[0]>mod-tb[0]) tb=tb*(mod-1); 
    	return tb;
    }
    inline poly poly_pow(poly a,int n,int k) // a^k mod (x^n) 
    {
    	while (!a.empty()&&!a.back()) a.pop_back();
    	if (a.empty()){return a;}
    	int k0=0;while (k0<a.size()&&a.v[k0]==0) k0++;int i;
    	poly b;for (i=k0;i<a.size();i++) b.v.push_back(a.v[i]);
    	int t=b.v[0];b=b*(qp(t,mod-2));t=qp(t,k);
    	k0=min(1ll*k0*k,1ll*n);b=poly_exp(poly_ln(b,n)*k,n)*t;
    	a.clear();while (k0--) a.v.push_back(0);
    	int idx=0;while (a.v.size()<n) a.v.push_back(b[idx++]);
    	return a;
    }
    inline poly operator/(poly a,poly b)
    {
    	while (!a.empty()&&!a.back()) a.pop_back();
    	while (!b.empty()&&!b.back()) b.pop_back();
    	if (b.empty()){fprintf(stderr,"wrong poly_div(a,0) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");exit(-1);}
    	reverse(a.v.begin(),a.v.end());reverse(b.v.begin(),b.v.end());
    	int n=a.size(),m=b.size(),k=n-m+1;if (k<=0){poly ans;ans.push_back(0);return ans;}
    	a.size_down(k);b.size_down(k);a=a*poly_inv(b,k);a.size_down(k);
    	reverse(a.v.begin(),a.v.end());return a;
    }
    inline poly operator%(poly a,poly b)
    {
    	while (!a.empty()&&!a.back()) a.pop_back();
    	while (!b.empty()&&!b.back()) b.pop_back();
    	if (b.empty()){fprintf(stderr,"wrong poly_mod(a,0) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");exit(-1);}
    	int m=b.size();a=a-a/b*b;
        a.size_down(m-1);return a;
    }
    inline void poly_divmod(poly a,poly b,poly &s1,poly &s2) // a/b=s1......s2
    {
    	while (!a.empty()&&!a.back()) a.pop_back();s1.clear();
    	while (!b.empty()&&!b.back()) b.pop_back();s2.clear();
    	if (b.empty()){fprintf(stderr,"wrong poly_divmod(a,0) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");exit(-1);}
    	poly c=a,d=b;reverse(a.v.begin(),a.v.end());reverse(b.v.begin(),b.v.end());
    	int n=a.size(),m=b.size(),k=n-m+1;if (k<0){s1.push_back(0);s2=a;return;}
    	a.size_down(k);b.size_down(k);s1=a*poly_inv(b,k);s1.size_down(k);
    	reverse(s1.v.begin(),s1.v.end());s2=c-s1*d;
        s2.size_down(m-1);
    }
    inline int poly_fuhe_inv(poly a,int n)
    {
    	while (!a.empty()&&!a.back()) a.pop_back();
    	if (a[0]!=0){fprintf(stderr,"wrong poly_fuhe_inv(0) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");exit(-1);}
    	int i;for (i=0;i+1<a.size();i++) a[i]=a[i+1];a.pop_back();
    	if (!basic::tag) basic::init();return 1ll*(poly_pow(poly_inv(a,n),n,n)[n-1])*basic::inv[n]%mod;
    }
    namespace seg_tree
    {
        poly v[maxn*4],v2[maxn*4];
        vector<int> px,py;
        void build(int x,int l,int r)
        {
            if (l==r){
                v[x].clear();int t=mod;dec(t,px[l]); 
                v[x].v.push_back(t);v[x].v.push_back(1);
                return;
            }
            int mid=(l+r)/2;build(x+x,l,mid);build(x+x+1,mid+1,r);
            v[x]=v[x*2]*v[x*2+1];
        }
        void qiuzhi(poly a,int x,int l,int r)
        {
            if (l==r){
                py[l]=a[0];return;
            }
            int mid=(l+r)/2;qiuzhi(a%v[x+x],x+x,l,mid);qiuzhi(a%v[x+x+1],x+x+1,mid+1,r);
        }
        void chazhi(int x,int l,int r)
        {
            if (l==r){
            	v2[x].clear();
            	v2[x].push_back(py[l]);
            	return;
            }
            int mid=(l+r)/2;chazhi(x+x,l,mid);chazhi(x+x+1,mid+1,r);
            v2[x]=v[x+x]*v2[x+x+1]+v2[x+x]*v[x+x+1]; 
        }
    };
    vector<int> poly_qiuzhi(const vector<int> &todo,const poly &a)
    {
        seg_tree::px.clear();seg_tree::py.clear();ff(todo,it){
            seg_tree::px.push_back(*it);seg_tree::py.push_back(0);
        }
        seg_tree::build(1,0,todo.size()-1);
        seg_tree::qiuzhi(a%seg_tree::v[1],1,0,todo.size()-1);
        return seg_tree::py;
    }
    poly poly_chazhi(vector<int> px,vector<int> py)
    {
        seg_tree::px.clear();seg_tree::py.clear();
		ff(px,it){
            seg_tree::px.push_back(*it);seg_tree::py.push_back(0);
        }
		seg_tree::build(1,0,px.size()-1);
        poly f=seg_tree::v[1];f.derivation();
        seg_tree::qiuzhi(f,1,0,px.size()-1);
        int i;fz0k(i,px.size()) seg_tree::py[i]=1ll*qp(seg_tree::py[i],mod-2)*py[i]%mod;
        seg_tree::chazhi(1,0,px.size()-1);
        return seg_tree::v2[1];
	}
};using namespace polynomial;
//------------------polynomial end------------------
int n,m,i,j;
poly R;
int calc(int n)
{
	return basic::fac[n-1];
//	return 1ll*R[n]*basic::fac[n]%mod;
}
int main()
{
	basic::init();
	read(n);
/*	poly T;T[0]=0;
	fz1(i,n) T[i]=1ll*qp(i,i-1)*basic::fi[i]%mod;
	R=(poly){{1}}+T-(T*T*((mod+1)/2));*/
	poly f;
	fz1(i,n){
		if(i<=(n-1)/2) f[i]=1ll*calc(i)*basic::fi[i]%mod;
	}
//	fz0k(i,n) cerr<<1ll*f[i]*basic::fac[i]%mod<<' ';cerr<<endl;
//	f=poly_inv((poly){{1}}-f,n);
	f=poly_exp(f,n);
//	fz0k(i,n) cerr<<1ll*f[i]*basic::fac[i]%mod<<' ';cerr<<endl;
	fz0k(i,n){
		if(n-i-1<=(n-1)/2){
			f[i]=1ll*f[i]*calc(n-i-1)%mod;
		}
		else{
			f[i]=0;
		}
	}
//	fz0k(i,n) cerr<<1ll*f[i]*basic::fac[i]%mod<<' ';cerr<<endl;
	poly g;
	fz0k(i,n) g[i]=basic::fi[i];
	poly h=f*g;
	fz1(i,n){
		if(i==1){
			i=2;
			printf("%d ",1ll*h[n-i]*basic::fac[n-i]%mod*(i-1)%mod);
			i=1;
			continue;
		}
		printf("%d ",1ll*h[n-i]*basic::fac[n-i]%mod*(i-1)%mod);
	}
	return 0;
}