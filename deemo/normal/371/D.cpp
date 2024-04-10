#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

const int max_n = 3e5;

int n, q;
vector<int>	vec, sec;
int nextt[max_n], pre[max_n];
set<int>	st;

void update(int v, int val){
	v = *st.lower_bound(v);
	for (int i = v; val && i <= n; i = nextt[i]){
		int t = min(val, vec[i] - sec[i]);
		sec[i] += t;
		val -= t;
		if (sec[i] == vec[i]){
			int b = nextt[i], a = pre[i];
			nextt[a] = b;
			pre[b] = a;
			st.erase(i);
		}
	}
}

int main(){
	scanf("%d", &n);
	vec.resize(n + 2);
	sec.resize(n + 2);
	vec[0] = vec[n + 1] = 1;
	for (int i = 1; i <= n; i++){
		scanf("%d", &vec[i]);
		nextt[i] = i + 1;
		pre[i] = i - 1;
		st.insert(i);
	}
	st.insert(0);
	st.insert(n + 1);
	scanf("%d", &q);
	while (q--){
		int type;	scanf("%d", &type);
		if (type == 1){
			int v, val;	scanf("%d%d", &v, &val);
			update(v, val);
		}
		else{
			int v;	scanf("%d", &v);
			printf("%d\n", sec[v]);
		}
	}
	return 0;
}