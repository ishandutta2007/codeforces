#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

ll c[MAXN];
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	for (ll i = 1; i < MAXN; i++)
		c[i] = i*(i-1)/2;

	int rem;	cin >> rem;
	if (rem == 0){
		cout << "z\n";
		return 0;
	}
	for (char ch = 'a'; rem; ch++){
		int cur = 2;
		while (c[cur+1] <= rem) cur++;

		rem -= c[cur];
		while (cur--)
			s += ch;
	}
	cout << s << "\n";
	return 0;
}