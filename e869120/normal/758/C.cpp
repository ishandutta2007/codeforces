#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long H,W,x,y,K,p[200][200],cx,cy;
vector<pair<long long,long long>>V;
int main(){
	cin>>H>>W>>K>>x>>y;x--;y--;long long J=1;if(H>=2)J=(H-1)*2;
	for(int i=0;i<W*J;i++){
		int vx=cx,vy=cy;if(vy>=(H-1))vy=(H-1)*2-cy;
		p[vy][vx]++;V.push_back(make_pair(vy,vx));
		cx++;if(cx==W){cx=0;cy++;if(cy==J)cy=0;}
	}
	for(int i=0;i<H;i++){for(int j=0;j<W;j++){p[i][j]*=(K/V.size());}}
	for(int i=0;i<(K%(int)V.size());i++)p[V[i].first][V[i].second]++;
	long long maxn=0,minx=1LL<<62;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			maxn=max(maxn,p[i][j]);minx=min(minx,p[i][j]);
		}
	}
	cout<<maxn<<' '<<minx<<' '<<p[x][y]<<endl;
	return 0;
}