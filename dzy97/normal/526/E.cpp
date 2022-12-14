#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
#define N 1000010

int n, Q, a[N], p[N], n1[N], cnt[N];
ll sum[N];

int work(ll m){
	int j = 0;
	for(int i = 1;i <= n;i ++) sum[i] = sum[i - 1] + a[i];
	if(sum[n] < m) return 1;
	for(int i = 1;i <= n;i ++){
		while(j + 1 <= n && sum[j + 1] - sum[i - 1] <= m) j ++;
		p[i] = j;
	}
	for(int i = n;i;i --){
		if(p[i] == n) cnt[i] = 1, n1[i] = i - 1; else cnt[i] = cnt[p[i] + 1] + 1, n1[i] = n1[p[i] + 1];
	}
	int ret = cnt[1], left = 1;
	ll Sum = sum[n];
	for(int i = 1;i < n;i ++){
		if(left <= i) left ++; else Sum += a[i];
		while(left <= n && Sum > m) Sum -= a[left ++];
		if(left <= n) ret = min(ret, cnt[i + 1] + (n1[i + 1] + 1 < left));
	}
	return ret;
}

int main(){
//	freopen("data.in", "r", stdin);
	scanf("%d%d", &n, &Q);
	for(int i = 1;i <= n;i ++) scanf("%d", &a[i]);
	ll m;
	while(Q --){
		cin >> m;
		cout << work(m) << endl;
	}
	return 0;
}