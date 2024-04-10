#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 10;

int n, p[MAXN], pos[MAXN];
bool pr[MAXN];
vector<int>	vec;
vector<pair<int, int>>	ans;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	scanf("%d", &p[i]), p[i]--, pos[p[i]] = i;
	pr[0] = pr[1] = 1;
	for (int i = 2; i < MAXN; i++)
		if (!pr[i]){
			vec.push_back(i - 1);
			for (int j = i + i; j < MAXN; j += i)	pr[j] = 1;
		}

	for (int i = 0; i < n; i++)
		while (pos[i] != i){
			int z = upper_bound(vec.begin(), vec.end(), pos[i] - i) - vec.begin();	z--;
			
			int tp = pos[i];
			int tx = p[tp - vec[z]];
			ans.push_back({tp - vec[z], pos[i]});
			swap(p[tp], p[tp - vec[z]]);
			swap(pos[tx], pos[i]);
		}

	printf("%d\n", (int)ans.size());
	for (auto v:ans)
		printf("%d %d\n", v.first + 1, v.second + 1);
	return	0;
}