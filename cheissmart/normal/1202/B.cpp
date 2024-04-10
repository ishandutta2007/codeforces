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

int m[10][10][10];

int main()
{
	IO_OP;
	memset(m, 0x3f, sizeof m);
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			for(int k=0;k<10;k++)
				for(int l=0;l<10;l++) {
					if(k == 0 && l == 0) continue;
					m[(i*k+j*l)%10][i][j] = min(m[(i*k+j*l)%10][i][j], k+l);
				}
	string s;
	cin >> s;
	for(int i=0;i<10;i++) {
		for(int j=0;j<10;j++) {
			int ans = 0, lst = 0;
			for(int k=1;k<s.size();k++) {
				char c = s[k];
				int x = ((c - '0') - lst + 10) % 10;
				if(m[x][i][j] == 0x3f3f3f3f) {
					ans = -1;
					break;
				}
				ans += m[x][i][j]-1;
				lst = c - '0';
			}
			if(ans != -1 && s[0] != '0') ans++;
			cout << ans << " ";
		}
		cout << endl;
	}
	
}