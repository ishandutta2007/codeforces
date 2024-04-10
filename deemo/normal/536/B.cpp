#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

const int MOD = 1e9 + 7;
const int max_n = 1e6 + 10;

int n, m;
string s;

int z[max_n], a[max_n];
bool mark[max_n];

void init(){
	int L = 0, R = 0;
	for (int i = 1; i < s.size(); i++){
		if (R <= i){
			L = R = i;
			while (R < s.size() && s[R] == s[R - L])	R++;
			z[i] = R - L;
		}
		else{
			int k = i - L;
			if (z[k] < R - i)
				z[i] = z[k];
			else{
				L = i;
				while (R < s.size() && s[R - L] == s[R])	R++;
				z[i] = R - L;
			}
		}
	}
}

void show_Ans(){
	long long ans = 1;
	for (int i = 0; i < n; i++)
		if (mark[i] == 0)
			ans = (ans * 26) % MOD;
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	cin >> s;
	init();
	for (int i = 0; i < m; i++){
		cin >> a[i];
		a[i]--;
		if (!mark[a[i]]){
			for (int j = a[i]; j < a[i] + s.size(); j++)
				mark[j] = 1;
		}
		else{
			int t = a[i] - a[i - 1];
			if (z[t] < s.size() - t){
				cout << 0 << endl;
				return 0;
			}
			else
				for (int j = a[i - 1] + s.size(); j < a[i] + s.size(); j++)
					mark[j] = 1;
		}
	}
	show_Ans();
	return 0;
}