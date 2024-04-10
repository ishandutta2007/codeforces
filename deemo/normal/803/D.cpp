#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e6 + 10;

int k, n, a[MAXN], p[MAXN], d[MAXN];
pii q[MAXN];

bool ok(int mid){
	int h = 0, t = 0;
	q[t++] = {0, 0};
	for (int i = 0; i < n; i++){
		while (p[i + 1] - p[q[h].S] > mid) h++;
		d[i + 1] = q[h].F + 1;
		while (t-h && q[t - 1].F > d[i+1]) t--;
		q[t++] = {d[i+1], i+1};
	}
	return d[n] <= k;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k;
	{
		string s;
		while (cin>>s){
			int cur = 0;
			for (int i = 0; i < s.size(); i++){
				if (s[i] == '-'){
					a[n++] = cur+1;
					cur = 0;
				}
				else cur++;
			}
			a[n++] = cur+1;
		}
		a[n-1]--;
		for (int i = 0; i < n; i++)
			p[i + 1] = p[i] + a[i];
	}
	
	int lo = *max_element(a, a + n) - 1, hi = MAXN;
	while (hi-lo>1){
		int mid = hi+lo>>1;
		if (ok(mid))
			hi = mid;
		else
			lo = mid;
	}
	cout << hi << "\n";
	return 0;
}