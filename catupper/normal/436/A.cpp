#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long Int;
typedef pair<int, int> P;

bool used[2160];
vector<P> candy[2];
int n, x, t, h, m;

int check(int t){
	fill(used, used + 2160, false);
	int res = 0;
	int jump = x;
	while(true){
		int next = -1;
		for(int i = 0;i < candy[t].size();i++){
			if(used[t * candy[0].size() + i])continue;
			if(candy[t][i].first > jump)continue;
			if(next == -1 || candy[t][next].second < candy[t][i].second){
				next = i;
			} 
		}
		if(next == -1)break;
		res++;
		jump += candy[t][next].second;
		used[t * candy[0].size() + next] = true;
		t ^= 1;
	}	
	return res;
}

int main(){
	cin >> n >> x;
	for(int i = 0;i < n;i++){
		cin >> t >> h >> m;
		candy[t].push_back(P(h, m));
	}
	cout << max(check(1), check(0)) << endl;
	return 0;
}