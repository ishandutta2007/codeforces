#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
const int maxn=524288;
const int mod=998244353,_k=119,_b=23,_g=3;
int n,m,i,j,num[200005];
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
        inline int operator[](const int &x){return v[x];}
        inline poly operator+(const poly &x)const{vector<int> s;int i;for (i=0;i<x.v.size()||i<v.size();i++){int t=0;if(i<v.size())inc(t,v[i]);if(i<x.v.size())inc(t,x.v[i]);s.push_back(t);}return(poly){s};}
        inline poly operator-(const poly &x)const{vector<int> s;int i;for (i=0;i<x.v.size()||i<v.size();i++){int t=0;if(i<v.size())inc(t,v[i]);if(i<x.v.size())dec(t,x.v[i]);s.push_back(t);}return(poly){s};}
        inline poly operator*(const int &x)const{vector<int> s;int i;for (i=0;i<v.size();i++)s.push_back(1ll*x*v[i]%mod);return(poly){s};}
		inline poly operator*(const poly &x)const{return (poly){basic::mul(v,x.v)};}
        inline void derivation(){int i;fz0k(i,v.size())v[i]=1ll*v[i+1]*(i+1)%mod;v.pop_back();} // this=this
        inline void integral(){int i;v.push_back(0);fd1(i,v.size()-1)v[i]=1ll*v[i-1]*basic::inv[i]%mod;} // this=this 
        inline void size_down(int x){while (v.size()>x)v.pop_back();}
    };
};using namespace polynomial;
poly solve(int l,int r)
{
	if(l==r){
		poly a;
		if(num[l]==num[l%n+1]){
			a.push_back(0);a.push_back(m%mod);
		}
		else{
			a.push_back(1);a.push_back((m-2)%mod);a.push_back(1);
		}
		return a;
	}
	int mid=(l+r)/2;
	return solve(l,mid)*solve(mid+1,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	fz1(i,n){
		scanf("%d",&num[i]);
	}
	poly ans=solve(1,n);
//	ans.print();
	int sum=0,len=ans.size();
	for(i=n+1;i<len;i++){
		inc(sum,ans[i]);
	}
	cout<<sum<<endl;
	return 0;
}