#include<iostream>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
using namespace std;
typedef pair<int, int> P;
int dpl[4320][4320];
int dpr[4320][4320];
int ls, rs;
int n, p, c, h, t, qq, a, b;
vector<P> add[21600], del[21600], query[21600];
int ans[21600];
queue<P> q;


int main(){
	cin >> n >> p;
	for(int i = 0;i < n;i++){
		cin >> c >> h >> t;
		add[t].push_back(P(c, h));
		del[t+p].push_back(P(c, h));
	}
	cin >> qq;
	for(int i = 0;i < qq;i++){
		cin >> a >> b;
		query[a].push_back(P(b, i));
	}
	for(int i = 1;i <= 20000;i++){
		for(int j = 0;j < add[i].size();j++){
			c = add[i][j].first;
			h = add[i][j].second;
			for(int k = 0;k <= 4320;k++){
				if(k - c < 0)dpr[rs + 1][k] = dpr[rs][k];
				else dpr[rs + 1][k] = max(dpr[rs][k], dpr[rs][k - c] + h);
			}
			rs++;
			q.push(P(c, h));
		}
		for(int j = 0;j < del[i].size();j++){
			if(ls == 0){
				vector<P> tmp;
				while(!q.empty()){
					tmp.push_back(q.front());q.pop();
				}
				for(int k = tmp.size() - 1;k >= 0;k--){
					c = tmp[k].first;
					h = tmp[k].second;
					for(int l = 0;l <= 4320;l++){
						if(l - c < 0)dpl[ls+1][l] = dpl[ls][l];
						else dpl[ls+1][l] = max(dpl[ls][l], dpl[ls][l-c] + h);
					}			
					ls++;
				}
				rs = 0;
			}
			ls--;
		}
		for(int j = 0;j < query[i].size();j++){
			b = query[i][j].first;
			int ind = query[i][j].second;
			int &res = ans[ind];
			for(int k = 0;k <= b;k++){
				res = max(res, dpl[ls][k] + dpr[rs][b-k]);
			}
		}
	}
	for(int i = 0;i < qq;i++){
		cout << ans[i] << endl;
	}
	return 0;
}