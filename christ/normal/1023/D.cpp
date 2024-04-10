        #include <bits/stdc++.h>
        using namespace std;
        using ll = long long;
        using ull = unsigned long long;
        using pii = pair<int,int>;
        using pll = pair<ll,ll>;
        using ld = long double;
        #define all(x) (x).begin(),(x).end()
        const int MN = 5e5 + 5, MOD = 1e9 + 7;
        int a[MN], l[MN], r[MN], ret[MN];
        vector<int> st[MN], ed[MN];
        int main () {
        	int n,q, pos = -1;
        	scanf ("%d %d",&n,&q);
        	for (int i = 1; i <= n; i++) {
        		scanf ("%d",&a[i]);
        		if (a[i] == 0) pos = i;
        		else if (pos == -1 || (a[pos] && a[i] > a[pos])) pos = i;
        		if (!l[a[i]]) l[a[i]] = i;
        		r[a[i]] = i;
        	}
        	for (int i = 1; i <= q; i++) { //query 1 can cover everything
        		if (i == 1) {
        			st[1].push_back(1);
        			ed[n].push_back(1);
        		} else if (!l[i]){
        			st[pos].push_back(i);
        			ed[pos].push_back(i);
        		} else {
        			st[l[i]].push_back(i);
        			ed[r[i]].push_back(i);
        		}
        	}
        	//construct array
        	multiset<int> can;
        	for (int i = 1; i <= n; i++) {
        		for (int j : st[i]) can.insert(j);
        		ret[i] = *can.rbegin();
        		for (int j : ed[i]) can.erase(can.find(j));
        	}
        	for (int i = 1; i <= n; i++) if (a[i] && ret[i] != a[i]) return !printf ("NO\n");
        	printf ("YES\n");
        	for (int i = 1; i <= n; i++) printf ("%d%c",ret[i]," \n"[i==n]);
        	return 0;
        }