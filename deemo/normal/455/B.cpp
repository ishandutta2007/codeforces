#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<utility>

using namespace std;

const int MAXN = 1e5 + 20;

int n, k;
int tr[MAXN][28], sz;

void insert(string t){
	int cur = 0;
	for (int i = 0; i < t.size(); i++){
		if (tr[cur][t[i] - 'a'] == 0)
			tr[cur][t[i] - 'a'] = ++sz;
		cur = tr[cur][t[i] - 'a'];
	}
}

pair<bool, bool> get(int cur = 0){
	bool win = 0, lose = 0;
	int cnt = 0;
	for (int i = 0; i < 26; i++)
		if (tr[cur][i]){
			cnt++;
			pair<bool, bool>	temp = get(tr[cur][i]);
			if (temp.first == 0)
				win = 1;
			if (temp.second == 0)
				lose = 1;
		}
	if (cnt == 0)
		return {0, 1};
	return	{win, lose};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++){
		string temp;	cin >> temp;
		insert(temp);
	}
	pair<bool, bool>	win = get();
	if (!win.first){
		cout << "Second\n";
		return 0;
	}
	if (win.second){
		cout << "First\n";
		return 0;
	}
	if (k % 2 == 1)
		cout << "First\n";
	else
		cout << "Second\n";
	return 0;
}