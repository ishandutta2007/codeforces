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

int main() {
	int n; scanf("%d",&n);
    bool val = 0;
    F0R(i,n) F0R(j,n) {
        int x; scanf("%d",&x);
        if (i == j && x == 1) val = !val;
    }
    int q; scanf("%d",&q);
    F0R(i,q) {
        int a = 1; scanf("%d",&a);
        if (a == 1 || a == 2) {
            val = !val;
            int z; scanf("%d",&z);
        } else printf("%d",val);
    }
    return 0;
}