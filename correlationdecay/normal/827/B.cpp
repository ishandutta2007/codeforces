#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>
#include <set>
#define maxn 2000009
using namespace std;
int n, k;
int tot = 1, mx1, mx2;
vector<pair<int,int> > ans;
void getline(int x){
	int last = 1;
	for(int i = 1; i <= x + 1; i++){
		ans.push_back(make_pair(last, ++tot));
		last = tot;
	}
	if(mx1 < x + 1){
		mx2 = mx1;
		mx1 = x + 1;
	}
	else if(mx2 < x + 1){
		mx2 = x + 1;
	}
}
int main(){
	cin >> n >> k;
	int rest = n - 1 - k;
	for(int i = 1; i <= k; i++){
		if(i <= rest % k){
			getline(rest / k + 1);
		}
		else{
			getline(rest / k);
		}
	}
	printf("%d\n", mx1 + mx2);
	for(auto x: ans){
		printf("%d %d\n", x.first, x.second);
	}
	return 0;
}