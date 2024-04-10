#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>F[250000],G[250000];int n,m,a,b,c;
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		F[b-a+1].push_back(make_pair(a,c));
	}
	for(int i=0;i<250000;i++){
		sort(F[i].begin(),F[i].end());G[i]=F[i];
		for(int j=(int)F[i].size()-2;j>=0;j--){
			F[i][j].second=min(F[i][j].second,F[i][j+1].second);
		}
	}
	int minx=2100000000;
	for(int i=1;i<m;i++){
		for(int j=0;j<F[i].size();j++){
			int O=m-i;
			int pos1=lower_bound(F[O].begin(),F[O].end(),make_pair(F[i][j].first+i,-2100000000))-F[O].begin();
			if(pos1==F[O].size())continue;
			//cout<<i<<' '<<F[i][j].second<<' '<<F[O][pos1].second<<' '<<O<<' '<<pos1<<' '<<F[O][pos1].first<<' '<<F[i][j].first<<endl;
			minx=min(minx,G[i][j].second+F[O][pos1].second);
		}
	}
	if(minx==2100000000)minx=-1;
	cout<<minx<<endl;
	return 0;
}