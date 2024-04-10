#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#define maxn 1000009
using namespace std;
int n, a[maxn];
int d[maxn];
vector<int>fix[maxn];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	long long cur = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		cur += abs(a[i] - i);
	}
	long long sum = 0;
	for(int i = 1; i <= n; i++){
		if(i < n){
			d[i] = abs(a[i] - (i + 1)) - abs(a[i] - i);
		}
		else{
			d[i] = abs(a[n] - 1) - abs(a[n] - n);
		}
		sum += d[i];
	}
	for(int i = 1; i <= n; i++){
		fix[n - i].push_back(i);
		if(i == 1)
			fix[0].push_back(i);
		else 
			fix[n - i + 1].push_back(i);
		if(a[i] == i){
			fix[0].push_back(i);
			fix[1].push_back(i);
		}
		else if(a[i] > i){
			fix[a[i] - i - 1].push_back(i);
			fix[a[i] - i].push_back(i);
			fix[a[i] - i + 1].push_back(i);
		}
		else{
			int len = n - (i - a[i]);
			fix[len].push_back(i);
			if(len)
				fix[len - 1].push_back(i);
			fix[len + 1].push_back(i);
		}
	}
	long long res = cur;
	for(int i = 1; i < n; i++){
		res = res + sum;
		if(res < cur){
			cur = res;
			ans = i;
		}
		for(auto x: fix[i]){
			sum -= d[x];
			int curx = x + i;
			if(curx > n) curx -= n;
			int nxt = curx + 1;
			if(nxt > n) nxt -= n;
			d[x] = abs(a[x] - nxt) - abs(a[x] - curx);
			sum += d[x]; 
		}
	}
	cout << cur << " " << ans << endl;
	return 0;
}