#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<numeric>
#include<cstdio>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#define frist first
#define bulid build
typedef long long ll;
using namespace std;
int n;
vector<int>p[200007];
int h[200007];
int val[200007];
int sign = 0;
bool solve1(const vector<int> &a) {
	for(auto x : a) {
		sign++;
		for(auto y : p[x]) {
			h[y] = sign;
		}
		for(int i = 1;i <= n;i++) {
			if(i == x) continue;
			int sum = 0;
			for(auto y : p[i]) {
				sum += (h[y] == sign);
				if(sum > 1) {
					printf("%d %d\n",x,i);
					return true;
				}
			}
		}
	}
	return false;
}
vector<int>dis;
vector<int>fr[200007];
bool solve2(const vector<int> &a) {
	for(int i = 0;i <= dis.size();i++) {
		fr[i].clear();
	}
	for(auto y : a) {
		for(auto x : p[y]) {
			fr[x].push_back(y);
		}
	}
	for(int i = dis.size();~i;i--) {
		sign++;
		for(auto y : fr[i]) {
			for(auto x : p[y]) {
				if(x == i) break;
				if(h[x] == sign) {
					printf("%d %d\n",val[x],y);
					return true;
				}
				else {
					h[x] = sign;
					val[x] = y;
				}
			}
		}
	}
	return false;
}
inline int getint() {
	char ch = getchar();
	int res = 0;
	while(ch < '0' || '9' < ch) {
		ch = getchar();
	}
	while('0' <= ch && ch <= '9') {
		res = (res * 10) + (ch - '0');
		ch = getchar();
	}
	return res;
}
void work() {
	dis.clear();
	n = getint();
	for(int i = 1;i <= n;i++) {
		p[i].clear();
	}
	int sum = 0;
	for(int i = 1;i <= n;i++) {
		int x = getint();
		sum += x;
		while(x--) {
			int y = getint();
			p[i].emplace_back(y);
			dis.push_back(y);
		}
		sort(p[i].begin(),p[i].end());
	}
	sort(dis.begin(),dis.end());
	dis.erase(unique(dis.begin(),dis.end()),dis.end());
	for(int i = 1;i <= n;i++) {
		for(auto &y : p[i]) {
			y = lower_bound(dis.begin(),dis.end(),y) - dis.begin() + 1;
		}
	}
	int lim = sqrt(sum);
	vector<int>b,s;
	for(int i = 1;i <= n;i++) {
		if(p[i].size() > lim) {
			b.emplace_back(i);
		}
		else {
			s.emplace_back(i);
		}
	}
	if(solve1(b)) return;
	if(solve2(s)) return;
	puts("-1");
	return;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--) {
		work();
	}
	return 0;
}
/*
6
4
2 1 10
3 1 3 5
5 5 4 3 2 1
3 10 20 30
3
4 1 2 3 4
4 2 3 4 5
4 3 4 5 6
2
3 1 3 5
3 4 3 2
4
2 1 10
3 1 3 5
5 5 4 3 2 1
3 10 20 30
3
4 1 2 3 4
4 2 3 4 5
4 3 4 5 6
2
3 1 3 5
3 4 3 2

2
2
4 1 2 3 4
4 2 5 6 1
5
2 1 9
2 1 7
2 1 8
3 1 7 8
2 1 2
*/