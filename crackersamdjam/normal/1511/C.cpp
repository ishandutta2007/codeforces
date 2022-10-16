#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 3e5+5;

int n, q, lo[55];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>q;
	vector<pair<int, int>> v = {{0, 0}};
	for(int i = 1,a; i <= n; i++){
		cin>>a;
		if(!lo[a]){
			lo[a] = i;
			v.emplace_back(a, i);
		}
	}
	while(q--){
		int a; cin>>a;
		for(int i = 0; i < size(v); i++){
			if(v[i].first == a){
				cout<<v[i].second<<' ';
				for(int j = 0; j < i; j++)
					v[j].second++;
				v.erase(v.begin()+i);
				v.insert(v.begin()+1, {a, 1});
			}
		}
	}
}