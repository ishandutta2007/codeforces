#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> ii;


int main(){
    cerr << 'z' - 'a' << endl;
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
    int n;
    cin >> n;
    vector<string> v(n);
    map<ll, set<int>> hs;
    for (int i = 0; i < n; ++i){
        cin >> v[i];
        ll h = 0;
        for (int j = 0; j < int(v[i].size()); ++j){
            h = 0;
            for (int k = j; k < int(v[i].size()); ++k){
                h *= 40;
                if (v[i][k] <= 'z' and v[i][k] >= 'a'){
                    h += v[i][k]-'a'+1;
                }
                else if (v[i][k] == '.') h += 27;
                else h += 27 + v[i][k]-'0'+1;
                hs[h].insert(i);
            }
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i){
        string s;
        cin >> s;
        ll h = 0;
        for (int k = 0; k < int(s.size()); ++k){
            h *= 40;
            if (s[k] <= 'z' and s[k] >= 'a'){
                h += s[k]-'a'+1;
            }
            else if (s[k] == '.') h += 27;
            else h += 27 + s[k]-'0'+1;
        }
        if (hs.count(h)){
            cout << hs[h].size() << " " << v[*hs[h].begin()] <<'\n';
        }
        else cout << "0 -\n";
    }
}