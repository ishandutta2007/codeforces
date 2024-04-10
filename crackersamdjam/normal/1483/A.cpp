#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e5+5;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, n, m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<int> cnt(n+1), out(m);
		vector<int> v[m];

		for(int i = 0,k; i < m; i++){
			cin>>k;
			v[i].resize(k);
			for(int &a: v[i])
				cin>>a;
			cnt[v[i][0]]++;
			out[i] = v[i][0];
		}
		int h = (m+1)/2, id = 0;
		for(int i = 1; i <= n; i++){
			if(cnt[i] > h){
				id = i;
				// now swap out whenever possible
				break;
			}
		}

		for(int j = 0; j < m; j++){
			if(v[j][0] == id and size(v[j]) > 1){
				out[j] = v[j][1];
				cnt[id]--;
			}
			if(cnt[id] <= h)
				break;
		}

		if(cnt[id] > h){
			cout<<"NO\n";
			goto done;
		}

		cout<<"YES\n";
		for(int i = 0; i < m; i++){
			cout<<out[i]<<' ';
		}
		cout<<'\n';
		done:;
	}
}