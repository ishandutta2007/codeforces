#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5005;
struct Key{
	pair<int,int> s[20];
	int sta;
}g[1<<15|5];
pair<int,int> ans[20];
int f[1<<15|5],pre[1<<15|5],t[1<<15|5];
vector<ll> a[20];
ll s[20];
unordered_map<ll,pair<int,int> > mp;
ll sum=0;
int n;
inline bool gbit(int sta,int i){ return sta&(1<<i-1); }
inline int ubit(int i){ return 1<<i-1; }
void solve(int x,int p){
	pair<int,int> e(x,p);
	int key=a[x][p],last=0;
	Key ret; ret.sta=0;
	while(1){
//		printf("|%d %d|",x,key);
		ret.sta|=ubit(x); 
		ret.s[x]=make_pair(key,last);
		pair<int,int> pos=mp[sum-s[x]+key];
		if(pos.first==0) return;
		if(pos.first==e.first){
			if(pos.second==e.second){
				ret.s[e.first].second=x;
				break;
			}else return;
		}
		if(gbit(ret.sta,pos.first)) return;
		key=a[pos.first][pos.second];
		last=x; x=pos.first;
	}
//	printf("<%d %d %d>",x,p,ret.sta);
	g[ret.sta]=ret;
	t[ret.sta]=1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int top; scanf("%d",&top);
		a[i].resize(top);
		for(int j=0;j<top;++j){
			scanf("%lld",&a[i][j]);
			mp[a[i][j]]=make_pair(i,j);
			sum+=a[i][j];
			s[i]+=a[i][j];
		}
	}
	if(sum%n!=0){
		puts("No");
		return 0;
	}
	sum/=n;
	for(int i=1;i<=n;++i)
		for(int j=0;j<a[i].size();++j)
			solve(i,j);
	f[0]=1;
	for(int sta=1;sta<1<<n;++sta){
		for(int sta1=sta;sta1>0;sta1=(sta1-1)&sta)
			if(f[sta-sta1]&&t[sta1]){
				pre[sta]=sta1;
				f[sta]=1;
				break;
			}
	}
	int sta=(1<<n)-1;
	if(!f[sta]){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(;sta!=0;sta=sta-pre[sta]){
		int sta1=pre[sta];
		for(int i=1;i<=n;++i)
			if(gbit(sta1,i))
				ans[i]=g[sta1].s[i];
	}
	for(int i=1;i<=n;++i) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}