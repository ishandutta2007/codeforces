#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> ii;


int maxs = 30100;
int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n, m, merda;
        cin >> n >> m >> merda;
        string s;
        cin >> s;
        VI G(26, 0);
        for (int i =0; i < int(s.size()); ++i) G[s[i]-'A']++;
        
        maxs = n+10;
        ll res = 1e18;
        for (int j = 0; j < int(G.size()); ++j){
            int tret = G[j];
            VI g;
            ll sum =0;
            for (int i = 0 ; i < int(G.size()); ++i){
                if (i != j){
                    g.push_back(G[i]);
                    sum += G[i];
                }
            }
            
            vector<bool> kn(maxs, false);
            kn[0] = true;
            ll least_sum = 1e18;
            for (int i = 0; i < int(g.size()); ++i){
                vector<bool> nkn = kn;
                for (int k = 0; k < maxs; ++k){
                    if (kn[k]){
                        if (k + g[i] >= n){
                            least_sum = min(least_sum, k+g[i]);
                        }
                        else nkn[k+g[i]] = true;
                    }
                }
                kn = nkn;
            }
            
            
            //cerr << "que" << endl;
            
            if (least_sum < 1e18){
                if ((sum-least_sum) + tret >= m) res = 0;
            }
            for (int i = 0; i < maxs; ++i){
                if (kn[i] and i + tret >= n){
                    ll altres = max(m - (sum-i), 0ll);
                    if (altres <= tret - max((n-i), 0   )){
                        res = min(res, max(n-i, 0)*(altres));
                    }
                }
            }
            
        }
        cout << res << endl;
    }
}