#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef map<int,int> mii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = b-1; i >= a; i--)
#define F0Rd(i,a) for (int i = a-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;
double PI = 4*atan(1);

char arr[3][3];
int cX=0,c0=0;

bool win(char c) {
	F0R(i,3) if (arr[i][0] == c && arr[i][1] == c && arr[i][2] == c) return 1;
	F0R(i,3) if (arr[0][i] == c && arr[1][i] == c && arr[2][i] == c) return 1;
	if (arr[0][0] == c && arr[1][1] == c && arr[2][2] == c) return 1;
	if (arr[0][2] == c && arr[1][1] == c && arr[2][0] == c) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	F0R(i,3) F0R(j,3) cin >> arr[i][j];
	F0R(i,3) F0R(j,3) {
		if (arr[i][j] == 'X') cX++;
		else if (arr[i][j] == '0') c0++;
	}
	if ((cX-c0)>1 || cX<c0 || (win('X') && win('0'))) cout << "illegal";
	else if (win('X') && cX == c0) cout << "illegal";
	else if (win('0') && cX > c0) cout << "illegal";
	else if (win('X')) cout << "the first player won";
	else if (win('0')) cout << "the second player won";
	else if (cX+c0 == 9) cout << "draw";
	else if (cX>c0) cout << "second";
	else cout << "first";
}