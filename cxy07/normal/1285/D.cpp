//Code By CXY
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int n;
int a[MAXN];
vector<int> v;

int solve(int dep,vector<int> &now) {
	if(dep < 0) return 0;
	int len = now.size();
	vector<int> L,R;
	L.clear(),R.clear();
	for(register int i = 0;i < len; ++i)
		if(now[i] & (1 << dep)) L.push_back(now[i]);
		else R.push_back(now[i]);
	if(!L.size()) return solve(dep - 1,R);
	if(!R.size()) return solve(dep - 1,L);
	return min(solve(dep - 1,L),solve(dep - 1,R)) + (1 << dep);
}

int main () {
	scanf("%d",&n);
	for(register int i = 1;i <= n; ++i)
		scanf("%d",&a[i]),v.push_back(a[i]);
	printf("%d\n",solve(30,v));
}