#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

typedef long long ll;

int n;
string s, ans;

bool solve(int l, int r, int type){
	if (l == r){
		int z = bool(type == 1 || type == 3);
		int y = s[l] - '0' - z;
		if (y % 2 == 0){
			if (type < 2)
				ans[l] = y/2 + '0';
			else
				ans[l] = y/2 + 5 + '0';
			return	true;
		}
		return	false;
	}

	if (l + 1 == r){
		if (type == 0){
			if (s[l] == s[r]){
				ans[l] = s[l];
				ans[r] = '0';
				return	true;
			}
			return	false;
		}
		if (type == 1){
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					if ((i + j + 1) % 10 + '0' == s[r] && (i + j + bool(i + j + 1 >= 10)) + '0' == s[l]){
						ans[r] = j + '0';
						ans[l] = i + '0';
						return	true;
					}
			return	false;
		}
		if (type == 2){
			for (int i = 0; i < 10; i++)
				for (int j = 0; j < 10; j++)
					if ((i + j) % 10 + '0' == s[r] && (i + j + bool(i + j >= 10)) - 10 + '0' == s[l]){
						ans[r] = i + '0';
						ans[l] = j + '0';
						return	true;
					}
			return	false;
		}
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 10; j++)
				if ((i + j + 1) % 10 + '0' == s[r] && (i + j + bool(i + j + 1 >= 10)) - 10 + '0' == s[l]){
					ans[r] = i + '0';
					ans[l] = j + '0';
					return	true;
				}
		return	false;
	}

	for (int j = 0; j < 10; j++)
		for (int i = 0; i < 10; i++){
			if (type == 0){
				if (s[l] == s[r]){
					ans[l] = s[l];
					ans[r] = '0';
					return	solve(l + 1, r - 1, 0);
				}
				else if (i + j + '0' == s[r] && i + j + 1 + '0' == s[l]){
					if (i != 0 || ((l != 0 || r != n - 1) && (l != 1 || r != n - 1))){
						ans[l] = i + '0';
						ans[r] = j + '0';
						return	solve(l + 1, r - 1, 2);
					}
				}
			}
			if (type == 1)
				if (i + j <= 9 && (i + j + 1) % 10 + '0' == s[r]){
					ans[r] = j + '0';
					ans[l] = i + '0';
					if ((i + j) + '0' == s[l])
						return	solve(l + 1, r - 1, bool(i + j + 1 >= 10));
					if ((i + j + 1) + '0' == s[l])
						return	solve(l + 1, r - 1, i + j + 1 >= 10?3:2);
					return	false;
				}
			if (type == 2){
				if (s[r] == '9'){
					if (i + j < 10 && (i + j) % 10 + '0' == s[r]){
						ans[r] = j + '0';
						ans[l] = i + '0';
						if (s[l] == '0')
							return	solve(l + 1, r - 1, 2);
						return	false;
					}
				}
				else{
					if (i + j >= 10 && (i + j) % 10 + '0' == s[r]){
						ans[r] = j + '0';
						ans[l] = i + '0';
						if ((i + j) % 10 + '0' == s[l])
							return	solve(l + 1, r - 1, 1);
						if ((i + j + 1) % 10 + '0' == s[l])
							return	solve(l + 1, r - 1, 3);
						return	false;
					}
				}
			}
			if (type == 3){
				if (s[r] == '9'){
					if (i + j >= 10 && (i + j + 1) % 10 + '0' == s[r]){
						ans[r] = j + '0';
						ans[l] = i + '0';
						if ((i + j) % 10 + '0'== s[l])
							return	solve(l + 1, r - 1, 1);
						if ((i + j + 1) % 10 + '0' == s[l])
							return	solve(l + 1, r - 1, 3);
						return	false;
					}
				}
				else if (s[r] == '0'){
					if (i + j == 9){
						ans[r] = j + '0';
						ans[l] = i + '0';
						if (s[l] == '0')
							return	solve(l + 1, r - 1, 3);
						return	false;
					}
				}
				else{
					if (i + j >= 10 && (i + j + 1) % 10 + '0' == s[r]){
						ans[r] = j + '0';
						ans[l] = i + '0';
						if ((i + j) % 10 + '0' == s[l])
							return	solve(l + 1, r - 1, 1);
						if ((i + j + 1) % 10 + '0' == s[l])
							return	solve(l + 1, r - 1, 3);
						return	false;
					}
				}
			}
		}
	return	false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	n = s.size();	ans.resize(n);
	if (solve(0, n - 1, 0)){
		for (int i = 0; i < n; i++)
			cout << ans[i];
		cout << "\n";
	}
	else if (s[0] == '1' && solve(1, n - 1, 2)){
		for (int i = 1; i < n; i++)
			cout << ans[i];
		cout << "\n";
	}
	else	cout << 0 << "\n";
	return	0;
}