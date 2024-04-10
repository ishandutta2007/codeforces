#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, k, cnt;
bool isn[1055];
vector<int> hv[2055];
vector<int> lk[30005];

void clear()
{
	cout << 'R' << endl;
}

void add(int x)
{
	cout << "? " << x + 1 << endl;
	char ch;
	cin >> ch;
	if(ch == 'Y') isn[x] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	if(k == 1) {
		rep(i, n) rep(j, i) {
			clear();
			add(j);
			add(i);
		}
	} else {
		rep(i, n / k * 2) {
			rep(j, i) if(!hv[j].empty()) {
				lk[hv[j].back()].push_back(i);
				hv[i].push_back(hv[j].back());
				hv[j].pop_back();
			} else {
				lk[cnt].push_back(j);
				lk[cnt].push_back(i);
				hv[i].push_back(cnt);
				cnt ++;
			}
		}
		rep(i, cnt) {
			clear();
			rep(j, lk[i].size())
			for(int cur = lk[i][j] * k / 2; cur < (lk[i][j] + 1) * k / 2; cur ++) add(cur);
		}
	}
	int ans = 0;
	rep(i, n) if(!isn[i]) ans ++;
	cout << "! " << ans << endl;
	return 0;
}