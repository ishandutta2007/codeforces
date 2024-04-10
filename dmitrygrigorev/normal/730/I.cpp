#include <bits/stdc++.h>
#define int long long
using namespace std;
struct V{int A; int B; int num;};
vector<V> g;
bool cmp(V f, V s){
	if (f.A > s.A) return true;
	if (f.A < s.A) return false;
	if (f.B < s.B) return true;
	return false;
}
vector<int> i1, i2;
signed main(){
    int n, p, s;
    cin >> n >> p >> s;
    int a[n], b[n];
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < n; i++) cin >> b[i];
    for (int i=0; i < n; i++){
		V nv = {a[i], b[i], i};
		g.push_back(nv);
    }
    sort(g.begin(), g.end(), cmp);
    int ans = -1;
    for (int ber=p-1; ber <= p+s-1; ber++){
        vector<pair<int, int> > gg;
        for (int i=ber+1; i < n; i++){
			gg.push_back(make_pair(g[i].B, g[i].num));
        }
        sort(gg.begin(), gg.end(), greater<pair<int, int> >());
        int var = 0;
        vector<int> var1, var2;
        for (int i=0; i < p+s-1-ber; i++){
			var += gg[i].first;
			var2.push_back(gg[i].second);
        }
        gg.clear();
        vector<bool> used(n);
        fill(used.begin(), used.end(), false);
        for (int i=0; i <= ber; i++) gg.push_back(make_pair(g[i].B-g[i].A, g[i].num));
        for (int i=0; i <= ber; i++) var += g[i].A;
        sort(gg.begin(), gg.end(), greater<pair<int, int> >());
        for (int i=0; i < ber-p+1; i++){
			used[gg[i].second] = true;
			var += gg[i].first;
			var2.push_back(gg[i].second);
        }
        for (int i=0; i <= ber; i++){
			if (!used[gg[i].second]) var1.push_back(gg[i].second);
        }
        if (var>ans){
			ans=var;
			i1 = var1;
			i2 = var2;
        }
    }
    sort(i1.begin(), i1.end());
    sort(i2.begin(), i2.end());
    cout << ans << endl;
    for (int i=0;i<p;i++) cout << i1[i]+1 << " ";
    cout << endl;
    for (int i=0;i<s;i++) cout << i2[i]+1 << " ";
}