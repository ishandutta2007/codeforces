#include<bits/stdc++.h>
namespace in{
    #ifndef slow
    char buf[1<<21],*p1=buf,*p2=buf;
    inline int getc(){return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;}
    #else
    inline int getc(){return getchar();}
    #endif
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
        static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
        while (len>=0)putc(buf[len]),--len;
    }
}
using namespace std;
const int mod=1e9+7;
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
    modint &operator++(int){return *this+=1;}
};
const int N=610;
int n;
modint a[N][N];
modint det(int n){
	modint res=1;
	for(int i=1;i<=n;i++){
		int k=i;
		for(int j=i;j<=n;j++)
			if(a[j][i]!=0){k=j;break;}
		if(a[k][i]==0)return 0;
		if(i!=k)res=-res,swap(a[i],a[k]);
		for(int j=i+1;j<=n;j++){
			if(a[j][i]==0)continue;
			modint inv=a[j][i]/a[i][i];
			for(int l=i;l<=n;l++)
				a[j][l]-=a[i][l]*inv;
		}
		res*=a[i][i];
	}
	return res;
}
modint ans[N];
modint x[N][N];
void Guess(){
	for(int i=0;i<n;i++){
		int k=i;
		for(int j=i;j<n;j++)
			if(x[j][i]!=0)
				{k=j;break;}
		if(x[k][i]==0)exit(-1);
		if(i!=k)swap(x[k],x[i]);
		for(int j=i+1;j<n;j++){
			modint inv=x[j][i]/x[i][i];
			for(int l=i;l<=n;l++)
				x[j][l]-=x[i][l]*inv;
		}
	}
	for(int i=n-1;i>=0;i--){
		ans[i]=x[i][n];
		for(int j=i+1;j<n;j++)
			ans[i]-=x[i][j]*ans[j];
		ans[i]/=x[i][i];
	}
}
int D[N][N],E[N][N];
signed main(){
	in::read(n);
	for(int i=1,u,v;i<n;i++)
		in::read(u,v),D[u][u]++,D[v][v]++,E[v][u]++,E[u][v]++;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)x[i][j]=modint(i+1)^j;
		for(int u=1;u<=n;u++)
			for(int v=1;v<=n;v++)
				if(u==v)a[u][v]=D[u][u]*(i+1)+(n-D[u][u]-1);
				else if(E[u][v]) a[u][v]=mod-(i+1);
				else a[u][v]=mod-1;
		x[i][n]=det(n-1);
	}
	Guess();
    for(int i=0;i<n;i++)
    	out::write(ans[i].x),out::putc(' ');
	out::flush();
    return 0;
}