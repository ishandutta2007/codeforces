/*
nm1k

*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;

const int maxn = 300009;
set<int> list, e[maxn];
int q[maxn], n, m, K, u, v, ans, r, flag;

void solve(int x){
	set<int>::iterator it1, it2; 
	list.erase(x); r = 0; q[r++] = x;
	for (int l=0; l<r; l++){
		x = q[l];
		it1 = list.begin();
		while (it1 != list.end()){ 
			if (e[x].count(*it1)) { it1++; continue; }
			q[r++] = *it1; 
			it2 = it1; it2++;
			list.erase(*it1);
			it1 = it2;
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &K); 
	for (int i=1; i<=m; i++){
		scanf("%d%d", &u, &v);
		e[u].insert(v), e[v].insert(u);
	}
	for (int i=2; i<=n; i++) list.insert(i);
	if (e[1].size() > n-K-1){
		puts("impossible"); return 0;
	}
	for (int i=2; i<=n; i++)
		if (list.count(i)){
			solve(i); flag = 0;
			for (int j=0; j<r; j++)
				if (!e[1].count(q[j])){
					flag = 1; break;
				}
			if (!flag){
				puts("impossible"); return 0;
			}
			ans++;
		} 
	if (ans <= K) puts("possible");
	else puts("impossible");
	return 0;
}