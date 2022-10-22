#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<deque>
#include<utility>

using namespace std;

const int MAXN = 100 + 10;

int n, t, m;
int a[MAXN][2], b[MAXN][2];
deque<pair<pair<string, int>, int>>	q;
vector<string>	ans[MAXN];
int k[MAXN][MAXN];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> t;
	for (int i = 0; i < n; i++)
		cin >> a[i][0] >> b[i][0] >> a[i][1] >> b[i][1];
	cin >> m;
	for (int i = 0; i < m; i++){
		string temp; cin >> temp;
		int z;	cin >> z;
		q.push_back({{temp, z}, i});
	}

	int cnt = 0, tt = t;
	bool turn = 0;
	for (int i = 0; cnt < m; i++){
		if (i == n){
			i = 0;
			turn = !turn;
		}
		
		pair<string, int>	fr = q.front().first;
		int id = q.front().second;
		q.pop_front();

		int z = max(1, fr.second - (k[i][id] + a[i][turn] + b[i][!turn]));
		if (t < z){
			k[i][id] += t;
			q.push_back({fr, id});
			t = tt;
		}
		else{
			cnt++;
			ans[i].push_back(fr.first);
			t -= z;
			if (t == 0){
				t = tt;
				continue;
			}
			i--;
		}
	}

	for (int i = 0; i < n; i++){
		cout << ans[i].size() << " ";
		for (string ss:ans[i])
			cout << ss << " ";
		cout << "\n";
	}

	return 0;
}