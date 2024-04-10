//I can almost taste it!

#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int max_n = 1e3 + 10;

int n;
int a[max_n];
vector<int>	gec;
vector<pair<int, int>>	sec, vec;
bool fl;

int abs(int x){
	if (x > 0)	return	x;
	return	-x;
}

void get(int rem){
	bool flag = 1;
	for (int i = 0; i < n; i++)
		if (a[i] != i + 1){
			flag = 0;
			break;
		}	
	if (fl || flag){
		fl = 1;
		return;
	}
	if (rem == 0)	return;

	vector<int>	temp;
	for (int i = 0; i < n; i++){
		if (i == 0 || i == n - 1)
			temp.push_back(i);
		else if (abs(a[i] - a[i - 1]) != 1 || abs(a[i] - a[i + 1]) != 1)
			temp.push_back(i);
	}

	for (int i = 0; i < temp.size(); i++)
		for (int j = i + 1; j < temp.size(); j++){
			sec.push_back({temp[i], temp[j]});
			reverse(a + temp[i], a + temp[j] + 1);
			get(rem - 1);
			if (fl)	return;
			reverse(a + temp[i], a + temp[j] + 1);
			sec.pop_back();
		}
}

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	get(3);
	printf("%d\n", (int)sec.size());
	for (int i = sec.size() - 1; i >= 0; i--)
		printf("%d %d\n", sec[i].first + 1, sec[i].second + 1);
	return 0;
}