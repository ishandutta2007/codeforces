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

bool x[1000001];

int main() {
    int n,p=0; scanf("%d",&n);

    // pair up the numbers?
    F0R(i,n) {
        int x1; scanf("%d",&x1);
        x[x1] = 1;
    }

    vi q,ans;
    FOR(i,1,500001) {
        int z = int(x[i])+int(x[1000001-i]);
        if (z == 2) p++;
        else if (z == 1) {
            if (x[i]) ans.pb(1000001-i);
            else ans.pb(i);
        } else q.pb(i);
    }
    F0R(i,p) {
        ans.pb(q[i]);
        ans.pb(1000001-q[i]);
    }
    printf("%d\n",ans.size());
    F0R(i,ans.size()) printf("%d ", ans[i]);
	return 0;
}