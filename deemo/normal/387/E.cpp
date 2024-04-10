//Don't turn away now..

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 30;

int n, k;
int vec[MAXN];
bool mark[MAXN];
set<int>	st;
int fen[MAXN];

int get(int v){
	int ret = 0;
	for (; v; v -= v & (-v))
		ret += fen[v];
	return	ret;
}

void add(int v, int val){
	for (v++; v < MAXN; v += v & (-v))
		fen[v] += val;
}

int main(){
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++){
		int temp;	scanf("%d", &temp);
		vec[temp] = i;
	}

	for (int i = 0; i < k; i++){
		int temp;	scanf("%d", &temp);
		mark[temp] = 1;
	}
	
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		if (mark[i]){
			st.insert(vec[i]);
			continue;
		}
		
		set<int>::iterator it = st.lower_bound(vec[i]);
		int hi = n;
		if (it != st.end())	hi = *it;

		int lo = 0;
		if (it != st.begin()){
			it--;
			lo = *it + 1;
		}
		int z = get(hi) - get(lo);
		ans += hi - lo - z;
		add(vec[i], 1);
	}
	printf("%I64d\n", ans);
	return 0;
}