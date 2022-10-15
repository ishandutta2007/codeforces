#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

struct X { int P, T, G; };

int S,B;
int A[(int)1e5+5];
ii C[(int)1e5+5];

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> S >> B;
    FOR(i,0,S-1){
        cin >> A[i];
    }
    FOR(i,0,B-1){
        cin >> C[i].fi >> C[i].sc;
    }

    sort(C,C+B);
    FOR(i,1,B-1){
        C[i].sc += C[i-1].sc;
    }

    FOR(i,0,S-1){
        int it = upper_bound(C,C+B,ii(A[i],(int)2e9))-C;
        cout << (it == 0 ? 0 : C[it-1].sc) << ' ';
    }
}