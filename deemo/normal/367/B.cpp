#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>

using namespace std;

int n, m, p;
vector<int>	a, b, ans;
map<int, int>	mp, f;

int main(){
	scanf("%d%d%d", &n, &m, &p);
	a.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	b.resize(m);
	for (int i = 0; i < m; i++){
		scanf("%d", &b[i]);
		f[b[i]]++;	
	}	

	for (int i = 0; i < p && i < n; i++){
		int cnt = 0;
		mp.clear();
		for (int j = i, w = 0; j < n; j += p, w++){
			mp[a[j]]++;
			if (mp[a[j]] <= f[a[j]])	cnt++;
			if (w >= m - 1){
				int ind = j - (m - 1) * p;
				if (cnt == m)
					ans.push_back(ind);
				mp[a[ind]] -= 1;
				if (mp[a[ind]] < f[a[ind]])	cnt--;
			}
		}
	}
	printf("%d\n", (int)ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i] + 1);
	printf("\n");
	return 0;
}