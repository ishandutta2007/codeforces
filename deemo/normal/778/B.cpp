#include<bits/stdc++.h>

using namespace std;

const int MAXN = 5e3 + 10;

int n, m, aa[MAXN], bb[MAXN], op[MAXN];
string name[MAXN], s[MAXN];
map<string, int> mp;

int get(int ind, int x){
	int ret = 0;
	for (int i = 0; i < n; i++){
		if (op[i] == -1){
			if (s[i][ind] == '1')
				ret++;
		}
		else{
			int a, b;
			if (aa[i] != -1)
				a = s[aa[i]][ind] - '0';
			else
				a = x;
			if (bb[i] != -1)
				b = s[bb[i]][ind] - '0';
			else
				b = x;

			if (op[i] == 0)
				a ^= b;
			else if (op[i] == 1)
				a |= b;
			else
				a &= b;

			s[i][ind] = char(a + '0');
			ret += a;
		}
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(op, -1, sizeof(op));
	for (int i = 0; i < n; i++){
		cin >> name[i]; mp[name[i]] = i;
		string temp;	cin >> temp;
		cin >> temp;
		if (temp[0] != '0' && temp[0] != '1'){
			if (temp[0] == '?')
				aa[i] = -1;
			else
				aa[i] = mp[temp];
			cin >> temp;
			if (temp[0] == 'X') op[i] = 0;
			else if (temp[0] == 'O') op[i] = 1;
			else if (temp[0] == 'A') op[i] = 2;
			cin >> temp;
			if (temp[0] == '?')
				bb[i] = -1;
			else
				bb[i] = mp[temp];
			s[i].resize(m);
		}
		else
			s[i] = temp;
	}

	string mn, mx;
	for (int i = 0; i < m; i++){
		int ta = get(i, 0), tb = get(i, 1);
		if (ta <= tb)
			mn += '0';
		else
			mn += '1';

		if (ta >= tb)
			mx += '0';
		else
			mx += '1'; 
	}
	cout << mn << "\n" << mx << "\n";
	return 0;
}