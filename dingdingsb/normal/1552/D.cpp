#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=11;
int t,n,a[N];
bool dfs(int now,int sum,int cnt){
	if(now==n)return sum==0&&cnt;
	return dfs(now+1,sum,cnt)||dfs(now+1,sum-a[now+1],cnt+1)||dfs(now+1,sum+a[now+1],cnt+1);
}
signed main(){
	read(t);
	while(t--){
		read(n);
		for(int i=1;i<=n;i++)read(i[a]);
		puts(dfs(0,0,0)?"YES":"NO");
	}
}