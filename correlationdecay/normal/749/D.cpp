#include <bits/stdc++.h>
#define maxn 200009
using namespace std;
int n;
int mx[maxn];
vector<int>G[maxn];
set<pair<int,int> >st;
vector<int>a;
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int x, y;
		scanf("%d%d", &x, &y);
		mx[x] = y;
		G[x].push_back(y);
	}
	for(int i = 1; i <= n; i++){
		if(mx[i] == 0)
			continue;
		st.insert(make_pair(mx[i], i));
	}
	int Q;
	scanf("%d", &Q);
	while(Q--){
		int num = 0;
		scanf("%d", &num);
		a.clear();
		for(int j = 0; j < num; j++){
			int x;
			scanf("%d" ,&x);
			a.push_back(x);
		}

		for(int j = 0; j < num; j++){
			int u = a[j];
			if(st.count(make_pair(mx[u],u))){
				st.erase(make_pair(mx[u],u));
			}
		}

		if((int)st.size() == 0){
			puts("0 0");
		}
		else if((int)st.size()==1){
			auto it = st.end();
			--it;
			int u = it->second;
			printf("%d %d\n", u, G[u][0]);
		}
		else{
			auto it = st.end();
			--it;
			int u = it ->second;
			--it;
			int v = it->first;

			auto res = lower_bound(G[u].begin(),G[u].end(),v);
			printf("%d %d\n", u, *res);
		}

		for(int j = 0; j < num; j++){
			if(mx[a[j]] != 0)
				st.insert(make_pair(mx[a[j]],a[j]));
		}
	}
	//system("pause");
	return 0;
}