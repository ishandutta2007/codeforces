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

ll L,R,ans=0;
vi L1(19), R1(19);
int oc[10], oc1[10], tmp[10];

bool test1(int ind) {
    F0R(i,10) tmp[i] = oc1[i];
    
    int c = 9;
    FOR(i,ind,19) {
        while (tmp[c] == 0) c--;
        tmp[c] --;
        if (c != L1[i]) return (c > L1[i]);
    }
    
    return 1;
}

bool test2(int ind) {
    F0R(i,10) tmp[i] = oc1[i];
    
    int c = 0;
    FOR(i,ind,19) {
        while (tmp[c] == 0) c++;
        tmp[c] --;
        if (c != R1[i]) return (c < R1[i]);
    }
    
    return 1;
}

bool ok() {
    F0R(i,10) oc1[i] = oc[i];
    F0R(i,19) {
        int l = L1[i], r = R1[i];
        if (l == r) {
            if (!oc1[l]) return 0;
            oc1[l] --;
        } else {
            FOR(j,l+1,r) if (oc1[j]) return 1;
            if (oc1[l]) {
                oc1[l] --;
                if (test1(i+1)) return 1;
                oc1[l] ++;
            }
            if (oc1[r]) {
                oc1[r] --;
                if (test2(i+1)) return 1;
                oc1[r] ++;
            }
            return 0;
        }
    }
    return 1;
}

void solve(int num, int cur) {
    oc[0] = 19-num;
    if (ok()) {
        ans++;
    }
    if (num == 19) return;
    FOR(i,cur,10) {
        oc[i] ++;
        solve(num+1,i);
        oc[i] --;
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> L >> R;
	string L2 = to_string(L), R2 = to_string(R);
	while (L2.length()<19) L2 = ('0'+L2);
	while (R2.length()<19) R2 = ('0'+R2);
	
	F0R(i,19) L1[i] = L2[i]-'0', R1[i] = R2[i]-'0';
	
	solve(0,1);
	cout << ans;
}