#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 5;

int n, l, k;

char a[maxn];

string ans[maxn];

int main(){
	int i, j, x;
	
	scanf("%d%d%d", &n, &l, &k);
	
	for(i=1;i<=n*l;i++){
		scanf(" %c", &a[i]);
	}
	
	sort(a + 1, a + n * l + 1);
	x = 0;
	
	int s = 1;
	
	for(i=1;i<=l;i++){
		for(j=s;j<=k;j++){
			ans[j].push_back(a[++x]);
			if(j != s and ans[j].back() != ans[j - 1].back())s = j;
		}
	}
	
	for(i=1;i<=n;i++){
		while(ans[i].size() < l){
			ans[i].push_back(a[++x]);
		}
		printf("%s\n", ans[i].c_str());
	}
	
	return 0;
}