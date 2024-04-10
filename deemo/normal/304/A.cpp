#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

const int MAX = 1e8 + 2;

bool seen[MAX];

int main(){
	int n;	cin >> n;
	for (int i = 1; i <= n; i++)
		seen[i * i] = 1;

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++){
			if (i * i + j * j >= MAX)	break;
			if (seen[i * i + j * j])	ans++;
		}
	cout << ans << endl;
	return 0;
}