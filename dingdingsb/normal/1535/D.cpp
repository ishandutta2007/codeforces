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
const int N=1e6+100;
int n,k,q,ans[N];
char s[N];
void pushup(int x){
	if(s[x]=='0')ans[x]=ans[rc];
	if(s[x]=='1')ans[x]=ans[lc];
	if(s[x]=='?')ans[x]=ans[lc]+ans[rc];
}
void build(int x,int l,int r){
	if(l==r)return ans[x]=1,void();
	build(lc,l,mid);build(rc,mid+1,r);
	pushup(x);
}
signed main(){
	read(k);n=1<<k;
	scanf("%s",s+1);reverse(s+1,s+n);
	build(1,1,n);
	read(q);while(q--){
		int x;read(x);x=n-x;
		char c=getchar();while(c!='1'&&c!='0'&&c!='?')c=getchar();
		s[x]=c;while(x)pushup(x),x>>=1;
		write(ans[1]);putchar('\n');
	}
}