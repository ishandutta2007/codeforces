#include<bits/stdc++.h>
#define pb push_back
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
const int N=2e5+100,B=30;
int n;
int ch[N*B][2];
int tot=0;
void ins(int x){
	int now=0;
	for(int i=B;~i;i--){
		if(!ch[now][x>>i&1])ch[now][x>>i&1]=++tot;
		now=ch[now][x>>i&1];
	}
}
int dp(int x){
	if(!ch[x][0]&&!ch[x][1])return 1;
	if(!ch[x][0])return dp(ch[x][1]);
	if(!ch[x][1])return dp(ch[x][0]);
	return max(dp(ch[x][0]),dp(ch[x][1]))+1;
}
signed main(){
	read(n);
	for(int i=1,x;i<=n;i++)
		read(x),ins(x);
	write(n-dp(0));
}