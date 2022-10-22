#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=5005;
const int inf=0x3f3f3f3f;
const int mod=998244353;
template<typename T>inline void read(T &x) {
    int f=1;x=0;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
    x*=f;return;
}
template<typename T,typename...Args>
	inline void read(T &x,Args &...args){
	read(x);read(args...);
}
int n,m;
ll a[N]; 
ll dp1[N],dp0[N];
struct node{
	ll k;int id;
};
struct school{
	ll x;int c;
	bool operator <(const school &b)const
	{
		return x<b.x;
	}
};
school s[N];
node q[N];
int head,tail;
ll dis(ll x,ll y){
	if(x>y) return x-y;
	else return y-x;
}
ll pre[N];
int main()
{
	int i,j;
	read(n,m);
	for(i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
	for(i=1;i<=m;i++) read(s[i].x,s[i].c);
	sort(s+1,s+m+1);
	ll sum=0;
	for(i=1;i<=m;i++) sum+=s[i].c;
	if(n>sum){
		cout<<-1;
		return 0;
	}
	memset(dp0,0x3f,sizeof(dp0));
	memset(dp1,0x3f,sizeof(dp1));
	dp0[0]=dp1[0]=0;
	for(i=1;i<=s[1].c;i++){
		dp0[i]=dp0[i-1]+dis(s[1].x,a[i]);
		dp1[i]=dp0[i];
	}
	#ifdef TIME
		clock_t ST=clock();
	#endif
	for(i=2;i<=m;i++){
		for(j=0;j<=n;j++) dp0[j]=dp1[j];
		head=tail=0;
		for(j=1;j<=n;j++) pre[j]=pre[j-1]+dis(a[j],s[i].x);
		for(j=1;j<=n;j++){
			while(head<tail&&q[head].id<j-s[i].c) head++;
			node tmp;tmp.id=j-1;tmp.k=dp0[j-1]-pre[j-1];
			while(head<tail&&q[tail-1].k>tmp.k) tail--;
			q[tail++]=tmp;
			dp1[j]=min(dp1[j],q[head].k+pre[j]);
		}
	}
	#ifdef TIME
		printf("\n%.2lf ms",double(clock()-ST)/CLOCKS_PER_SEC*1000.0);
	#endif
	cout<<dp1[n];
	return 0;
}