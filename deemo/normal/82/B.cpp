#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 200 + 3;

int n;
vector<int>	vec[MAXN * MAXN], sec;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n * (n - 1)/ 2; i++){
		int t;	cin >> t;	vec[i].resize(t);
		for (int j = 0; j < t; j++)	cin >> vec[i][j];
	}
	if (n == 2){
		cout << 1 << " " << vec[0][0] << "\n";
		cout << vec[0].size() - 1 << " ";
		for (int i = 1; i < vec[0].size(); i++)
			cout << vec[0][i] << " ";
		cout << "\n";
		return 0;
	}
	
	int x = vec[0][0];
	int ind = -1;
	for (int j = 1; ind == -1 && j < n * (n - 1)/ 2; j++)
		for (int i = 0; ind == -1 && i < vec[j].size(); i++)
			if (vec[j][i] == x)	ind = j;
				
	for (int i = 0; i < vec[0].size(); i++)
		for (int j = 0; j < vec[ind].size(); j++)
			if (vec[0][i] == vec[ind][j]){
				sec.push_back(vec[0][i]);
				break;
			}
	cout << sec.size() << " ";
	for (int u:sec)	cout << u << " ";
	cout << "\n";
	
	for (int i = 0; i < n * (n - 1)/ 2; i++){
		bool f = 0;
		for (int j = 0; j < vec[i].size(); j++)
			if (vec[i][j] == x){
				f = 1;
				break;		
			}
		if (f){
			cout << vec[i].size() - sec.size() << " ";
			for (int u:vec[i]){
				bool found = 0;
				for (int z:sec)
					if (z == u){
						found = 1;
						break;
					}
				if (!found)
					cout << u << " ";
			}
			cout << "\n";
		}
	}

	return	0;
}