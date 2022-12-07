#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()
#define ls (t << 1)
#define rs ((t << 1) | 1)

int n, qu;
int fa[200100];

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void merge(int x, int y){
	x = find(x), y = find(y);
	fa[y] = x;
}

int main(){
	scanf("%d%d", &n, &qu);
	for(int i = 1; i <= n; ++i) fa[i] = i;
	set<pair<int, int> > q;
	for(int i = 1; i <= n; ++i) q.insert(mkp(i, i));
	while(qu--){
		static int ty, x, y;
		scanf("%d%d%d", &ty, &x, &y);
		if(ty == 1){
			merge(x, y);
		}else if(ty == 2){
			merge(x, y);
			auto t = q.lower_bound(mkp(x, 0));
			while(t != q.end() && t->fi <= y){
				merge(x, t->fi);
				x = min(x, t->se);
				y = max(y, t->fi);
				auto tt = t++;
				q.erase(tt);
			}
			q.insert(mkp(y, x));
		}else{
			auto t1 = q.lower_bound(mkp(x, 0)), t2 = q.lower_bound(mkp(y, 0));
			x = t1->se, y = t2->se;
			x = find(x), y = find(y);
			printf("%s\n", x == y ? "YES" : "NO");
		}
	}
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}