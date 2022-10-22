#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int MAXN = 1e6 + 10;

int n, q, a[MAXN], sec[MAXN];
bool seen[MAXN];
ordered_set st;

int main(){
	scanf("%d %d", &q, &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if (seen[a[i]]){
			n--;
			i--;
			continue;
		}
		seen[a[i]] = 1;
	}

	int sz = 0;
	while (q--){
		int type;	scanf("%d", &type);
		if (type == -1){
			int p = 0;
			while (p < n && a[p] <= (int)st.size())	p++;
			copy(a, a + p, sec);
			sort(sec, sec + p);
			while (p--)
				st.erase(st.find_by_order(sec[p] - 1));
		}
		if (type == 0)
			st.insert({sz++, 0});
		if (type == 1)
			st.insert({sz++, 1});
	}

	if (st.empty())
		printf("Poor stack!\n");
	else{
		for (auto v:st)
			printf("%d", v.second);
		printf("\n");
	}	
	return 0;
}