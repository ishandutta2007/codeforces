#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define maxn 109
using namespace std;
int n, m;
int b[maxn][maxn], a[maxn][maxn];
vector<int>ans1, ans2;
bool ok1 = 0, ok2 = 0;

bool solve1(){
	for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m; j++)
		a[i][j] = b[i][j];
	for(int i = 1; i <= n; i++){
		int mi = 1e9;
		for(int j = 1; j <= m; j++)
			mi = min(mi, a[i][j]);
		for(int j = 1; j <= mi; j++)
			ans1.push_back(i);
		for(int j = 1; j <= m; j++)
			a[i][j] -= mi;
	}
	for(int j = 1; j <= m; j++){
		int mi = 1e9;
		for(int i = 1; i <= n; i++)
			mi = min(mi, a[i][j]);
		for(int i = 1; i <= mi; i++)
			ans1.push_back(-j);
		for(int i = 1; i <= n; i++)
			a[i][j] -= mi;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] > 0)
				return 0;
	return 1;
}

bool solve2(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = b[i][j];
	for(int j = 1; j <= m; j++){
		int mi = 1e9;
		for(int i = 1; i <= n; i++)
			mi = min(mi, a[i][j]);
		for(int i = 1; i <= mi; i++)
			ans2.push_back(-j);
		for(int i = 1; i <= n; i++)
			a[i][j] -= mi;
	}
	for(int i = 1; i <= n; i++){
		int mi = 1e9;
		for(int j = 1; j <= m; j++)
			mi = min(mi, a[i][j]);
		for(int j = 1; j <= mi; j++)
			ans2.push_back(i);
		for(int j = 1; j <= m; j++)
			a[i][j] -= mi;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] > 0)
				return 0;
	return 1;
}

void output(vector<int>&ans){
	cout << ans.size() << endl;
	for(int i = 0; i < (int)ans.size(); i++){
		if(ans[i] > 0)
			printf("row %d\n", ans[i]);
		else
			printf("col %d\n", -ans[i]);
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++)
			cin >> b[i][j];
	}
	ok1 = solve1();
	ok2 = solve2();
	if(!ok1 && ok2){
		output(ans2);
	}
	else if(ok1 && !ok2){
		output(ans1);
	}
	else if(ok1 && ok2){
		//puts("!!!");
		if(ans1.size() < ans2.size())
			output(ans1);
		else
			output(ans2);
	}
	else{
		puts("-1");
	}
	return 0;
}