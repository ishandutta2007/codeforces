#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 3e5+3, A = 1e6+3, MOD = 1e9+7;
ll best[MN];
int main () { 
   	vector<int> w[4];
	int n,m;scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i++) {
		int ww,c;
		scanf("%d%d",&ww,&c);
		w[ww].push_back(c);
	}
	for (int i = 1; i <= 3; i++) sort(w[i].begin(),w[i].end());
	vector<int> temp[4];
	for (int i = 1; i <= 3; i++) temp[i] = w[i];
	best[0] = 0;
	for (int i = 2; i <= m; i += 2) {
		if (temp[2].empty() && temp[1].size() < 2) {while (i <= m) best[i] = best[i-2], i += 2;break;}
		if (temp[1].size() >= 2 && (temp[2].empty() || temp[1].back()+temp[1][temp[1].size()-2] > temp[2].back())) best[i] = best[i-2] + temp[1].back(), temp[1].pop_back(), best[i] += temp[1].back(), temp[1].pop_back();
		else best[i] = best[i-2] + temp[2].back(), temp[2].pop_back();
	}
	if (!w[1].empty()) {best[1] = w[1].back(); w[1].pop_back();}
	for (int i = 3; i <= m; i += 2) {
		if (w[2].empty() && w[1].size() < 2) {while (i <= m) best[i] = best[i-2], i += 2; break;}
		if (w[1].size() >= 2 && (w[2].empty() || w[1].back()+w[1][w[1].size()-2] > w[2].back())) best[i] = best[i-2] + w[1].back(), w[1].pop_back(), best[i] += w[1].back(), w[1].pop_back();
		else best[i] = best[i-2] + w[2].back(), w[2].pop_back();
	}
    for (int i = 1; i <= m; i++) best[i] = max(best[i],best[i-1]);
	ll ans = best[m], sofar = 0 ;
	while (!w[3].empty()) {
		m -= 3;
		if (m < 0) break;
		sofar += w[3].back(); w[3].pop_back();
		ans = max(ans,sofar+best[m]);
	}
	printf ("%lld\n",ans);
    return 0; 
}