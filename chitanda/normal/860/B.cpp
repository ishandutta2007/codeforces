#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

bool vis[70005];
unordered_map<int, int> mp[9];
pii ans[70005];

int main(){
	int n;
	scanf("%d", &n);
	char s[100];
	for(int k = 1; k <= n; ++k){
		scanf("%s", s);
		int m = strlen(s);
		for(int i = 0; i < m; ++i){
			int num = 0;
			for(int j = i; j < m; ++j){
				num = num * 10 + s[j] - '0';
				if(mp[j - i].count(num)){
					if(mp[j - i][num] != k) mp[j - i][num] = 0;
				}else mp[j - i][num] = k;
			}
		}
	}

	
	for(int i = 0; i < 9; ++i){
		for(auto v : mp[i]){
			if(v.se != 0){
				if(!vis[v.se]){
					vis[v.se] = 1;
					ans[v.se] = mkp(i, v.fi);
				}
			}
		}
	}
	
	for(int i = 1; i <= n; ++i){
		sprintf(s, "%d", ans[i].se);
		for(int j = ans[i].fi + 1 - strlen(s); j; --j) printf("0");
		printf("%s\n", s);
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}