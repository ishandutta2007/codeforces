#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define dzd(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
int t,n,i;
int fa[100005],a[100005];
int fnd(int x){
	if(fa[x]==x) return x;
	return fa[x]=fnd(fa[x]);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,n) scanf("%d",&a[i]);
		queue<int> qx;
		vector<int> ans;
		rep(i,n)fa[i]=i;
		fa[n+1]=1;
		rep(i,n) qx.push(i);
		while(!qx.empty()){
			int x=qx.front();qx.pop();
			if(fnd(x)!=x) continue;
			int y=fnd(x+1);
			if(__gcd(a[x],a[y])==1){
				fa[y]=fnd(y+1);
				ans.push_back(y);
				if(x==y) break;
				qx.push(x);
			}
		}
		printf("%d",ans.size());
		dzd(ans,it) printf(" %d",*it);
		puts("");
	}
	return 0;
}