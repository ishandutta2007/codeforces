 
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;

bool cmp(pi a, pi b){
  	ll a1 = a.first;
  	ll a2 = a.second;
  	ll b1 = b.first;
  	ll b2 = b.second;
    return a1*b2 > b1*a2;
}

int main() { FAST
    int t,h,v;
    cin >> t;
    for (int test = 0; test < t; test++){
        cin >> h;
        vi hs = vi();
        int sh = 0;
        for(int j = 0; j < h; j++){
            int n;
            cin >> n;
            hs.pb(n);
            sh += n;
        }
        cin >> v;
        vi vs = vi();
        int sv = 0;
        for(int j = 0; j < v; j++){
            int n;
            cin >> n;
            vs.pb(n);
            sv += n;
        }
        if (h != v || sh % 2 == 1 || sv % 2 == 1){
            cout << "No\n";
            continue;
        }
        
        vi rh = vi();
        vi rv = vi();
        
        int wanth = sh/2;
        bool partitionh[h][wanth + 1];
        for (int i = 0; i <= wanth; i++){
            partitionh[0][i] = (i == hs[0] || i == 0);
        }
        for (int i = 1; i < h; i++){
          	int val = hs[i];
            for (int j = 0; j <= wanth; j++){
                partitionh[i][j] = partitionh[i-1][j] || (j >= val && partitionh[i-1][j-val]);
            }
        }
      
      	if (partitionh[h-1][wanth]){
         	int curr = h-1;
          	int currv = wanth;
          	while (currv > 0){
            	if (curr != 0  && partitionh[curr-1][currv]){
                	rh.pb(hs[curr]);
                }
              	else{
                	rh.pb(-hs[curr]);
                    currv -= hs[curr];
                }
                  
                curr -= 1;
            }
          	while(curr >= 0){
            	rh.pb(hs[curr]);
               	curr -= 1;
            }
        }
      	else{
            cout << "No\n";
            continue;
        }
    
        //Vertical
        int wantv = sv/2;
        bool partitionv[v][wantv + 1];
        for (int i = 0; i <= wantv; i++){
            partitionv[0][i] = (i == vs[0] || i == 0);
        }
        for (int i = 1; i < v; i++){
          	int val = vs[i];
            for (int j = 0; j <= wantv; j++){
                partitionv[i][j] = partitionv[i-1][j] || (j >= val && partitionv[i-1][j-val]);
            }
        }
      
      	if (partitionv[v-1][wantv]){
         	int curr = v-1;
          	int currv = wantv;
          	while (currv > 0){
            	if (curr != 0  && partitionv[curr-1][currv]){
                	rv.pb(vs[curr]);
                }
              	else{
                	rv.pb(-vs[curr]);
                    currv -= vs[curr];
                }
                  
                curr -= 1;
            }
          	while(curr >= 0){
            	rv.pb(vs[curr]);
               	curr -= 1;
            }
        }
      	else{
            cout << "No\n";
            continue;
        }
        
        cout << "Yes\n";
        
        vector<pair<int,int>> pp;
        vector<pair<int,int>> pn;
        vector<pair<int,int>> np;
        vector<pair<int,int>> nn;
        vector<pair<int,int>> final;
        int pph = 0;
        int pnh = 0;
        int nph = 0;
        int nnh = 0;
        int ppy = 0;
        int pny = 0;
        int npy = 0;
        int nny = 0;
        
        for(int i = 0; i < h; i++){
            int dx = rh[i];
            int dy = rv[i];
            if (dx >= 0){
                if (dy >= 0){
                    pp.pb(pair(dx,dy));
                    pph += dx;
                    ppy += dy;
                }
                else{
                    pn.pb(pair(dx,dy));
                    pnh += dx;
                    pny += dy;
                }
            }
            else{
                if (dy >= 0){
                    np.pb(pair(dx,dy));
                    nph += dx;
                    npy += dy;
                }
                else{
                    nn.pb(pair(dx,dy));
                    nnh += dx;
                    nny += dy;
                }
            }
        }
      
      sort(pp.begin(),pp.end(),cmp);
      sort(pn.begin(),pn.end(),cmp);
      sort(np.begin(),np.end(),cmp);
      sort(nn.begin(),nn.end(),cmp);
        
        if (pph + nph > 0 || npy + nny < 0){
            final.insert(final.end(),pp.begin(),pp.end());
            final.insert(final.end(),np.begin(),np.end());
            final.insert(final.end(),nn.begin(),nn.end());
            final.insert(final.end(),pn.begin(),pn.end());
        }
        else{
            final.insert(final.end(),pn.begin(),pn.end());
            final.insert(final.end(),nn.begin(),nn.end());
            final.insert(final.end(),np.begin(),np.end());
            final.insert(final.end(),pp.begin(),pp.end());
        }
        
        int x = 0;
        int y = 0;
        for (auto [dx,dy]: final){
            x += dx;
            cout << x << " " << y << '\n';
            y += dy;
            cout << x << " " << y << '\n';
        }
        
    }
}