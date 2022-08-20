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
#define b begin
#define e end
#define lb lower_bound
#define ub upper_bound
#define sz size
 
const int MOD = 1000000007;

int is (int a, int b) {
      unsigned int x;
      while (b) {
          x = a % b;
          a = b;
          b = x;
        }
      if (a>1) return 1;
      else return 0;
    }

int main() {
	int n, c=0;
	cin >> n;
	vi ori, arr;
	F0R(i,n) {
		int x;
		cin >> x;
		ori.pb(x);
	}
	
	F0R(i,n) {
		arr.pb(ori[i]);
		if (i != n-1 && is(max(ori[i],ori[i+1]),min(ori[i],ori[i+1]))) {
			arr.pb(1);
			c++;
		}
	}
	cout << c << endl;
	F0R(i,arr.size()) cout << arr[i] << " ";
	return 0;
}