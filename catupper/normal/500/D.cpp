#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std;
typedef pair<int, double> P;
double sum;
double all;
int cnt[108000];
vector<P> edge[108000];
int a[108000], b[108000];
int n;
int l[108000];
int q, r, w;
void dfs(int x, int last = -1){
	cnt[x] = 1;
	for(int i = 0;i < edge[x].size();i++){
		int to = edge[x][i].first;
		if(to == last)continue;
		dfs(to, x);
		cnt[x] += cnt[to];
	}
}


double c(int a, int b){
	double p = min(cnt[a], cnt[b]);
	double rest = n - p;
	return rest * p * (p - 1) / 2 + p * rest * (rest - 1) / 2;
}

int main(){
	cin >> n;
	all = (double)n * (n - 1) / 2 * (n - 2) / 3;
	for(int i = 1;i < n;i++){
		cin >> a[i] >> b[i] >> l[i];
		edge[a[i]].push_back(P(b[i], l[i]));
		edge[b[i]].push_back(P(a[i], l[i]));
	}
	dfs(1);
	for(int i = 1;i < n;i++){
		sum += l[i] * c(a[i], b[i]);
	}
	cin >> q;
	while(q--){
		cin >> r >> w;
		sum -= (l[r] - w) * c(a[r], b[r]);
		l[r] = w;
		printf("%.10lf\n", sum / all * 2);
	}
	return 0;
}