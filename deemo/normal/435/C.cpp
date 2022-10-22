#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 3e3 + 20;

int n, vec[MAXN];
char ss[MAXN][MAXN];

int main(){
	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			ss[i][j] = ' ';
	cin >> n;
	int sum = 0, maxi = 0, mini = 1e9;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		if (i % 2 == 0)	sum += vec[i];
		else	sum -= vec[i];
		maxi = max(maxi, sum);
		mini = min(mini, sum);
	}

	int cur = maxi, b = 0;
	mini = maxi;
	sum = 0;
	for (int i = 0; i < n; i++){
		if (i % 2 == 0){
			sum += vec[i];
			for (int j = 0; j < vec[i]; j++)
				ss[cur--][b++] = '/';
			mini = max(mini, cur);
			cur++;
		}
		else{
			sum -= vec[i];
			for (int j = 0; j < vec[i]; j++)
				ss[cur++][b++] = '\\';
			mini = max(mini, cur);
			cur--;
		}
	}
	for (int i = 1; i <= mini; i++){
		for (int j = 0; j < b; j++)
			cout << ss[i][j];
		cout << "\n";
	}
	return	0;
}