#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>

using namespace std;

map<pair<int, int>, int>	mp;

pair<int, int>	get(int a, int b){
	if (a > b)	swap(a, b);
	return	{a, b};
}	

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		mp.clear();
		int n, p;	cin >> n >> p;
		for (int i = 0; i < n; i++){
			cout << i + 1 << " " << ((i + 1) % n) + 1 << "\n";
			cout << i + 1 << " " << ((i + 2) % n) + 1 << "\n";
			mp[get(i, (i + 1) % n)] = 1;
			mp[get(i, (i + 2) % n)] = 1;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (p && mp[get(i, j)] == 0 && i != j){
					p--;
					mp[get(i, j)] = 1;
					cout << i + 1 << " " << j + 1 << "\n";
				}
	}
	return	0;
}