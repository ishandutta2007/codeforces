#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

string mp[6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int ans[MAXN], n, rem[10];
int a[MAXN], b[MAXN];

int find(string s){
	for (int i = 0; i < 6; i++)
		if (mp[i] == s)	return i;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 6; i++)	cin >> rem[i];
	cin >> n;
	for (int i = 0; i < n; i++){
		string s, t;	cin >> s;
		a[i] = b[i] = -1;
		for (int j = 0; j < s.size(); j++){
			if (s[j] == ','){
				a[i] = find(t);
				t = "";
			}
			else
				t += s[j];
		}
		if (a[i] == -1)
			a[i] = find(t);
		else
			b[i] = find(t);
	}

	memset(ans, -1, sizeof(ans));
	for (int i = 0; i < n; i++)
		if (b[i] == -1){
			rem[a[i]]--;
			ans[i] = a[i];
			if (rem[a[i]] < 0){
				cout << "NO\n";
				return 0;
			}
		}
	for (int i = 0; i < n; i++)
		if (ans[i] == -1 && a[i] == 0){
			if (rem[a[i]])
				rem[a[i]]--, ans[i] = a[i];
			else
				rem[b[i]]--, ans[i] = b[i];
			if (rem[b[i]] < 0){
				cout << "NO\n";
				return 0;
			}
		}
	for (int i = 0; i < n; i++)
		if (ans[i] == -1 && a[i] == 1){
			if (rem[a[i]])
				rem[a[i]]--, ans[i] = a[i];
			else
				rem[b[i]]--, ans[i] = b[i];
			if (rem[b[i]] < 0){
				cout << "NO\n";
				return 0;
			}
		}
	for (int i = 0; i < n; i++)
		if (ans[i] == -1 && a[i] == 2){
			if (rem[a[i]])
				rem[a[i]]--, ans[i] = a[i];
			else
				rem[b[i]]--, ans[i] = b[i];
			if (rem[b[i]] < 0){
				cout << "NO\n";
				return 0;
			}
		}
	for (int i = 0; i < n; i++)
		if (ans[i] == -1 && a[i] == 3){
			if (rem[a[i]])
				rem[a[i]]--, ans[i] = a[i];
			else
				rem[b[i]]--, ans[i] = b[i];
			if (rem[b[i]] < 0){
				cout << "NO\n";
				return 0;
			}
		}
	for (int i = 0; i < n; i++)
		if (ans[i] == -1 && a[i] == 4){
			if (rem[a[i]])
				rem[a[i]]--, ans[i] = a[i];
			else
				rem[b[i]]--, ans[i] = b[i];
			if (rem[b[i]] < 0){
				cout << "NO\n";
				return 0;
			}
		}

	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << mp[ans[i]] << "\n";
	return 0;
}