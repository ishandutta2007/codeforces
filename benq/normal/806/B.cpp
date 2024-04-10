/*#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>*/
#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

int n, par[120][5], val[5], num[5];

int get(int a, int b) {
    if (2*a>b) return 1;
    if (4*a>b) return 2;
    if (8*a>b) return 3;
    if (16*a>b) return 4;
    if (32*a>b) return 5;
    return 6;
}

bool work (int k) {
    int s1 = 0, s2 = 0;
    F0R(i,5) {
        if (par[0][i] == -1) {
            if (par[1][i] != -1) 
                s2 += get(num[i],k+n)*(250-par[1][i]);
        } else {
            if (par[1][i] != -1) {
                if (par[0][i] <= par[1][i]) {
                    s1 += get(num[i],k+n)*(250-par[0][i]);
                    s2 += get(num[i],k+n)*(250-par[1][i]);
                } else {
                    s1 += get(num[i]+k,k+n)*(250-par[0][i]);
                    s2 += get(num[i]+k,k+n)*(250-par[1][i]);
                }
            } else s1 += get(num[i],k+n)*(250-par[0][i]);
        }
    }
    if (s1>s2) return 1;
    return 0;
}

int main() {
	cin >> n;
	F0R(i,n) F0R(j,5) {
	    cin >> par[i][j]; 
	    if (par[i][j] != -1) num[j] ++;
	}
	F0R(i,10000) if (work(i)) {
	    cout << i;
	    return 0;
	}
	cout << -1;
}