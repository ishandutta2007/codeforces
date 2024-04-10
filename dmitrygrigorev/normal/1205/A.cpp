#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9;
vector<int> used;
vector<vector<int> > data;
signed main() {
	#ifdef LOCAL
		freopen("H_input.txt", "r", stdin);
		//freopen("C_output.txt", "w", stdout);
	#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
   	int n;
   	cin >> n;
   	if (n%2==0){
   		cout << "NO\n";
   		return 0;
   	}
   	cout << "YES\n";
   	vector<int> a, b;
   	for (int i=0; i < n; i++){
   		if (i % 2 == 0){
   			a.push_back(2*i);
   			b.push_back(2*i+1);
   		}
   		else{
   			b.push_back(2*i);
   			a.push_back(2*i+1);
   		}
   	}
   	for (int i=0; i < n; i++) cout << a[i]+1 << " ";
   		for (int i=0; i < n; i++) cout << b[i]+1 << " ";
}