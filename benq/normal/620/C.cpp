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
 
const int MOD = 1000000007;
const int MAX = 10000005;

int n, numsegs = 0, last = 0, pearls[300000];
set<int> temp;
vi solutions;

int main() {
	cin >> n;
	// n = 300000;
	F0R(i,n) {
		cin >> pearls[i];
		// pearls[i] = i+1;
		if (temp.find(pearls[i]) != temp.end()) {
			temp.clear();
			solutions.pb(last+1);
			solutions.pb(i+1);
			last = i+1;
			numsegs++;
		} else temp.insert(pearls[i]);
	}
	if (numsegs == 0) cout << -1;
	else {
		cout << numsegs << endl;
		F0R(i,solutions.size()/2-1) {
			cout << solutions[2*i] << " " << solutions[2*i+1] << endl;
		}
		cout << solutions[solutions.size()-2] << " " << n;
	}
	
	return 0;
}