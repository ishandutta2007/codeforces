/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
int lowbit(int x){return x&-x;}
void read(int &x){
	x=0;char c=getchar();bool ne=false;
	while(!isdigit(c))ne|=c=='-',c=getchar();
	while(isdigit(c))x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(ne)x=-x;
}
const int N=200000;
int n,m;
int a[N+1];
int dp[N+1];
struct range{
	int l,r,id;
	range(int _l=0,int _r=0,int _id=0){l=_l,r=_r,id=_id;}
}rg[N+1];
bool cmp(range x,range y){
	if(x.l!=y.l)return x.l>y.l;
	return x.r<y.r;
}
vector<int> nums;
void discrete(){
	sort(nums.begin(),nums.end());
	nums.resize(unique(nums.begin(),nums.end())-nums.begin());
}
struct bitree{
	int mn[N+1];
	void init(){memset(mn,0x3f,sizeof(mn));}
	void chkmn(int x,int v){
		while(x<=n)mn[x]=min(mn[x],v),x+=lowbit(x);
	}
	int Mn(int x){
		int res=inf;
		while(x)res=min(res,mn[x]),x-=lowbit(x);
		return res;
	}
}bit;
bool chk(int x){
	nums.clear();
	for(int i=1;i<=n;i++)rg[i]=range(a[i]-i*x,a[i]+i*x,i),nums.pb(a[i]+i*x);
	discrete();
	sort(rg+1,rg+n+1,cmp);
	bit.init();
	for(int i=1;i<=n;i++){
		int fd=lower_bound(nums.begin(),nums.end(),rg[i].r)-nums.begin()+1;
		dp[rg[i].id]=min(rg[i].id-1,bit.Mn(fd)+rg[i].id-1);
		if(dp[rg[i].id]+n-rg[i].id<=m)return true;
		bit.chkmn(fd,dp[rg[i].id]-rg[i].id);
	}
	return false;
}
signed main(){
//	freopen("a.in","r",stdin);freopen("a.out","w",stdout); 
	read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	int ans=1e10;
	for(int i=34;~i;i--)if(ans-(1ll<<i)>=0&&chk(ans-(1ll<<i)))ans-=1ll<<i;
	cout<<ans<<"\n";
	return 0;
}