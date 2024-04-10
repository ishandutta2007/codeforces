#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define P pair
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl
#define endl '\n'

using namespace std;

typedef long long ll;
typedef P<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int x1, y1, x2, y2, x3, y3, x4, y4, x5, y5, x6, y6;

bool ok1() {
	if(x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2) return true;
	if(x5 <= x1 && x6 >= x2 && y5 <= y1 && y6 >= y2) return true;
	if(!(y3 <= y1 && y4 >= y2 && y5 <= y1 && y6 >= y2)) return false;
	if(x3 < x5 && x4 < x5) return false;
	if(x5 < x3 && x6 < x3) return false;
	int l = min(x3, x5), r = max(x4, x6);
	if(l <= x1 && r >= x2) return true;
	return false;
}

bool ok2() {
	swap(x1, y1);
	swap(x2, y2);
	swap(x3, y3);
	swap(x4, y4);
	swap(x5, y5);
	swap(x6, y6);
	return ok1();
}

int32_t main()
{
	IO_OP;
	
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;
	if(ok1() || ok2()) cout << "NO" << endl;
	else cout << "YES" << endl;	
	
}