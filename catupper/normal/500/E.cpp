#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
using namespace std;

typedef pair<int, int> P;

int bit[1 << 20];

int getval(int pos){
	pos++;
	int res = 0;
	while(pos){
		res += bit[pos];
		pos -= pos & -pos;
	}
	return res;
}

void add(int pos, int val){
	pos++;
	while(pos < (1 << 20)){
		bit[pos] += val;
		pos += pos & -pos;
	}
}


int n, p[216000], l[216000];
vector<int> nums;
vector<P> query[216000];
int q, x, y;
int ans[216000];


int main(){
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> p[i] >> l[i];
		nums.push_back(p[i]);
		nums.push_back(p[i] + l[i]);
	}
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());
	for(int i = 0;i < n;i++){                                             
		l[i] = lower_bound(nums.begin(), nums.end(), p[i] + l[i]) - nums.begin();
		p[i] = lower_bound(nums.begin(), nums.end(), p[i]) - nums.begin();
		l[i] -= p[i];
	}
	set<int> nozero;
	for(int i = 0;i < nums.size();i++){
		nozero.insert(i);
		if(i + 1 != nums.size())add(i, nums[i + 1] - nums[i]);
	}
	nozero.insert(1 << 30);
	
	cin >> q;
	for(int i = 0;i < q;i++){
		cin >> x >> y;
		x--,y--;
		query[x].push_back(P(y, i));
	}
	for(int i = n - 1;i >= 0;i--){
		set<int>::iterator it = nozero.lower_bound(p[i]);
		while(*it < p[i] + l[i]){
			add(*it, -nums[(*it) + 1] + nums[*it]);			
			nozero.erase(it++);
		}
		for(int j = 0;j < query[i].size();j++){
			int to = query[i][j].first;
			int ind = query[i][j].second;
			ans[ind] = getval(p[to]) - getval(p[i]);
		}
	}
	for(int i = 0;i < q;i++){
		cout << ans[i] << endl;
	}
	return 0;
}