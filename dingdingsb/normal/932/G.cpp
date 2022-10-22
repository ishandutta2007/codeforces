// Problem: CF932G Palindrome Partition
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF932G
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
template<class T,class ...ARK>void write(T x,ARK...ark){write(x);pc(' ');write(ark...);}
template<class ...ARK>void writeln(ARK...ark){write(ark...);pc('\n');}
typedef long long ll;
const int mod=1e9+7;
struct mint{
	int x;mint(int o=0){x=o;}mint&operator+=(mint a){return(x+=a.x)%=mod,*this;}mint&operator-=(mint a){return(x+=mod-a.x)%=mod,*this;}
	mint&operator*=(mint a){return(x=1ll*x*a.x%mod),*this;}mint&operator^=( int b){mint a=*this;x=1;while(b)(b&1)&&(*this*=a,1),a*=a,b>>=1;return*this;}mint&operator/=(mint a){return*this*=(a^=mod-2);}
	friend mint operator+(mint a,mint b){return a+=b;}friend mint operator-(mint a,mint b){return a-=b;}friend mint operator*(mint a,mint b){return a*=b;}friend mint operator/(mint a,mint b){return a/=b;}
	friend mint operator^(mint a, int b){return a^=b;}mint operator-(){return 0-*this;}
};
#define lowbit(x) ((x)&-(x))
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1|1)
const int N=1e6+10,M=26;
int n;char str[N],s[N];
struct PAM{
	int ch[N][26],fail[N],len[N],sz,top[N],d[N],lst;
	mint f[N],sumf[N];
	PAM(){sz=1;fail[0]=fail[1]=1;top[0]=1;len[1]=-1;f[0]=1;}
	int getfail(int x,int i){
		while(i-len[x]-1<0||s[i-len[x]-1]!=s[i])x=fail[x];
		return x;
	}
	void ins(int i){
		int x=getfail(lst,i),w=s[i]-'a';
		if(!ch[x][w]){
			len[++sz]=len[x]+2;
			int tmp=getfail(fail[x],i);
			fail[sz]=ch[tmp][w];
			d[sz]=len[sz]-len[fail[sz]];
			if(d[sz]==d[fail[sz]])top[sz]=top[fail[sz]];
			else top[sz]=fail[sz];
			ch[x][w]=sz;
		}
		lst=ch[x][w];int j=lst;
		while(j){
			sumf[j]=f[i-len[top[j]]-d[j]];
			if(top[j]!=fail[j])sumf[j]+=sumf[fail[j]];
			if(i%2==0)f[i]+=sumf[j];
			j=top[j];
		}
	}
}P;
signed main(){
	scanf("%s",str+1);n=strlen(str+1);int l=1,r=n;
	for(int i=1;i<=n;i++)if(i&1)s[i]=str[l++];else s[i]=str[r--];
	for(int i=1;i<=n;i++)P.ins(i);
	write(P.f[n].x);
}