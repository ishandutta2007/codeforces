#include<bits/stdc++.h>

using namespace std;

const int MAXN = 50;

int n = 27;
string s, a, b;
bool vis[200];
char ch;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i < n; i++){
		if (vis[s[i]])	ch = s[i];
		vis[s[i]] = 1;
	}

	int cc = 0, ind = 0;
	bool fl = 0;
	for (int i = 0; i < n; i++){
		if (fl)
			cc++;
		if (ch == s[i]){
			if (fl)
				break;
			else
				ind = i;
			fl = 1;
		}
	}
	if (cc == 1){
		cout << "Impossible\n";
		return 0;
	}
	if (cc % 2 == 0){
		for (int i = 0; i < cc/2; i++)
			a += s[ind + i];
		for (int i = cc/2; i < cc; i++)
			b = s[ind + i] + b;
		string temp;
		for (int j = ind - 1; ~j; j--){
			if (b.size() < 13)
				b = s[j] + b;
			else
				temp += s[j];
		}
		if (b.size() == 13){
			for (int j = ind + cc + 1; j < n; j++)
				a = s[j] + a;
			a = temp + a;
		}
		else{
			for (int j = ind + cc + 1; j < n; j++){
				if (a.size() < 13)
					a = s[j] + a;
				else
					temp += s[j];
			}
			b = temp + b;
		}
	}
	else{
		for (int i = 0; i < cc/2+1; i++)
			a += s[ind + i];
		for (int i = cc/2+1; i < cc; i++)
			b = s[ind + i] + b;
		string temp;
		for (int j = ind - 1; ~j; j--){
			if (a.size() < 13)
				a = s[j] + a;
			else
				temp += s[j];
		}
		if (a.size() == 13){
			for (int j = ind + cc + 1; j < n; j++)
				b = s[j] + b;
			b = temp + b;
		}
		else{
			for (int j = ind + cc + 1; j < n; j++){
				if (b.size() < 13)
					b = s[j] + b;
				else
					temp += s[j];
			}
			a = temp + a;
		}
	}
	cout << a << "\n";
	cout << b << "\n";
	return 0;
}