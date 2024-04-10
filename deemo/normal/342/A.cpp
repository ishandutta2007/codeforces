#include<cmath>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
#include<string>

using namespace std;

int n;
int cnt[10];
vector<string>	vec;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int temp;	scanf("%d", &temp);
		if (temp == 7 || temp == 5){
			cout << -1 << endl;
			return 0;
		}

		cnt[temp]++;
	}

	int g = 0;
	g = cnt[4];
	for (int i = 0; i < g; i++){
		if (cnt[2] == 0 || cnt[1] == 0){
			cout << -1 << endl;
			return 0;
		}
		vec.push_back({"124"});
		cnt[4]--;	cnt[2]--;	cnt[1]--;
	}

	g = cnt[2];
	for (int i = 0; i < g; i++){
		if (cnt[6] == 0 || cnt[1] == 0){
			cout << -1 << endl;
			return 0;
		}
		vec.push_back("126");
		cnt[6]--;	cnt[2]--;	cnt[1]--;
	}

	g = cnt[3];
	for (int i = 0; i < g; i++){
		if (cnt[6] == 0 || cnt[1] == 0){
			cout << -1 << endl;
			return 0;
		}
		vec.push_back("136");
		cnt[6]--;	cnt[3]--;	cnt[1]--;
	}

	if (vec.size() != n/3){
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < vec.size(); i++){
		for (int j = 0; j < 3; j++)
			cout << vec[i][j] - 48 << " ";
		cout << endl;
	}
	return 0;
}