#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, k, pos1;
bool fl;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	{
		int l = 0, r = n;
		while (r-l>1){
			int ln = r-l;
			int y = r-ln/2;
			int x = y-1;
			cout << 1 << " " << x+1 << " " << y+1 << endl;
			cin >> s;
			if (s[0] == 'T')
				fl = 1;
			else
				fl = 0;

			if (fl)
				r = x+1;
			else
				l = y;
		}
		pos1 = l;
	}

	if (pos1 + 1 < n){
		int l = pos1+1, r = n;
		while (r-l>1){
			int ln = r-l;
			int y = r-ln/2;
			int x = y-1;
			cout << 1 << " " << x+1 << " " << y+1 << endl;
			cin >> s;
			if (s[0] == 'T')
				fl = 1;
			else
				fl = 0;

			if (fl)
				r = x+1;
			else
				l = y;
		}
		cout << 1 << " " << l+1 << " " << pos1+1 << endl;
		cin >> s;
		if (s[0] == 'T'){
			cout << 2 << " " << pos1+1 << " " << l+1 << endl;
			return 0;
		}
	}

	int l = 0, r = pos1;
	while (r-l>1){
		int ln = r-l;
		int y = r-ln/2;
		int x = y-1;
		cout << 1 << " " << x+1 << " " << y+1 << endl;
		cin >> s;
		if (s[0] == 'T')
			fl = 1;
		else
			fl = 0;

		if (fl)
			r = x+1;
		else
			l = y;
	}
	cout << 2 << " " << l+1 << " " << pos1+1 << endl;
	return 0;
}