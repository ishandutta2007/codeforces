#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 3e5 + 10;

int n, sec[MAXN];
ll s[MAXN], w[MAXN];
multiset<ll>	st;

bool cmp(int u, int v){return s[u] > s[v];}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &s[i], &w[i]);
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (s[i] > s[0])	ans++;

	if (ans){
		int pt = 0;
		while (pt < n){
			if (sec[pt] == 0){
				pt++;
				continue;
			}
			if (s[sec[pt]] > s[0]){
				st.insert(w[sec[pt]] - s[sec[pt]] + 1);
				pt++;
			}
			else
				break;
		}

		do{
			s[0] -= *st.begin();
			st.erase(st.begin());
			if (s[0] < 0)	break;
			while (pt < n){
				if (sec[pt] == 0){
					pt++;
					continue;
				}
				if (s[sec[pt]] > s[0]){
					st.insert(w[sec[pt]] - s[sec[pt]] + 1);
					pt++;
				}
				else
					break;
			}
			ans = min(ans, (int)st.size());
		}while (st.size());
	}

	printf("%d\n", ans + 1);
	return 0;
}