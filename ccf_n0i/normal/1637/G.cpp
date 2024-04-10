#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define rep0(i,n) for ((i)=0;(i)<(n);(i)++)
using namespace std;
int c[65537],lim;
vector<pair<int,int> > ans;
void op(int x,int y){
	assert(0<=x&&x<=lim);
	assert(0<=y&&y<=lim);
	assert(0<=x+y&&x+y<=lim);
	c[x]--;c[y]--;
	assert(c[x]>=0);
	assert(c[y]>=0);
	c[x+y]++;c[abs(x-y)]++;
	ans.push_back(make_pair(x,y));
}
void solve(){
	ans.clear();
	int n,i,j,k;
	scanf("%d",&n);
	if(n==2){
		puts("-1");
		return;
	}
	lim=n;
	while(lim&(lim-1)) lim++;
	memset(c,0,sizeof(c));
	rep(i,n) c[i]=1;
	for(i=1;i<(lim>>1);i<<=1){
		for(j=(lim>>1);j>=1;j>>=1){
			for(k=(j<<1)-i;k>j;k-=(i<<1)){
				while(c[k]&&c[(j<<1)-k]) op(k,(j<<1)-k);
			}
		}
	}
	for(i=1;i<lim;i<<=1){
		while(c[i]>=2) op(i,i);
	}
	for(i=1;i<lim;i<<=1){
		while(c[i]>=2) op(i,i);
		if(c[i]) op(i,0); 
		while(c[i]>=2) op(i,i); 
	}
	while(c[0]) op(lim,0);
	assert(c[lim]==n);
	printf("%d\n",ans.size());
	rep0(i,ans.size()){
		printf("%d %d\n",ans[i].first,ans[i].second);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}