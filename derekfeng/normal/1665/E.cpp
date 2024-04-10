#include<bits/stdc++.h>
using namespace std;
int dt[10000005],s[2][10000005],cnt=1;
int n,q,rt[100005];
int built(int id,int d,int x){
	int i=++cnt;
	dt[i]=dt[id]+1,s[0][i]=s[0][id],s[1][i]=s[1][id];
	if(d>-1){
		int t=(x>>d)&1;
		s[t][i]=built(s[t][id],d-1,x);
	}
	return i;
}
vector<int>V;
int ans;
void qry(int i1,int i2,int x,int d){
	if(dt[i2]-dt[i1]==0||V.size()>31)return;
	if(d<0){
		if(dt[i2]-dt[i1]>1)ans=min(ans,x);
		V.push_back(x);
	}else{
		qry(s[0][i1],s[0][i2],x,d-1);
		qry(s[1][i1],s[1][i2],x|(1<<d),d-1);
	}
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		rt[i]=built(rt[i-1],29,x);
	}
	scanf("%d",&q);
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		ans=2e9,V.clear();
		qry(rt[l-1],rt[r],0,29);
		for(auto x:V)for(auto y:V)if(x!=y)ans=min(ans,x|y);
		printf("%d\n",ans);
	}
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}