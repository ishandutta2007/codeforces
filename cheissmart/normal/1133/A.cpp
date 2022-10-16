#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	char c;
	int h1, m1, h2, m2;
	cin >> h1 >> c >> m1 >> h2 >> c >> m2;
	int m = (h1*60+m1+h2*60+m2) / 2;
	cout << (m/60 < 10 ? "0" : "") << m/60 << ":" << (m%60 < 10 ? "0" : "")<< m%60 << endl;
	
}