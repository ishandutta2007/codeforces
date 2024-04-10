#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define R register int
vector<int>C[317];
int main(){
	int n,m;
	cin>>n>>m;
	for(R i=0;i!=n;i++){
		C[i].resize(m);
		for(R j=0;j!=m;j++){
			scanf("%d",&C[i][j]);
		}
	}
	map<int,pair<int,long long>>Q;
	long long ans=0;
	for(R i=0;i!=n;i++){
		for(R j=0;j!=m;j++){
			int x=C[i][j];
			ans+=(long long)i*Q[x].first-Q[x].second;
			Q[x].first++;
			Q[x].second+=i;
		}
	}
	Q.clear();
	for(R i=0;i!=m;i++){
		for(R j=0;j!=n;j++){
			int x=C[j][i];
			ans+=(long long)i*Q[x].first-Q[x].second;
			Q[x].first++;
			Q[x].second+=i;
		}
	}
	cout<<ans;
	return 0;
}