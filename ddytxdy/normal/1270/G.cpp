#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e6+50;
int n,d[N],st[N],tp,p[N],T;
vector<int>ans;
void solve(){
	scanf("%d",&n);tp=0;
	for(int i=1;i<=n;i++)d[i]=0;
	for(int i=1,x;i<=n;i++)
		scanf("%d",&x),p[i]=i-x,d[i-x]++;
	for(int i=1;i<=n;i++)if(!d[i])st[++tp]=i;
	ans.clear();
	while(tp){
		int x=st[tp--];
		if(!--d[p[x]])st[++tp]=p[x];
	}
	for(int i=1;i<=n;i++)if(d[i]){
		for(int x=p[i];x!=i;x=p[x])ans.pb(x),assert(ans.size()<N);
		ans.pb(i);printf("%d\n",ans.size());
		for(int j=0;j<ans.size();j++)printf("%d ",ans[j]);
		break;
	}
	puts("");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}