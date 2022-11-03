#include <bits/stdc++.h>
          
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

int n, m;
vector<int> a, b;
 
vector<int> parse(int x){
	vector<int> ans;
	while(x){
		ans.pub(x % 10);
		x /= 10;
	}
	return ans;
}

bool ok(int x){
	auto now = parse(x);
	int cnt1 = 0, cnt2 = 0;

	for (int d : now){
		for (int w1 : a){
			if (d == w1) cnt1++;
		}
		for (int w2 : b){
			if (d == w2) cnt2++;
		}
	}

	return cnt1 > 0 && cnt2 > 0;
}

int main(){ 
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //freopen("heavy.in", "r", stdin);
    //freopen("heavy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    a.resize(n); b.resize(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int ans = 1; ans < 100; ans++) if (ok(ans)) cout << ans, exit(0);
}