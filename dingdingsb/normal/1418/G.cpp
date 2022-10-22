#include<bits/stdc++.h>
#define int unsigned long long
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
		static char buf[15];static int len=-1;if(x>=0){do{buf[++len]=x%10+48,x/=10;}while (x);}else{putc('-');do {buf[++len]=-(x%10)+48,x/=10;}while(x);}
		while (len>=0)putc(buf[len]),--len;
	}
}
using namespace std;
const int N=5e5+1000;
int n,a[N],ans,DP1[N],DP2[N],pre[N][3];
template<int base,int mod>
struct myhash{
	int power[N],state;
	myhash(){
		state=0;
		power[0]=1;
		for(int i=1;i<N;i++)
			power[i]=(power[i-1]*base)%mod;
	}
	void operator+=(const int x){
		state=(state+power[x])%mod;
	}
	void operator-=(const int x){
		state=(state-2*power[x]+2*mod)%mod;
	}
};
myhash<15260279ll,3158565539ll>H1;
myhash<15260279ll,1526024417ll>H2;
unordered_map<int,int>Q1,Q2;
signed main(){
	in::read(n);int p1=1;
	for(int i=1;i<=n;i++){
		Q1[H1.state]++,
		Q2[H2.state]++;
		DP1[i]=H1.state;
		DP2[i]=H2.state;
		int x;in::read(x);a[x]++;
		if(pre[x][0]){
			if(pre[x][1]){
				if(pre[x][2])
					while(p1<=pre[x][2])
						Q1[DP1[p1]]--,
						Q2[DP2[p1]]--,
						p1++;
				pre[x][2]=pre[x][1];
			}
			pre[x][1]=pre[x][0];
		}
		pre[x][0]=i;
		if(a[x]!=3)H1+=x,H2+=x;
		else a[x]=0,H1-=x,H2-=x;
		ans+=min(Q1[H1.state],Q2[H2.state]);
		//cout<<H1.state<<" "<<H2.state<<endl;
	}
	cout<<ans;
	return 0;
}