#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int a,b,n, ans[100][100];

int main() {
	cin >> n >> a >> b;
	if (n > a*b) {
        cout << -1;
        return 0;
    }
    int c1=0, c2=1;
    ans[0][0] = 1;
    F0R(j,a) F0R(i,b) {
        if (ans[i][j] == 0) {
            if (i == 0) {
                if (ans[i][j-1] % 2 == 0) {
                    c2 += 2;
                    ans[i][j] = c2;
                } else {
                    c1 += 2;
                    ans[i][j] = c1;
                }
            } else {
                if (ans[i-1][j] % 2 == 0) {
                     c2 += 2;
                     ans[i][j] = c2;
                } else {
                     c1 += 2;
                     ans[i][j] = c1;
                }
            }
        }
    }
    F0R(j,a) {
    	F0R(i,b) {
    		if (ans[i][j] <= n) cout << ans[i][j];
    		else cout << 0;
    		cout << " ";
    	}
    	cout << endl;
    }
	return 0;
}