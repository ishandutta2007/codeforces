#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;

string s;
int q, rkey[26], sz[11];
char key[4] = {'A','T','G','C'};

int seg[11][10][1<<18][4];

int qsum(int l, int r, int mod, int pos, int cha) {  // sum on interval [l, r)
  int res = 0;
  for (l += sz[mod], r += sz[mod]; l < r; l >>= 1, r >>= 1) {
    if (l&1) {
        res += seg[mod][pos][l++][cha];
        l ++;
    }
    if (r&1) {
        r--;
        res += seg[mod][pos][r][cha];
    }
  }
  return res;
} // correct

void init() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s >> q; 
    
    rkey['A'-'A'] = 0, rkey['T'-'A'] = 1, rkey['G'-'A'] = 2, rkey['C'-'A'] = 3;
    
    FOR(i,1,11) sz[i] = (s.length()+i-1)/i;
    
    F0R(i,s.length()) 
        FOR(j,1,11) 
            seg[j][i % j][i/j+sz[j]][rkey[s[i]-'A']] ++;
    
    FOR(i,1,11) 
        F0R(j,i)  
            for (int x = sz[i]-1; x > 0; --x) 
                F0R(y,4)
                    seg[i][j][x][y] = seg[i][j][2*x][y]+seg[i][j][2*x+1][y];
} // correct

void upd(int x, int c) {
    FOR(i,1,11) {
        int p = x/i+sz[i];
        int p1 = p;
        
        int c1 = rkey[s[x]-'A'];
        
        for (seg[i][x%i][p][c1] = 0; p > 1; p >>= 1) seg[i][x%i][p>>1][c1] = seg[i][x%i][p][c1]+seg[i][x%i][p^1][c1];
        
        p = p1;
        for (seg[i][x%i][p][c] = 1; p > 1; p >>= 1) seg[i][x%i][p>>1][c] = seg[i][x%i][p][c]+seg[i][x%i][p^1][c];
    }
        s[x] = key[c];
} // correct

int main() {
    init();

    F0R(i,q) {
        int t; cin >> t;
        if (t == 1) {
            int x; char c; cin >> x >> c;
            upd(x-1,rkey[c-'A']);
        } else {
            int l, r; cin >> l >> r; l--, r--;
            string e; cin >> e;
            
            int ret = 0, el = e.length();
            
            F0R(i,min(r-l+1,el)) {
                int i1 = (i+l) % el;
                int l1 = (l-i1+el-1)/el; // change
                int r1 = (r-i1)/el+1;
                
                ret += qsum(l1,r1,e.length(),i1,rkey[e[i]-'A']); // modify
            }
            
            cout << ret << "\n";
        }
    }
}

// read!
// ll vs. int!