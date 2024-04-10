#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<set>

using namespace std;

const int MAXN = 2e5 + 10;

int n, q, par[MAXN], sec[MAXN];
set<int>	st;

int get_par(int v){
	if (par[v] == v)
		return	v;
	return par[v] = get_par(par[v]);
}

int main(){
	scanf("%d %d", &n, &q);
	iota(par, par + n, 0);
	for (int i = 0; i < n; i++)
		st.insert(i);

	while (q--){
		int type;	scanf("%d", &type);
		if (type == 3){
			int u, v;	scanf("%d %d", &u, &v);	u--, v--;
			if (get_par(u) == get_par(v))
				printf("YES\n");
			else
				printf("NO\n");
		}
		if (type == 1){
			int u, v;	scanf("%d %d", &u, &v);	u--, v--;
			if (get_par(u) != get_par(v))
				par[get_par(u)] = get_par(v);
		}
		if (type == 2){
			int l, r;	scanf("%d %d", &l, &r);	l--;
			
			int sz = 0;
			auto it = st.lower_bound(l);
			while (it != st.end() && *it < r){
				sec[sz++] = *it;
				it++;
			}

			for (int i = 0; i < sz - 1; i++){
				if (get_par(sec[i]) != get_par(sec[i + 1]))
					par[get_par(sec[i])] = get_par(sec[i + 1]);
				if (i)
					st.erase(sec[i]);
			}
		}	
	}
	return	0;
}