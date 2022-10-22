#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e3 + 10;

int n, sec[MAXN * 4], sz;
string s, t;

void f(int x){
	if (!x) return;
	sec[sz++] = x;
	string temp = s.substr(n - x);
	s.erase(n-x, n);
	reverse(temp.begin(), temp.end());
	s = temp + s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s >> t;
	{
		string _s = s;
		string _t = t;
		sort(_s.begin(), _s.end());
		sort(_t.begin(), _t.end());
		if (_s != _t){
			cout << "-1\n";
			return 0;
		}
	}

	int l = n/ 2;
	int r = l+1;
	for (int i = 0; i < n; i++)
		if (s[i] == t[l]){
			f(n-i - 1);
			f(1);
			break;
		}
	for (int w = 0; w < n-1; w++) {
		char ch;
		if (!(w&1))
			ch = t[l - 1];
		else
			ch = t[r];
		
		int ind = -1;
		for (int i = r - l; i < n; i++)
			if (s[i] == ch){
				ind = i;
				break;
			}

		f(n - ind);
		f(n - (n - ind) - (r - l));
		f(r - l + 1);
		if (!(w&1))
			l--;
		else
			r++;
	}
	if (s != t)
		f(n);

	cout << sz << "\n";
	for (int i = 0; i < sz; i++)
		cout << sec[i] << " ";
	cout << "\n";
	return 0;
}