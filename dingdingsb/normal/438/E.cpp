#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
#define mod 998244353
struct modint{
    int x;
    modint(int o=0){x=o;}
    modint &operator = (int o){return x=o,*this;}
    modint &operator +=(modint o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint &operator -=(modint o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint &operator *=(modint o){return x=1ll*x*o.x%mod,*this;}
    modint &operator ^=(int b){
        modint a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint &operator ++(int){return x++,*this;}
    modint &operator /=(modint o){return *this *=o^=mod-2;}
    modint &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint &operator /=(int o){return *this *= ((modint(o))^=mod-2);}
    template<class I>friend modint operator +(modint a,I b){return a+=b;}
    template<class I>friend modint operator -(modint a,I b){return a-=b;}
    template<class I>friend modint operator *(modint a,I b){return a*=b;}
    template<class I>friend modint operator /(modint a,I b){return a/=b;}
    friend modint operator ^(modint a,int b){return a^=b;}
    friend bool operator ==(modint a,int b){return a.x==b;}
    friend bool operator !=(modint a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint operator - () {return x?mod-x:0;}
};
const int N=4e6+5;
const modint GG=3,Ginv=modint(1)/3;
struct poly{
	vector<modint>a;
	modint&operator[](int i){return a[i];}
	int size(){return a.size();}
	void resize(int n){a.resize(n);}
};
int rev[N];
inline int ext(int n){int k=0;while((1<<k)<n)k++;return k;}
inline void init(int k){int n=1<<k;for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));}
inline void ntt(poly&a,int k,int typ){
	int n=1<<k;
	for(int i=0;i<n;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
	for(int mid=1;mid<n;mid<<=1){
		modint wn=(typ>0?GG:Ginv)^((mod-1)/(mid<<1));
		for(int r=mid<<1,j=0;j<n;j+=r){
			modint w=1;
			for(int k=0;k<mid;k++,w=w*wn){
				modint x=a[j+k],y=w*a[j+k+mid];
				a[j+k]=x+y,a[j+k+mid]=x-y;
			}
		}
	}
	if(typ<0){
		modint inv=modint(1)/n;
		for(int i=0;i<n-1;i++)a[i]*=inv;
	}
}
inline poly one(){poly a;a.a.push_back(1);return a;}
poly operator +(poly a,poly b){
	int n=max(a.size(),b.size());a.resize(n),b.resize(n);
	for(int i=0;i<n;i++)a[i]+=b[i];return a;
}
poly operator -(poly a,poly b){
	int n=max(a.size(),b.size());a.resize(n),b.resize(n);
	for(int i=0;i<n;i++)a[i]-=b[i];return a;
}
inline poly operator*(poly a,poly b){
	int n=a.size()+b.size()-1,k=ext(n);
	a.resize(1<<k),b.resize(1<<k),init(k);
	ntt(a,k,1);ntt(b,k,1);for(int i=0;i<(1<<k);i++)a[i]*=b[i];
	ntt(a,k,-1),a.resize(n);return a;
}
poly inv(poly F,int k){
	int n=1<<k;F.resize(n);
	if(n==1){F[0]=modint(1)/F[0];return F;}
	poly G,H=inv(F,k-1);
	G.resize(n),H.resize(n<<1),F.resize(n<<1);
	for(int i=0;i<n/2;i++)G[i]=H[i]*2;
	init(k+1),ntt(H,k+1,1),ntt(F,k+1,1);
	for(int i=0;i<(n<<1);i++)H[i]=H[i]*H[i]*F[i];
	ntt(H,k+1,-1),H.resize(n);
	for(int i=0;i<n;i++)G[i]-=H[i];return G;
}
inline poly inv(poly a){
	int n=a.size();
	a=inv(a,ext(n)),a.resize(n);return a;;
}
poly sqrt(poly F,int k){
	int n=1<<k;F.resize(n);
	if(n==1){F[0]=modint(1)/F[0];return F;}
	poly G,H=sqrt(F,k-1);
	H.resize(n);init(k);poly invH=inv(H);
	G.resize(n),H.resize(n<<1),F.resize(n<<1);
	init(k+1),ntt(H,k+1,1);
	for(int i=0;i<(n<<1);i++)H[i]=H[i]*H[i];
	ntt(H,k+1,-1),H.resize(n);
	for(int i=0;i<n;i++)G[i]=H[i]+F[i];
	G=G*invH;G.resize(n);for(int i=0;i<n;i++)G[i]/=2;
	return G;
}
inline poly sqrt(poly a){
	int n=a.size();
	a=sqrt(a,ext(n)),a.resize(n);return a;;
}
poly G;
signed main(){
	int n,m,x;
	read(n,m);G.resize(m+1);
	for(int i=1;i<=n;i++){read(x);if(x<=m)G[x]++;}
	for(int i=0;i<=m;i++)G[i]=modint(0)-G[i]*4;G[0]++;
	G=sqrt(G);G[0]++;G=inv(G);
	for(int i=1;i<=m;i++)write((2*G[i]).x),putchar('\n');
}