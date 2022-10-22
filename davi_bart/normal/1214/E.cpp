#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int sol[2000009];
vector<int> v[2000009];
vector<pair<int,int> > d;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		for(int i=1;i<=N;i++){
			int a;
			cin>>a;
			d.push_back({a,2*i-1});
		}
		sort(d.begin(),d.end());
		reverse(d.begin(),d.end());
		for(int i=0;i<d.size();i++){
			sol[i]=d[i].second;
		}
		for(int i=0;i<d.size();i++){
			int dist=d[i].first;
			if(sol[i+dist]==0)sol[i+dist]=sol[i]+1;
			else{
				v[i+dist-1].push_back(sol[i]+1);
			}
		}
		for(int i=1;;i++){
			if(sol[i]==0)break;
			cout<<sol[i]<<" "<<sol[i-1]<<endl;
		}
		for(int i=0;i<2000000;i++){
			for(int j=0;j<v[i].size();j++){
				cout<<sol[i]<<" "<<v[i][j]<<endl;
			}
		}
		return 0;
}