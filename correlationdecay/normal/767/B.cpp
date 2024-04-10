#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <cmath>
#include <iostream>
#define maxn 1000009
using namespace std;
long long X[maxn], ts, tf, t;
long long P[maxn];
int n, tot;
const long long INF = 1e18;
long long Server(long long l, long long r, long long L, long long R){
	long long nl = max(L, l);
	long long nr = min(R, r);
	return max(0LL, nr - nl);
}
long long waittime(long long len, long long cur, long long L, long long R){
	if(cur < L){
		if(L + len + t <= R){
			return L - cur + len;
		}
		else{
			return INF;
		}
	}
	else{
		if(cur + len + t > R)
			return INF;
		else
			return len;
	}
}
int main(){
	cin >> ts >> tf >> t;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> P[i];
		X[tot++] = P[i];
		X[tot++] = P[i] + t;
		X[tot++] = max(0LL, P[i] - 1);
		X[tot++] = P[i] + 1;
		X[tot++] = max(0LL, P[i] + t - 1);
		X[tot++] = P[i] + t + 1;
	}
	X[tot++] = 0;
	X[tot++] = ts;
	X[tot++] = tf - t;
	sort(X, X + tot);
	tot = unique(X, X + tot) - X;
	long long  ans = INF, pos = -1;
	int j = 1;
	long long sum = 0;
	for(int i = 0; i < tot; i++){
		if(X[i] >= ts && i > 0){
			long long server_time = Server(X[i - 1], X[i], ts, tf);
			sum -= min(sum, server_time);
		}
		while(j <= n && P[j] <= X[i]){
			sum += t;
			j++;
		}
		if(waittime(sum, X[i], ts, tf) < ans){
			ans = waittime(sum, X[i], ts, tf);
			pos = X[i];
		}
		//cout << ans << endl;
	}
	cout << pos << endl;
	return 0;
}