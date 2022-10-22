#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
#define abs(x) ((x) < 0?-(x):(x))
Int nowdif[108000];  
Int n, m;
Int a[108000];
vector<int> neib[108000];
Int res;

int main(){
	cin >> n >> m;
	for(int i = 0;i < m;i++){
		cin >> a[i];
		if(i){
			res += abs(a[i] - a[i - 1]);
			nowdif[a[i]] += abs(a[i] - a[i - 1]);
			nowdif[a[i - 1]] += abs(a[i] - a[i - 1]);
			if(a[i] != a[i - 1]){
				neib[a[i]].push_back(a[i - 1]);
				neib[a[i - 1]].push_back(a[i]);
			}
		}
	}
	for(int i = 1;i <= n;i++)sort(neib[i].begin(), neib[i].end());
	Int dec = 0;
	for(int i = 1;i <= n;i++){
		if(neib[i].empty())continue;
		int p = neib[i][neib[i].size() / 2];
		int tmp = 0;
		for(int j = 0;j < neib[i].size();j++){
			tmp += abs(p - neib[i][j]);
		}
		dec = max(dec, nowdif[i] - tmp);
	}
	cout << res - dec << endl;
	return 0;
}