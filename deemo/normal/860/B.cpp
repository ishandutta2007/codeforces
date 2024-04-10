#include<iostream>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 70000 + 20;

int n;
string s[MAXN];
map<int, int> mn, mx;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s[i];
		for (int w = 0; w < 9; w++){
			int cur = 1;
			for (int j = w; j < 9; j++){
				cur = cur*10 + int(s[i][j] - '0');
				if (!mn.count(cur)) mn[cur] = i;
				mx[cur] = i;
			}
		}
	}

	for (int i = 0; i < n; i++){
		string res;
		for (int w = 0; w < 9; w++){
			int cur = 1;
			string cc;
			for (int j = w; j < 9; j++){
				cur = cur*10 + int(s[i][j] - '0');
				cc += s[i][j];

				if (mn[cur] == mx[cur] && (res.empty() || res.size() > cc.size()))
					res = cc;
			}
		}
		cout << res << "\n";
	}
	return 0;
}