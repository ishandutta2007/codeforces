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

int na, ma, nb, mb;
pair<int,pii> bes = {-MOD,{0,0}};
char A[50][50], B[50][50];

int test(int x, int y) {
    int tmp = 0;
    F0R(i,na) if (0 <= i+x && i+x < nb) 
        F0R(j,ma) if (0 <= j+y && j+y < mb) {
            tmp += (A[i][j]-'0')*(B[i+x][j+y]-'0');
        } 
    return tmp;
}

int main() {
    cin >> na >> ma;
    F0R(i,na) F0R(j,ma) cin >> A[i][j];
    cin >> nb >> mb;
    F0R(i,nb) F0R(j,mb) cin >> B[i][j];
    FOR(i,-50,51) FOR(j,-50,51) bes = max(bes,{test(i,j),{i,j}});
    
    cout << bes.s.f << " " << bes.s.s;
}