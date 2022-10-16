#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e5+5;

int n, a[MM], ans;
vector<int> v[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	ans = n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		v[a[i]].emplace_back(i);
	}
	for(int i = 1; i <= n; i++){
		int cnt = 0;
		for(int j = 0; j < size(v[i]); j++){
			if(j) cnt -= v[i][j]-1-v[i][j-1];
			cnt = max(0, cnt);
			cnt++;
			if(cnt == 3){
				cnt--;
				ans--;
			}
		}
	}

	cout<<ans<<'\n';
}