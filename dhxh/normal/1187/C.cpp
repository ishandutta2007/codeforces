#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1005;

int n, m, t;

int ans[maxn];

vector <pair <int, int> > veca, vecb, vecc;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y, z;
	
	n = read();
	m = read();
	
	for(i=1;i<=m;i++){
		x = read();
		y = read();
		z = read();
		if(x == 1){
			veca.push_back(make_pair(y, z));
		}else{
			vecb.push_back(make_pair(y, z));
		}
	}
	
	for(i=1;i<=n;i++){
		ans[i] = n - i + 1;
	}
	
	sort(veca.begin(), veca.end());
	
	if(veca.size())vecc.push_back(veca[0]);
	
	for(i=1;i<veca.size();i++){
		if(vecc.back().second >= veca[i].first){
			vecc.back().second = max(vecc.back().second, veca[i].second);
		}else{
			vecc.push_back(veca[i]);
		}
	}
	
	for(pair <int, int> tmp : vecc){
		sort(ans + tmp.first, ans + tmp.second + 1);
	}
	
	for(pair <int, int> tmp : vecb){
		bool flag = false;
		for(j=tmp.first+1;j<=tmp.second;j++){
			if(ans[j - 1] > ans[j]){
				flag = true;
				break;
			}
		}
		if(!flag){
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	
	for(i=1;i<=n;i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}