#include <bits/stdc++.h>
                    
using namespace std;
            
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int f(int x){
	int ans = 1;
	while(x){
		if (x % 10 != 0){
			ans *= x % 10;
		}
		x /= 10;
	}
	return ans;
}

int g[1000007];
int ans[200007];
vector<pair<pair<int, int>, int> > t[10];
int sum[1000007];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 1; i <= 9; i++) g[i] = i;
    for (int i = 10; i < 1000007; i++){
    	int now = f(i);
    	if (now >= i) assert(0);
    	g[i] = g[now];
    }
    int q;
    cin >> q;
    int it = 0;
    while(q--){
    	int l, r, k;
    	cin >> l >> r >> k;
    	t[k].pb(mp(mp(l, r), it));
    	it++;
    }
    for (int c = 1; c <= 9; c++){
    	for (int i = 1; i < 1000007; i++) sum[i] = sum[i - 1] + (g[i] == c);
    	for (auto s : t[c]) ans[s.y] = sum[s.x.y] - sum[s.x.x - 1];
    }
	for (int i = 0; i < it; i++) cout << ans[i] << ' ';
}