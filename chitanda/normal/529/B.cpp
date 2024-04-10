#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()

int n;
int w[1111], h[1111];
int ans = 1000000000;

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d%d", w + i, h + i);
	
	for(int x = 1; x <= 2 * n; ++x){
		int lim = x <= n ? h[x] : w[x - n];
				
		vector<int> q;
		int wid = 0, cnt = 0;
		bool flag = 1;
		for(int i = 1; i <= n; ++i){
			if(h[i] > lim && w[i] > lim){
				flag = 0;
			}else if(h[i] > lim){
				++cnt;
				wid += h[i];
			}else if(w[i] > lim){
				wid += w[i];
			}else q.pb(h[i] - w[i]), wid += w[i];
		}
		if(cnt > n / 2) continue;
		if(!flag) continue;
		sort(q.begin(), q.end());
		for(int i = 0; i < q.size() && cnt < n / 2 && q[i] < 0; ++i)
			wid += q[i], ++cnt;
		ans = min(ans, lim * wid);
	}
	
	printf("%d\n", ans);
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}