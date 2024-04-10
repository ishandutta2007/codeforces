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
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0;i<n;i++) cin >> v[i];
    int sum=0, mx=0;
	for (int i=0;i<n;i++){
		sum += v[i];
		mx = max(mx, v[i]);
	}
	if (sum%2!=0){
		cout << "NO";
		return 0;
	}
	if (2*mx > sum){
		cout << "NO";
		return 0;
	}
	cout << "YES";
}