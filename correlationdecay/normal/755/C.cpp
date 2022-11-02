#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iostream>
#define maxn 10009
using namespace std;
int p[maxn];
int findset(int x){
	return x == p[x] ? x : p[x] = findset(p[x]);
}
void unionset(int x, int y){
	p[findset(x)] = findset(y);
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <=n ;i++)
		p[i] = i;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		unionset(x, i);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(findset(i) == i)
			ans++;
	}
	cout << ans << endl;
	return 0;
}