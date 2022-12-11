#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> ii;

const int lim = 300;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
        cout.setf(ios::fixed);
        cout.precision(5);
        int n;
        cin >> n;
        vector<double> p(n);
        VVI t(n);
        for (int i = 0; i < n; ++i){
            cin >> p[i];
        }
        for (int i = 0; i < n-1; ++i){
            int u, v;
            cin >> u >> v;
            t[u].push_back(v);
            t[v].push_back(u);
        }
        
        VVI l(n), h(n);
        vector<double> sum(n, 0);
        double ans = 1;
        for (int i = 0; i < n; ++i){
            for (int v : t[i]){
                sum[i] += p[v];
                if (t[v].size() > lim) h[i].push_back(v);
                else l[i].push_back(v);
            }
            ans -= sum[i]*p[i]/2;
            ans += (t[i].size()-1)*p[i];
        }
        
        cerr << "ep " << ans << endl;
        
        int q;
        cin >> q;
        for (int z = 0; z < q; ++z){
            int u;
            double np;
            cin >> u >> np;
            if (n == 1){
                cout << 1-np<<"\n";
                continue;
            }
            if (t[u].size() > lim){
                ans -= (np-p[u])*sum[u];
            }
            else{
                sum[u] = 0;
                for (int v : t[u]){
                    sum[u] += p[v];
                }
                ans -= (np-p[u])*sum[u];
            }
            ans += (t[u].size()-1)*(np-p[u]);
            
            for (int v : h[u]){
                sum[v] += np-p[u];
            }
            
            p[u] = np;
        
            cout << ans << "\n";
            
        }
        cout << endl;
    
}