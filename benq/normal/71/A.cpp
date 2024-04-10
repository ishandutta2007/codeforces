#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int main() {
	int n;
    cin >> n;
    F0R(i,n) {
        string x;
        cin >> x;
        if (x.length()<=10) cout << x << endl;
        else cout << x[0] << int(x.length()-2) << x[x.length()-1] << endl;
    }
	return 0;
}