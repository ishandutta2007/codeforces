#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int a[200099], b[200099];

int main()
{
	IO_OP;
	
	int t;
	cin >> t;
	while(t--) {
		string x, y;
		cin >> x >> y;
		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());
		int i=0,j;
		while(i<y.size() && y[i] == '0') i++;
		for(j=i;x[j] == '0';j++);
		cout << j - i << endl;
	}

}