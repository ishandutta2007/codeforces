#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+3;
int n,m,k;
ll ans;
std::map<int,int>h;
struct point{int x,y;};
std::vector<point>a[N];
int main(){
	int c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
		scanf("%d",&c);
		if(!h[c])h[c]=++k;
		a[h[c]].push_back((point){i,j});
	}
	for(int i=1;i<=k;i++){
		std::sort(a[i].begin(),a[i].end(),[](const point&a,const point&b){return a.x<b.x;});
		for(int j=1;j<a[i].size();j++)ans+=(ll)(a[i][j].x-a[i][j-1].x)*j*(a[i].size()-j);
		std::sort(a[i].begin(),a[i].end(),[](const point&a,const point&b){return a.y<b.y;});
		for(int j=1;j<a[i].size();j++)ans+=(ll)(a[i][j].y-a[i][j-1].y)*j*(a[i].size()-j);
	}
	printf("%lld\n",ans);
	return 0;
}