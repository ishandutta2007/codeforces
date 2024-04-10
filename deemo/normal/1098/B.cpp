#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 3e5 + 10;

int n, m;
string s[MAXN], t[MAXN];
char ch[4] = {'A', 'C', 'G', 'T'};

int get(int a, int b, int type){
	for (int i = 0; i < n; i++) t[i] = s[i];
	int c = -1, d = -1;
	for (int i = 0; i < 4; i++)
		if (i != a && i != b){
			if (c == -1)
				c = i;
			else
				d = i;
		}

	if (type == 0){
		for (int i = 0; i < n; i++){
			int c1 = 0, c2 = 0;
			for (int j = 0; j < m; j++)
				if ((j&1) && s[i][j] != ch[c])
					c1++;
				else if (!(j&1) && s[i][j] != ch[d])
					c1++;

			swap(c, d);
			for (int j = 0; j < m; j++)
				if ((j&1) && s[i][j] != ch[c])
					c2++;
				else if (!(j&1) && s[i][j] != ch[d])
					c2++;

			if (c1 < c2)
				swap(c, d);
			for (int j = 0; j < m; j++)
				if (j&1)
					t[i][j] = ch[c];
				else
					t[i][j] = ch[d];
			swap(a, c);
			swap(b, d);
		}
	}
	else{
		for (int j = 0; j < m; j++){
			int c1 = 0, c2 = 0;
			for (int i = 0; i < n; i++)
				if ((i&1) && s[i][j] != ch[c])
					c1++;
				else if (!(i&1) && s[i][j] != ch[d])
					c1++;

			swap(c, d);
			for (int i = 0; i < n; i++)
				if ((i&1) && s[i][j] != ch[c])
					c2++;
				else if (!(i&1) && s[i][j] != ch[d])
					c2++;

			if (c1 < c2)
				swap(c, d);
			for (int i = 0; i < n; i++)
				if (i&1)
					t[i][j] = ch[c];
				else
					t[i][j] = ch[d];
			swap(a, c);
			swap(b, d);
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] != t[i][j])
				ret++;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> s[i];

	int mn = 1e9;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i != j)
				for (int w = 0; w < 2; w++)
					mn = min(mn, get(i, j, w));

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i != j)
				for (int w = 0; w < 2; w++){
					if (get(i, j, w) == mn){
						for (int i = 0; i < n; i++)
							cout << t[i] << "\n";
						return 0;
					}
				}
	return 0;
}