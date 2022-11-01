#include <bits/stdc++.h>

using namespace std;

int a[105][105];

int b[105];
int c[105];

int n, m;

bool cmp(int x, int y){
	return b[x] > b[y];
}

vector <int> getans(int x){
	int i, j;
	vector <int> ret;
	
	for(i=1;i<=m;i++){
		b[i] = a[i][x] - a[i][n];
		c[i] = i;
	}
	
	sort(c + 1, c + m + 1, cmp);
	
	int s = 0;
	
	for(i=1;i<=m;i++){
		if(s + b[c[i]] >= 0){
			s += b[c[i]];
		}else{
			ret.push_back(c[i]);
		}
	}
	
	return ret;
}

int main(){
	int i, j;
	
	scanf("%d%d", &n, &m);
	
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	vector <int> ans;
	for(i=1;i<=m;i++){
		ans.push_back(i);
	}
	
	for(i=1;i<n;i++){
		vector <int> tmp = getans(i);
		if(tmp.size() < ans.size()){
			swap(ans, tmp);
		}
	}
	
	printf("%d\n", (int)ans.size());
	for(int x : ans){
		printf("%d ", x);
	}
	printf("\n");
	
	return 0;
}