#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#define maxn 2000009
using namespace std;
int nxt[maxn], n, pre[maxn];
char ans[maxn], s[maxn];
set<int>st;
int main(){
	cin >> n;
	for(int i = 0; i < maxn; i++)
		st.insert(i);
	for(int i = 1; i <= n; i++){
		scanf("%s", s);
		int len = strlen(s);
		int num;
		scanf("%d", &num);
		for(int j = 0; j < num; j++){
			int x;
			scanf("%d", &x);
			x--;
			auto it = st.lower_bound(x);
			while((*it) <= x + len - 1){
				ans[*it] = s[(*it) - x];
				auto itt = it;
				++itt;
				st.erase(it);
				it = itt;
			}
		}
	}
	bool ok = 0;
	for(int i = maxn - 1; i >= 0; i--){
		if(ans[i] != 0){
			ok = 1;
		}
		if(ok && ans[i] == 0){
			ans[i] = 'a';
		}
	}
	puts(ans);
	return 0;
}