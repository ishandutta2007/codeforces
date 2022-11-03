#include <bits/stdc++.h>
       
using namespace std;
       
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
int a[1000007], ans[1000007];;
int used[1000007];
vector<vector<int> > d;
vector<int> uk[1000007];

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < n; i++) if (!used[i]){
    	int v = i;
    	vector<int> now;
    	while(1){
    		used[v] = 1;
    		now.pb(v);
    		v = a[v];
    		if (used[v]) break;
    	}
    	uk[now.size()].pb(d.size());
    	d.pb(now);
    }
    for (int i = 2; i <= n; i += 2) if (uk[i].size() % 2 == 1) cout << -1, exit(0);

    for (int i = 1; i <= n; i += 2){
    	for (int j : uk[i]){
    		auto now = d[j];
    		for (int s = 0; s < now.size(); s++) ans[now[s]] = now[(s + (i + 1) / 2) % i];
    		/*for (int s : now) ans[s] = a[s];
    		int save = ans[now[0]];
    		int zz = 0;
    		while(1){
    			zz++;
    			if (ans[ans[now[0]]] == save) break;
    			vector<int> t;
    			for (int s : now) t.pb(ans[s]);
    			int ff = 1;
    			for (int s : now){
    				if (ff == t.size()) ff = 0;
    				ans[s] = t[ff++];
    			}
    		}
    		cout << zz << endl;*/
    	}
    }

    for (int i = 2; i <= n; i+= 2){
    	while(uk[i].size()){
    		auto w1 = d[uk[i].back()];
    		uk[i].pop_back();
    		auto w2 = d[uk[i].back()];
    		uk[i].pop_back();
    		for (int s = 0; s < i; s++) ans[w1[s]] = w2[s], ans[w2[s]] = w1[(s + 1) % i];
    	}
    }

    for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
}