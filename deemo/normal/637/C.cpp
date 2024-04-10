#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e3 + 10;

int n;
string s[MAXN];

int dif(int a, int b){
	int ret = 0;
	for (int i = 0; i < 6; i++)
		ret += bool(s[a][i] != s[b][i]);
	return	ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int mx = 6;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int j = 0; j < i; j++)
			mx = min(mx, (dif(i, j) - 1)/2);
	}
	cout << mx << "\n";
	return	0;	
}