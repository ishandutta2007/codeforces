//int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

const int maxn = 100100;
int n, k, L1[maxn], R1[maxn], L2[maxn], R2[maxn];
struct node{
	int x, y;
}p[maxn];

bool cmp(node a, node b){
	return a.x < b.x;
}

ll pow(int a){
	return (ll)a * a;
}

bool check(ll r){
	int mi, ma;
	for(int i = 1, j1 = k, j2 = n; i <= k; i++){
		if(pow(p[i].x) > r) continue;
		while(j1 < n && pow(p[j1 + 1].x - p[i].x) <= r) j1++;
		while(j2 > k && abs(p[j2].x) > abs(p[i].x)) j2--;
		mi = min(0, min(L1[i - 1], R1[min(j1, j2) + 1]));
		ma = max(0, max(L2[i - 1], R2[min(j1, j2) + 1]));
		if(pow(ma - mi) <= r && max(pow(ma), pow(mi)) + pow(p[i].x) <= r) return 1;
	}
	for(int i = n, j1 = k + 1, j2 = 1; i > k; i--){
		if(pow(p[i].x) > r) continue;
		while(j1 > 1 && pow(p[j1 - 1].x - p[i].x) <= r) j1--;
		while(j2 <= k && abs(p[j2].x) > abs(p[i].x)) j2++;
		mi = min(0, min(R1[i + 1], L1[max(j1, j2) - 1]));
		ma = max(0, max(R2[i + 1], L2[max(j1, j2) - 1]));
		if(pow(ma - mi) <= r && max(pow(ma), pow(mi)) + pow(p[i].x) <= r) return 1;
	}
	return 0;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
	sort(p + 1, p + n + 1, cmp);
	for(int i = 1; i <= n; i++) if(p[i].x <= 0) k = i;
	L1[1] = L2[1] = p[1].y, R1[n] = R2[n] = p[n].y;
	for(int i = 2; i <= n; i++) L1[i] = min(L1[i - 1], p[i].y), L2[i] = max(L2[i - 1], p[i].y);
	for(int i = n - 1; i >= 1; i--) R1[i] = min(R1[i + 1], p[i].y), R2[i] = max(R2[i + 1], p[i].y);
	ll l = -1, r = 1LL << 56;
	while(l + 1 < r){
		ll mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	r = min(r, pow(p[n].x - p[1].x));
	r = min(r, pow(L2[n] - L1[n]));
	cout << r;
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/