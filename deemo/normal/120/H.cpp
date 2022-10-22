#include<fstream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#include<cstring>
#include<set>

using namespace std;

const int MAXN = 200 + 10;
const int MAX = 2e6;

int n;
string s[MAXN];
string save[MAX];
map<string, int>	mp;
int sz;
set<string>	st;
vector<int>	adj[MAXN];
bool mark[MAX];
int mat[MAX];

bool dfs(int v){
	if (mark[v])
		return	false;
	mark[v] = 1;
	for (int u:adj[v]){
		if (mat[u] == -1 || dfs(mat[u])){
			mat[v] = u;
			mat[u] = v;
			return	true;
		}
	}
	return	false;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin >> n;
	sz = n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		int m = s[i].size();
		st.clear();

		string temp;
		for (int a = 0; st.size() < n && a < m; a++){
			temp += s[i][a];
			st.insert(temp);
			for (int b = a + 1; st.size() < n && b < m; b++){
				temp += s[i][b];
				st.insert(temp);
				for (int c = b + 1; st.size() < n && c < m; c++){
					temp += s[i][c];
					st.insert(temp);
					for (int d = c + 1; st.size() < n && d < m; d++){
						temp += s[i][d];
						st.insert(temp);
						temp.pop_back();
					}
					temp.pop_back();
				}
				temp.pop_back();
			}
			temp.pop_back();
		}
		
		for (string t:st){
			if (mp.count(t))
				adj[i].push_back(mp[t]);
			else{
				adj[i].push_back(mp[t] = sz++);
				save[sz - 1] = t;
			}
		}
	}
	
	int ans = 0;
	memset(mat, -1, sizeof(mat));
	bool fl = 1;
	while (fl){
		memset(mark, 0, sizeof(mark));
		fl = 0;
		for (int i = 0; i < n; i++)
			if (mat[i] == -1)
				if (dfs(i)){
					fl = 1;
					ans++;
				}
	}

	if (ans < n)
		cout << -1 << endl;
	else{
		for (int i = 0; i < n; i++)
			cout << save[mat[i]] << "\n";
	}
	
	return 0;
}