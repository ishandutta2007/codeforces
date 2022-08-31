#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"
 
const int MOD = 1000000007;
double PI = 4*atan(1);

int arr[21][21],n,m;

bool test(vi a) {
    F0R(i,n) {
        int e = 0;
        F0R(j,m) if (arr[i][j] != a[j]) e++;
        if (e>2) return 0;
    }
    return 1;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	F0R(i,n) F0R(j,m) cin >> arr[i][j];
	
	vi a;
	FOR(i,1,m+1) a.pb(i);
	if (test(a)) {
	    cout << "YES";
	    return 0;
	}
	
	F0R(i,m) FOR(j,i+1,m) {
	    swap(a[i],a[j]);
	    /*for (int x: a) cout << x << " ";
	    cout << "\n";*/
	    if(test(a)) {
	        cout << "YES";
	        return 0;
	    }
	    swap(a[i],a[j]);
	}
	cout << "NO";
}