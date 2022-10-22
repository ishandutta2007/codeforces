#include<fstream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAX = 5e3 + 100;

vector<int>	vec[MAX];

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int n;	cin >> n;
	for (int i = 1; i <= 2 * n; i++){
		int a;	cin >> a;
		vec[a].push_back(i);
	}

	bool fl = 0;
	for (int i = 0; i < MAX; i++)
		if ((int)vec[i].size() % 2 == 1)	fl = 1;
	if (fl)
		cout << -1 << endl;
	else
		for (int i = 0; i <MAX; i++){
			while ((int)vec[i].size()){
				cout << vec[i].back() << " ";
				vec[i].pop_back();
				cout << vec[i].back() << "\n";
				vec[i].pop_back();
			}
		}
	return 0;
}