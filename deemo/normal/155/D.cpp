#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e5 + 10;

int n, q, us[MAXN];
bool col[MAXN];
vector<int>	ls[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q;
	for (int i = 2; i <= n; i++)
		if (ls[i].empty())
			for (int j = i; j <= n; j += i)
				ls[j].push_back(i);
	
	while (q--){
		char type;
		int v;	cin >> type >> v;
		if (type == '+'){
			if (col[v])
				cout << "Already on\n";
			else{
				int ind = 0;
				for (int u:ls[v])
					if (us[u]){
						ind = us[u];
						break;
					}

				if (ind)
					cout << "Conflict with " << ind << "\n";
				else{
					cout << "Success\n";
					for (int u:ls[v])
						us[u] = v;
					col[v] = 1;
				}
			}
		}
		else{
			if (!col[v])
				cout << "Already off\n";
			else{
				cout << "Success\n";
				for (int u:ls[v])
					us[u] = 0;
			}
			col[v] = 0;
		}
	}
	return	0;
}