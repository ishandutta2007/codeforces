#include<fstream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

#define Friend pair<pair<int, int>, pair<int, int>>
#define food second.first
#define id second.second
#define left first.first
#define right first.second

const int MAXN = 400 + 10;
const int INF = 1e9 + 2;

int n, v, m, sec[3 * MAXN], d[3 * MAXN][3 * MAXN], maxi[3 * MAXN][3 * MAXN];
Friend vec[3 * MAXN];
vector<pair<int, int>>	day[3 * MAXN];

bool cmp(Friend a, Friend b){return	a.food < b.food;}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n >> v;
	for (int i = 0; i < n; i++)	cin >> sec[i];
	cin >> m;
	for (int i = 0; i < m; i++){
		cin >> vec[i].left >> vec[i].right >> vec[i].food;
		vec[i].left--;
		vec[i].id = i;
	}
	sort(vec, vec + m, cmp);
	for (int i = 0; i < m; i++)
		for (int j = vec[i].left; j < vec[i].right; j++)
			day[j].push_back({vec[i].food, vec[i].id});

	for (int i = n - 1; i >= 0; i--)
		for (int j = 0; j < MAXN; j++){
			if (sec[i] + j < v){
				d[i][j] = -INF;
				continue;
			}	

			int ret = 0, temp = min(j, v), sum = v;
			if (temp == v)
				d[i][j] = d[i + 1][sec[i]];
			else
				d[i][j] = d[i + 1][j + sec[i] - v];

			for (int k = 0; k < (int)day[i].size(); k++){
				sum += day[i][k].first;
				if (sum > j + sec[i])	break;

				int z;
				temp = min(sum, j);
				if (temp == sum)	
					z = sec[i];
				else
					z = sec[i] + j - sum;
				if (d[i][j] < d[i + 1][z] + k + 1){
					ret = k + 1;
					d[i][j] = d[i + 1][z] + k + 1;
				}
			}

			maxi[i][j] = ret;
		}

	cout << d[0][0] << "\n";
	int last = 0;
	for (int i = 0; i < n; i++){
		int k = maxi[i][last];
		cout << k << " ";
		int nxt = last + sec[i] - v;
		for (int j = 0; j < k; j++){
			cout << day[i][j].second + 1 << " ";
			nxt -= day[i][j].first;
		}
		cout << "\n";
		if (nxt > sec[i])	nxt = sec[i];
		last = nxt;
	}
	return 0;
}