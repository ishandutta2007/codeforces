#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

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

char grid[10][10], grid1[10][10];

bool diag(int i, int j) {
    int cx = 0, co = 0;
    F0R(i1,5) if (grid[i+i1][j+i1] == 'X') cx ++;
    else if (grid[i+i1][j+i1] == 'O') co ++;
    if (cx == 4 && co == 0) return 1;
    return 0;
}

bool row(int i, int j) {
    int cx = 0, co = 0;
    FOR(j1,j,j+5) if (grid[i][j1] == 'X') cx ++;
    else if (grid[i][j1] == 'O') co++;
    if (cx == 4 && co == 0) return 1;
    return 0;
}

int main() {
	F0R(i,10) F0R(j,10) cin >> grid[i][j];
	F0R(i,10) F0R(j,6) if (row(i,j)) {
	    cout << "YES";
	    return 0;
	}
	F0R(i,10) F0R(j,i) swap(grid[i][j],grid[j][i]);
	F0R(i,10) F0R(j,6) if (row(i,j)) {
	    cout << "YES";
	    return 0;
	}
	F0R(i,6) F0R(j,6) if (diag(i,j)) {
	    cout << "YES";
	    return 0;
	}
	F0R(i,10) F0R(j,5) swap(grid[i][j],grid[i][9-j]);
	
	/*F0R(i,10) {
	    F0R(j,10) cout << grid[i][j];
	    cout << "\n";
	}*/
	F0R(i,6) F0R(j,6) if (diag(i,j)) {
	    cout << "YES";
	    return 0;
	}
	cout << "NO";
}