#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 600000
#define INT __int128
using namespace std;
namespace FastIO
{
	#define FS 100000
	#define Tp template<typename Ty>
	#define Ts template<typename Ty,typename... Ar>
	#define tc() (FA==FB&&(FB=(FA=FI)+fread(FI,1,FS,stdin),FA==FB)?EOF:*FA++)
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char oc,FI[FS],FO[FS],OS[FS],*FA=FI,*FB=FI,*FC=FO,*FE=FO+FS;
	void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}struct IO_Cl {~IO_Cl() {clear();}}CL;
	Tp void read(Ty& x) {x=0;while(!isdigit(oc=tc()));while(x=(x<<3)+(x<<1)+(oc&15),isdigit(oc=tc()));}
	Ts void read(Ty& x,Ar&... y) {read(x),read(y...);}
	void readc(char& x) {while(isspace(x=tc()));}
	Tp void writeln(Ty x) {while(OS[++OT]=x%10+48,x/=10);while(OT) pc(OS[OT--]);pc('\n');}
}using namespace FastIO;
int n,a[N+5],nxt[N+5],Q[N+5],C[N+5],V[N+5];char s[N+5];vector<int> g[N+5];
int main()
{
	int i,j;read(n),readc(s[1]),read(a[1]),writeln(a[1]);
	int H=1,T=0,x,p,c,mn=a[1];INT t=0,ans=a[1];for(i=2,j=0;i<=n;writeln(ans+=t),++i)
	{
		readc(s[i]),read(a[i]),s[i]='a'+(s[i]-'a'+ans)%26,a[i]^=ans&((1<<30)-1);
		mn=min(mn,a[i]),ans+=mn;while(j&&s[j+1]^s[i]) j=nxt[j];s[j+1]==s[i]&&++j;nxt[i]=j;
		if(!j) {for(x=nxt[i-1];x;x=nxt[x]) g[i].push_back(x);t=0,H=T+1;continue;}
		for(x=nxt[i-1];x>=j;x=nxt[x]) {g[i].push_back(x),t-=V[H],--C[H];while(H<=T&&!C[H]) ++H;}
		for(auto x:g[j]) g[i].push_back(x),p=lower_bound(Q+H,Q+T+1,i-x)-Q,t-=V[p],--C[p];
		c=0;while(H<=T&&!C[H]) ++H;while(H<=T&&V[T]>a[i]) {t-=1LL*(V[T]-a[i])*C[T],c+=C[T--];while(H<=T&&!C[H]) ++H;}
		s[i]==s[1]&&(t+=a[i],++c),c&&(Q[++T]=i,V[T]=a[i],C[T]=c);
	}return 0;
}