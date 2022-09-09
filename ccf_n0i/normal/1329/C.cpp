#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int t,n,m,i,a[1<<22];
long long ans;
vector<int> res;
bool try_del(int x,int dep){
	if(m==dep&&!a[x<<1]&&!a[(x<<1)|1]) return 0;
	if(m==dep) return 1;
	if(a[x<<1]>a[(x<<1)|1]) return try_del(x<<1,dep+1); else return try_del((x<<1)|1,dep+1);
}
void del(int x,int dep){
	if(a[x<<1]>a[(x<<1)|1]){
		a[x]=a[x<<1];
		return del(x<<1,dep);
	}
	else if(a[(x<<1)|1]){
		a[x]=a[(x<<1)|1];
		return del((x<<1)|1,dep);
	}
	else a[x]=0;
}
void solve(int x,int dep){
	while(try_del(x,dep)){
		res.push_back(x);
		del(x,dep);
	}
	if(dep!=m){
		solve(x<<1,dep+1);
		solve((x<<1)|1,dep+1);
	}
}
int main(){
	scanf("%d",&t);
	while(t--){
		ans=0;res.clear();
		scanf("%d%d",&n,&m);
		rep(i,(1<<n)-1){
			scanf("%d",&a[i]);
		}
		solve(1,1);
		rep(i,(1<<m)-1) ans+=a[i];
		printf("%I64d\n",ans);
		rep(i,(1<<n)-(1<<m)){
			printf("%d ",res[i-1]);
		}
		puts("");
		rep(i,(1<<(n+1))) a[i]=0;
	} 
	return 0;
}