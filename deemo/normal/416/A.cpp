#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int INF = 2e9;

int get(int l, int r, int rem){
	if (rem == 0){
		if (r >= l)	return	l;
		return	INF + 1;
	}	
	
	string s;	int x;	char ans;	cin >> s >> x >> ans;

	if (s == ">"){
		if (ans == 'Y')
			l = max(l, x + 1);
		else
			r = min(r, x);
	}
	if (s == "<"){
		if (ans == 'Y')
			r = min(r, x - 1);
		else
			l = max(l, x);
	}
	if (s == ">="){
		if (ans == 'Y')
			l = max(l, x);
		else
			r = min(r, x - 1);
	}
	if (s == "<="){
		if (ans == 'Y')
			r = min(r, x);
		else
			l = max(l, x + 1);
	}
	return	get(l, r, rem - 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;	cin >> n;
	int ans = get(-INF, INF, n);
	if (ans != INF + 1)
		cout << ans << "\n";
	else
		cout << "Impossible\n";
	return 0;
}