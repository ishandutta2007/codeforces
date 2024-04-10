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
	int a[200005], n,m, ori[200005];
   // cin >> n >> m;
    scanf("%d%d",&n,&m);
    F0R(i,n) scanf("%d",&ori[i]);

    for (int i = n-2; i >= 0; --i) {
    	if (ori[i] == ori[i+1]) a[i] = a[i+1];
    	else a[i] = i+1;
    }
    
    F0R(i,m) {
        int l,r,x;
        scanf("%d%d%d",&l,&r, &x);
        if (ori[l-1] != x) cout << l << endl;
        else {
	        if (a[l-1] != 0 && (a[l-1]+1) <= r) printf("%d\n", (a[l-1]+1));
        	else printf("%d\n", -1);
        }
    }
	return 0;
}