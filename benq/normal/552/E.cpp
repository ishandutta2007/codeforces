#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
ll curval, ans;
string s;
vi di, op;

ll eval2(int a, int b) {
	ll sum = 0, cur = di[a];
	FOR(i,a,b) {
		if (op[i] == 0) sum += cur, cur = di[i+1];
		else cur *= di[i+1];
	}
	sum += cur;
	return sum;
}

ll eval (int a, int b) {
	ll sum = 0, cur, i = 0;
	if (a != 0) cur = di[0];
	else cur = eval2(a,b), i = b;
	for (;i<op.size();++i) {
		if (i == a-1) {
			if (op[i] == 0) sum += cur, cur = eval2(a,b);
			else cur *= eval2(a,b);
			i = b-1;
		} else {
			if (op[i] == 0) sum += cur, cur = di[i+1];
			else cur *= di[i+1];
		}
	}
	sum += cur;
	return sum;
}

int main() {
	cin >> s;
	F0R(i,s.length()) {
		if (i % 2 == 0) di.pb(int(s[i]-'0'));
		else {
			if (s[i] == '+') op.pb(0);
			else op.pb(1);
		}
	}
	F0R(i,di.size()) FOR(j,i+1,di.size()) {
		if ((i > 0 && op[i-1] == 1) || (j < di.size()-1 && op[j] == 1)) {
			// cout << i << " " << j << " " << eval(i,j) << endl;
			ans = max(ans,eval(i,j));
		}
	}
	ans = max(ans,eval(0,0));
	cout << ans;
	return 0;
}