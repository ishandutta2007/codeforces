using namespace std;
#include <bits/stdc++.h>
const int N = 30001;
unordered_map<int, int> v[N];
vector<int> p;
int main() {
	int n, d;
	cin >> n >> d;
	vector<int> a(n);
	p.resize(N, 0);
	for (int i=0; i < n; i++) cin >> a[i];
	for (int i=0; i < n; i++) p[a[i]]++;
	v[d][d] = p[d];
	int ans = p[d];
	for (int i=0; i < N; i++){
	    for (auto it = v[i].begin(); it != v[i].end(); it++){
	       // cout << i << endl;
	        pair<int, int> e = *it;
	        for (int j=max(i+1, i+e.first-1); j <= i+e.first+1; j++){
	            if (j < N) {
	                //if (!v[j].count(j-i)) v[j][j-i] = 0;
	                v[j][j-i] = max(v[j][j-i], e.second + p[j]);
	                ans = max(ans, e.second+p[j]);
	            }
	        }
	    }
	}
	//cout << v[21][1] << endl;
	cout << ans;
	
}