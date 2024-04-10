#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2e6 + 10;

int n, k;
vector<int>	vec[MAXN];
set<int> st;

void handle(int a, int b){
	if (a < b){
		while (st.size()){
			auto it = st.lower_bound(k-b);
			if (it == st.end() || *it >= k - a)	break;
			st.erase(it);
		}
	}
	else{
		while (st.size() && *st.begin() < k - a) st.erase(st.begin());
		while (st.size()){
			auto it = st.lower_bound(k - b);
			if (it == st.end())	break;
			st.erase(it);
		}
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++){
		int temp;	scanf("%d", &temp);
		vec[i].resize(temp);
		for (int j = 0; j < temp; j++)
			scanf("%d", &vec[i][j]), vec[i][j]--;
	}

	for (int i = 0; i < k; i++)	st.insert(i);

	for (int i = 0; i + 1 < n; i++){
		int sz1 = vec[i].size(), sz2 = vec[i + 1].size();
		int j = 0;
		for (; j < min(sz1, sz2); j++)
			if (vec[i][j] ^ vec[i + 1][j])	break;
		
		if (j == min(sz1, sz2)){
			if ((int)vec[i].size() != min(sz1, sz2)){
				printf("-1\n");
				return 0;
			}
			continue;
		}
		int a = vec[i][j], b = vec[i + 1][j];
		handle(a, b);
	}
	
	if (st.size())
		printf("%d\n", *st.begin());
	else
		printf("-1\n");
	return 0;
}