#include <bits/stdc++.h>
#define INF (INT_MAX/2)
using namespace std;
pair<int, int> a[105], d[11 * 11 * 3], dp[105 * 3];
int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			int t;
			cin >> t;
			t--;
			a[t] = {i, j};
		}
	}
	for(int it=0;it<n*n-1;it++) {
		fill_n(dp+(it+1)*3,3,make_pair(INF,INF));
		for (int jt=0;jt<3;++jt) {
//cerr << it << ' ' << jt << ' ' << dp[it*3+jt].first << ' ' << dp[it*3+jt].second << endl;
			int u = (a[it].first * n + a[it].second) * 3 + jt;
			fill_n(d,n*n*3,make_pair(INF,INF));
			d[u] = {0,0};
			priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> pq;
			pq.push(make_pair(d[u],u));
			while (pq.size()) {
				pair<int,int> w;
				tie(w,u) = pq.top();
				pq.pop();
				if (w > d[u])
					continue;
				for (int j = 0; j < 3; ++j) 
					if (j != u%3) {
						int v = u-u%3+j;
						pair<int,int> nw = {w.first+1,w.second+1};
						if (nw < d[v]) {
							d[v] = nw;
							pq.push({nw,v});
						}
					}
		
				int k=u%3;
				int j=u/3%n;
				int i=u/3/n;
				if (k == 0) {
					const pair<int,int> x[]={{2,1},{2,-1},{-2,-1},{-2,1},
						{1,2},{-1,2},{-1,-2},{1,-2}
					};
					for (const auto & p : x) {
						int ii = i + p.first, jj= j + p.second;
						int v = (ii * n + jj) * 3 + k;
						pair<int,int> nw = {w.first+1,w.second};
						if (min(ii,jj) >= 0 && max(ii,jj) < n && d[v] > nw) {
							d[v] = nw;
							pq.push({nw,v});
						}
					}
				} else if(k == 1) {
					const pair<int,int> x[]={
						{1, 1},{1, -1},{-1, 1},{-1,-1}
					};
					for (const auto & p : x) {
						for (int q=1;q<n;q++) {
							int ii = i + p.first*q, jj= j + p.second*q;
							int v = (ii * n + jj) * 3 + k;
							pair<int,int> nw = {w.first+1,w.second};
							if (min(ii,jj) >= 0 && max(ii,jj) < n && d[v] > nw) {
								d[v] = nw;
								pq.push({nw,v});
							}
						}
					}
					
				} else {
					const pair<int,int> x[]={
						{1, 0},{-1, 0},{0, 1},{0,-1}
					};
					for (const auto & p : x) {
						for (int q=1;q<n;q++) {
							int ii = i + p.first*q, jj= j + p.second*q;
							int v = (ii * n + jj) * 3 + k;
							pair<int,int> nw = {w.first+1,w.second};
							if (min(ii,jj) >= 0 && max(ii,jj) < n && d[v] > nw) {
								d[v] = nw;
								pq.push({nw,v});
							}
						}
					}
					
	
				}
			}
			int v = (a[it+1].first * n + a[it+1].second)*3;
			for (int i=0;i<3;++i)
				dp[it*3+3+i] = min(dp[it*3+3+i], make_pair(dp[it*3+jt].first + d[v+i].first,dp[it*3+jt].second + d[v+i].second));
		}
	}
	auto ans=min(min(dp[(n*n-1)*3],dp[(n*n-1)*3+1]),dp[(n*n-1)*3+2]);
	cout << ans.first << ' ' << ans.second << endl;
	
}