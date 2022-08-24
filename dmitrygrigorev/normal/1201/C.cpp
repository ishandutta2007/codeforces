#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
#define mp make_pair
#define db double
#define pb push_back
#define all(a) a.begin(), a.end()
main(){
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
	int L = 0, R = 2e9+17;
	while (R-L>1){
		int M = (L+R)/2;
		int need=0;
		for (int i=0; i < (n+1)/2; i++){
			if (v[n-i-1] < M) need += M-v[n-i-1];
		}
		if (need <= k) L = M;
		else R = M;
	}
	cout << L;
}