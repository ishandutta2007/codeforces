// Problem: CF1598G The Sum of Good Numbers
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1598G
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define pc putchar
#define mp make_pair
#define fi first
#define se second
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=1e6+100;
int n,m;char s[N],a[N];
vector<int>mods;const int B=5;
int h[N][B],pw10[N][B],val[B];
int get(int T,int l,int r){
	int tmp=(h[r][T]-1ll*h[l-1][T]*pw10[r-l+1][T])%mods[T];
	if(tmp<0)tmp+=mods[T];return tmp;
}
vector<int>get(int l,int r){
	vector<int>res;
	for(int T=0;T<B;T++)
		res.pb(get(T,l,r));
	return res;
}
void chk(int l1,int r1,int l2,int r2){
	if(l1<1||r2>n)return;
	if(l1>r1||l2>r2)return;
	vector<int>res1=get(l1,r1),res2=get(l2,r2);
	for(int T=0;T<B;T++)
		if((res1[T]+res2[T])%mods[T]!=val[T])
			return;
	printf("%d %d\n%d %d\n",l1,r1,l2,r2);
	exit(0);
}
int z[N];
void Z(char *s,int n){
	for(int i=1;i<=n;i++)z[i]=0;
	z[1]=n;
	for(int i=2,l=0,r=0;i<=n;i++){
		if(i<=r)z[i]=min(z[i-l+1],r-i+1);
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1])++z[i];
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
}
signed main(){
	mt19937 rnd(random_device{}());
	uniform_int_distribution<int>dis(100000000/2,1000000000/2);	
	while(mods.size()<B){
		int x=dis(rnd)*2+1;
		bool flag=true;
		for(int i=2;i*i<=x;i++)
			if(x%i==0){flag=false;break;}
		if(flag)mods.pb(x);
	}
	ios::sync_with_stdio(false);
	cin.getline(s+1,998244353);n=strlen(s+1);
	cin.getline(a+1,998244353);m=strlen(a+1);
	for(int T=0;T<5;T++){
		pw10[0][T]=1;
		for(int i=1;i<=n;i++)
			pw10[i][T]=10ll*pw10[i-1][T]%mods[T];
		for(int i=1;i<=n;i++)
			h[i][T]=(h[i-1][T]*10ll+s[i]-'0')%mods[T];
		for(int i=1;i<=m;i++)
			val[T]=(10ll*val[T]+a[i]-'0')%mods[T];
	}
	a[m+1]='#';
	for(int i=1;i<=n;i++)a[m+1+i]=s[i];
	Z(a,n+m+1);
	for(int i=1;i<=n;i++){
		chk(i,i+m-2,i+m-1,i+2*m-3);
		int lcp=z[m+i+1];
		chk(i,i+m-1,i+m,i+m+(m-lcp)-1);
		chk(i,i+m-1,i+m,i+m+(m-lcp-1)-1);
		chk(i-(m-lcp),i-1,i,i+m-1);
		chk(i-(m-lcp-1),i-1,i,i+m-1);
	}
}