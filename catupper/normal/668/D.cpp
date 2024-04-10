#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;
typedef pair<int, int> P;
typedef pair<P, P> Q;

Q query[108000];
int ans[108000];
int bit[108000], n;
vector<int> nums;

void _add(int x, int v){
	x++;
	while(x < 108000){
		bit[x]+=v;
		x += x & -x;
	}
}

int _sum(int x){
	int res = 0;
	x++;
	while(x){
		res += bit[x];
		x -= x & -x;
	}
	return res;
}

void add(int x, int v){
	_add(x, v);
	
}



int sum(int x){
	return _sum(x);
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d%d%d", &query[i].second.first, &query[i].second.second, &query[i].first.first);
		query[i].first.second = i;
		nums.push_back(query[i].second.second);
	}
	nums.push_back(-100);
	sort(nums.begin(), nums.end());
	fill(ans, ans + n, -1);
	sort(query, query + n);
	int nownum = query[0].first.first;
	for(int i = 0;i < n;i++){
		query[i].second.second = lower_bound(nums.begin(), nums.end(), query[i].second.second) - nums.begin();
		int x = query[i].first.first;
		int a = query[i].second.first;
		int t = query[i].second.second;
		int id = query[i].first.second;
		if(nownum != x){
			for(int j = i-1;j >= 0;j--){
				int tx = query[j].first.first;
				int ta = query[j].second.first;
				int tt = query[j].second.second;
				int tid = query[j].first.second;
				if(tx != nownum)break;
				if(ta == 1){
					add(tt, -1);
				}
				if(ta == 2){
					add(tt, 1);
				}
			}
		nownum = x;
		}
		
		if(a == 1){
			add(t, 1);
		}
		if(a == 2){
			add(t, -1);
		}
		if(a == 3){
			ans[id] = sum(t);
		}
	}
	for(int i = 0;i < n;i++){
		if(ans[i] >= 0)printf("%d\n", ans[i]);
	}
	return 0;
}