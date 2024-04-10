// Problem: Pairwise Modulo
// Contest: Codeforces
// URL: https://m1.codeforces.ml/contest/1553/problem/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;
namespace in{
    char buf[1<<21],*p1=buf,*p2=buf;
    inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    template <typename T>inline void read(T& t){
        t=0;int f=0;char ch=getc();while (!isdigit(ch)){if(ch=='-')f = 1;ch=getc();}
        while(isdigit(ch)){t=t*10+ch-48;ch = getc();}if(f)t=-t;
    }
    template <typename T,typename... Args> inline void read(T& t, Args&... args){read(t);read(args...);}
}
namespace out{
    char buffer[1<<21];int p1=-1;const int p2 = (1<<21)-1;
    inline void flush(){fwrite(buffer,1,p1+1,stdout),p1=-1;}
    inline void putc(const char &x) {if(p1==p2)flush();buffer[++p1]=x;}
    template <typename T>void write(T x) {
        static char buf[25];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
        while (len>=0)putc(buf[len]),--len;
    }
}
typedef long long ll;
const int N=3e5+100,SZ=sqrt(N);
const int MX=300000,bl=(MX-1)/SZ+1;
int n,a[N];int l[N],r[N],id[N];
void init(){
	for(int i=1;i<=bl;i++){
		l[i]=(i-1)*SZ+1;
		r[i]=min(i*SZ,MX);
		for(int j=l[i];j<=r[i];j++)
			id[j]=i;
	}
}
struct SJJG{
	ll Pre[N],pre[N];
	void add(int pos,int val){
		for(int i=id[pos];i<=bl;i++)
			Pre[i]+=val;
		for(int i=pos;i<=r[id[pos]];i++)
			pre[i]+=val;
	}
	ll qry(int pos){
		if(pos==0)return 0;
		if(pos>MX)pos=MX;
		return pre[pos]+Pre[id[pos]-1];
	}
	ll qry(int l,int r){
		return qry(r)-qry(l-1);
	}
}Sum,Cnt;
ll p[N];
ll tot[N];
signed main(){
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	init();
	in::read(n);for(int i=1;i<=n;i++)in::read(a[i]);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1];
		p[i]+=Sum.qry(1,a[i]-1);
		p[i]+=1ll*a[i]*Cnt.qry(a[i]+1,MX);
		p[i]+=1ll*a[i]*Cnt.qry(1,a[i]-1);
		p[i]+=Sum.qry(a[i]+1,MX);
		if(a[i]!=1){
			for(int l=1,r;l<=a[i];l=r+1){
				if(a[i]/l==0)break;
				r=a[i]/(a[i]/l);
				p[i]-=Sum.qry(l,r)*(a[i]/l);
			}
		}
		if(a[i]<=SZ)p[i]-=1ll*a[i]*tot[a[i]];
		else{
			for(int l=a[i],r=2*a[i]-1;l<=MX;l+=a[i],r+=a[i]){
				p[i]-=1ll*a[i]*(l/a[i])*Cnt.qry(l,r);
			}
		}
		Sum.add(a[i],a[i]);
		Cnt.add(a[i],1);
		for(int j=1;j<=SZ;j++)
			if(a[i]>j)
				tot[j]+=a[i]/j;
		out::write(p[i]);out::putc(' ');
	}out::flush();
	return 0;
	cout<<"*cfnm*l";
}