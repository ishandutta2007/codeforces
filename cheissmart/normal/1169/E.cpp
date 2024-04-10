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

int a[300005], s[20][300005], b[20];

int main()
{
	IO_OP;
	
	int n, q;
	cin >> n >> q;
	for(int i=0;i<n;i++)
		cin >> a[i];
	memset(s, 0x3f, sizeof s);
	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<19;j++)				
			if(a[i]>>j & 1){
				s[j][i] = i;
				for(int k=0;k<19;k++) {
					s[k][i] = min(s[k][i], s[k][b[j]]);
				}
			}
		for(int j=0;j<19;j++)
			if(a[i]>>j & 1)
				b[j] = i;
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		bool ok = 0;
		for(int i=0;i<19;i++)
			if((a[y]>>i&1) && s[i][x] <= y)
				ok = 1;
		if(ok) cout << "Shi" << endl;
		else cout << "Fou" << endl;
	}
	
}