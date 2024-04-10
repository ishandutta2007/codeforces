// 

// Problem: CF802O April Fools' Problem (hard)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF802O
// Memory Limit: 250 MB
// Time Limit: 10000 ms
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
#define int long long
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
typedef long long ll;
const int N=5e5+100;
int n,m,a[N],b[N],res;
int calc(int md){
	//mdb
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>q;
	int cnt=0;res=0;
	for(int i=1;i<=n;i++){
		q.push(mp(a[i],1));
		if(b[i]-md+q.top().fi<0){
			res+=b[i]-md+q.top().fi;
			cnt+=q.top().se;
			q.pop();q.push(mp(md-b[i],0));
		}
	}
	return cnt;
}
signed main(){
	read(n,m);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=n;i++)read(b[i]);
	int l=0,r=2e9,ans=0;
	while(l<=r){
		if(calc(mid)<=m)ans=mid,l=mid+1;
		else r=mid-1;
	}
	calc(ans);
	write(res+ans*m);
}