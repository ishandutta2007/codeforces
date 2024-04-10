#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cstring>

using namespace std;

const int SQ = 320;
const int MAXN = 1e5 + 10;

int n, a[MAXN], sec[MAXN], rev[MAXN], dn[MAXN], le[MAXN], ri[MAXN], par[MAXN];
set<int>	st;
map<int, int>	mp;

int go(int v){
	while (~le[v])
		v = dn[v];
	return v;
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]), sec[i] = a[i];
	sort(sec, sec + n);
	for (int i = 0; i < n; i++)	rev[i] = sec[i], mp[sec[i]] = i;
	for (int i = 0; i < n; i++)	a[i] = mp[a[i]];
	
	st.insert(a[0]);
	memset(par, -1, sizeof(par));
	memset(le, -1, sizeof(le));
	memset(ri, -1, sizeof(ri));

	for (int i = 1; i < n; i++){
		auto it = st.lower_bound(a[i]);
		int prv = -1;
		if (it == st.begin())
			par[a[i]] = *it;	
		else{
			it--;
			prv = *it;
		}
		
		if (~prv){
			if (~ri[prv])
				par[a[i]] = go(ri[prv]);
			else
				par[a[i]] = prv;
		}
	
		if (par[a[i]] > a[i])	le[par[a[i]]] = a[i];
		else	ri[par[a[i]]] = a[i];
		for (int j = 0, p = a[i]; j < SQ && ~p && p >= a[i]; j++, p = par[p])
			dn[p] = a[i];

		st.insert(a[i]);
	}

	for (int i = 1; i < n; i++)
		printf("%d ", rev[par[a[i]]]);
	printf("\n");
	return 0;
}