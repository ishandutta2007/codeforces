#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;
const int INF = 1e9 + 2;

int n, a[MAXN], b[MAXN], mark[MAXN];
ll p1[MAXN], p2[MAXN];
set<pair<ll, int>>	st;
bool sw;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &a[i]), p1[i + 1] = p1[i] + a[i];
	for (int i = 0; i < n; i++)	scanf("%d", &b[i]), p2[i + 1] = p2[i] + b[i];

	if (p1[n] < p2[n])
		for (int i = 0; i < n; i++)	
			swap(p1[i + 1], p2[i + 1]), swap(a[i], b[i]), sw = 1;
	for (int i = 0; i < n; i++)	st.insert({p1[i + 1], i + 1});

	int i1, i2;
	for (int j = 0; j < n; j++){
		auto it = st.lower_bound({p2[j + 1], -1});
		if (it->first == p2[j + 1]){
			int sz = it->second;
			if (sw){
				int temp = it->second;
				sz = j + 1;
				j = temp - 1;
			}

			printf("%d\n", sz);
			for (int i = 0; i < sz; i++)
				printf("%d ", i + 1);
			printf("\n");
			printf("%d\n", j + 1);
			for (int i = 0; i < j + 1; i++)
				printf("%d ", i + 1);
			printf("\n");
			return	0;
		}

		int dif = it->first - p2[j + 1];
		if (mark[dif]){
			i1 = mark[dif] - 1;
			i2 = j;
			break;
		}
		mark[dif] = j + 1;
	}


	int j1, j2;
	auto it = st.lower_bound({p2[i1 + 1], -1});
	j1 = it->second;
	it = st.lower_bound({p2[i2 + 1], -1});
	j2 = it->second;
	j1--, j2--;

	i1++, j1++;
	if (sw)
		swap(i1, j1), swap(i2, j2);

	printf("%d\n", j2 - j1 + 1);
	for (int i = j1; i <= j2; i++)
		printf("%d ", i + 1);
	printf("\n");

	printf("%d\n", i2 - i1 + 1);
	for (int i = i1; i <= i2; i++)
		printf("%d ", i + 1);
	printf("\n");
	return	0;
}