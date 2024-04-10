#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define maxn 1000000
#define int long long
using namespace std;
int n,k,m,l,r,c,p,ans;
vector <int>cnt[1000005],val[1000005];
struct BIT{
	int tree[1000005];
	BIT(){
		memset(tree,0,sizeof(tree));
		return;
	}
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int pos,int val){
		while(pos<=maxn)tree[pos]+=val,pos+=lowbit(pos);
		return;
	}
	inline int ask(int pos){
		int ans=0;
		while(pos)ans+=tree[pos],pos-=lowbit(pos);
		return ans;
	}
}bit1,bit2;
signed main(){
	cin>>n>>k>>m;
	for (int i=1;i<=m;i++){
		scanf("%lld%lld%lld%lld",&l,&r,&c,&p);
		cnt[l].push_back(c),val[l].push_back(p);
		cnt[r+1].push_back(-c),val[r+1].push_back(p);
	}
	for (int i=1;i<=n;i++){
		for (int j=0,len=cnt[i].size();j<len;j++){
			bit1.add(val[i][j],cnt[i][j]);
			bit2.add(val[i][j],val[i][j]*cnt[i][j]);
		}
		int l=1,r=maxn,now=maxn;
		while(l<=r){
			int mid=(l+r)/2;
			if (bit1.ask(mid)>=k)now=mid,r=mid-1;
			else l=mid+1; 
		}
		if (bit1.ask(now)>k)ans+=bit2.ask(now)-(bit1.ask(now)-k)*now;
		else ans+=bit2.ask(now);
	}
	cout<<ans<<endl;
	return 0;
}