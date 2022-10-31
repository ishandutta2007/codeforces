#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define maxn 100005
#define INF 1LL << 60
using namespace std;
struct data{
	int s, t, d, w;
	bool operator < (const data &x) const{
		return w < x.w || w == x.w && d < x.d;
	}
	bool operator == (const data &x) const{
		return d == x.d && w == x.w;
	}
};
vector <data> in[maxn], out[maxn];
data a[maxn];
long long f[maxn][202];
priority_queue <data> q, q_out;
int main(){
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; ++ i){
		scanf("%d %d %d %d", &a[i].s, &a[i].t, &a[i].d, &a[i].w);
		in[a[i].t].push_back(a[i]);
		out[a[i].s - 1].push_back(a[i]);
	}
	long long ans = INF;
	for (int i = n; i; -- i){
		for (int j = 0; j < in[i].size(); ++ j)
			q.push(in[i][j]);
		for (int j = 0; j < out[i].size(); ++ j)
			q_out.push(out[i][j]);
		while (! q.empty() && ! q_out.empty() && q.top() == q_out.top()){
			q.pop();
			q_out.pop();
		}
		for (int j = 0; j <= m; ++ j){
			if (q.size())
				f[i][j] = f[q.top().d + 1][j] + q.top().w;
			else
				f[i][j] = f[i + 1][j];
			if (j)
				f[i][j] = min(f[i][j], f[i + 1][j - 1]);
			if (i == 1)
				ans = min(ans, f[i][j]);
		}
	}
	cout << ans << endl;
}