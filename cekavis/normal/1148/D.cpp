#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
int n, a[N], b[N];
vector<pair<int,int>> f, g;
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		scanf("%d%d", a+i, b+i);
		if(a[i]<b[i]) f.push_back(make_pair(b[i], i));
		else g.push_back(make_pair(a[i], i));
	}
	if(f.size()>g.size()){
		sort(f.begin(), f.end());
		printf("%d\n", (int)f.size());
		for(int i=f.size()-1; ~i; --i) printf("%d ", f[i].second);
	}
	else{
		sort(g.begin(), g.end());
		printf("%d\n", (int)g.size());
		for(auto i:g) printf("%d ", i.second);
	}
	return 0;
}