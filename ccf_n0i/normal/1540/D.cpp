#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int n,m,i,j,a[100005],blk;
vector<int> v[1005];
struct bit{
	vector<int> mem;
	int a[100005],b[100005];
	void init(){
		int i;
		rep(i,n)b[i]=1;
		rep(i,n)if(i+(i&-i)<=n) b[i+(i&-i)]+=b[i];
		memcpy(a,b,sizeof(a));
	}
	void clear(){
		dzd(mem,itr){
			for(int i=*itr;i<=n;i+=(i&-i)) a[i]=b[i];
		}
		mem.clear();
	}
	void add(int x,int y){
		mem.push_back(x);
		while(x<=n){
			a[x]+=y;
			x+=(x&-x);
		}
	}
	int query(int x){
		int s=0,i;
		for(i=16;i>=0;i--){
			if(s+(1<<i)>n) continue;
			if(a[s+(1<<i)]<x){
				x-=a[s+=(1<<i)];
			}
		}
		return s+1;
	}
}t;
void rebuild(int x){
	t.clear();v[x].clear();
	int i,l=max(1,x*blk),r=min(n,x*blk+blk-1);
	for(i=l;i<=r;i++){
		int p=t.query(i-a[i]);
		v[x].push_back(p);
		t.add(p,1);
	}
	sort(v[x].begin(),v[x].end());
}
int main(){
	scanf("%d",&n);blk=150;;
	t.init();
	rep(i,n)scanf("%d",&a[i]);
	for(i=1/blk;i<=n/blk;i++){
		rebuild(i);
	}
	scanf("%d",&m);
	while(m--){
		int op,x;
		scanf("%d%d",&op,&x); 
		if(op==1){
			scanf("%d",&a[x]);rebuild(x/blk);
		}
		else{
			int ans=x-a[x];
			while(x<=n&&x/blk==(x+1)/blk){
				x++;
				if(ans>=x-a[x]) ans++;
			}
			x++;
			while(x<=n){
				ans+=upper_bound(v[x/blk].begin(),v[x/blk].end(),ans)-v[x/blk].begin();
				x+=blk;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}