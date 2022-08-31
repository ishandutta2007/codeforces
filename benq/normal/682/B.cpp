#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

vi arr;

int main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	F0R(i,n) {
		int k;
		cin >> k;
		arr.pb(k);
	}
	sort(arr.begin(),arr.end());
	arr[0] = 1;
	F0R(i,n-1) if (arr[i+1] > arr[i]) arr[i+1] = arr[i]+1;
	cout << (arr[n-1]+1);
	return 0;
}