#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<string>

using namespace std;

const int max_n = 1e6 + 10;

struct Thing{
	int maxi, l, r;
	Thing(int a, int b, int c): maxi(a), l(b), r(c){}
};

string s;
int n, q;
int maxi[6 * max_n], first[6 * max_n], second[6 * max_n];

void init(int v, int b, int e){
	if (b == e){
		if (s[b] == '(')	first[v] = 1;
		else	second[v] = 1;
		return;
	}
	int mid = (b + e)/ 2;
	init(v<<1, b, mid);
	init(v<<1^1, mid + 1, e);
	int t = min(first[v<<1], second[v<<1^1]);
	maxi[v] = maxi[v<<1] + maxi[v<<1^1] + t*2;
	first[v] = first[v<<1^1] + (first[v<<1] - t);
	second[v] = second[v<<1] + (second[v<<1^1] - t);
}

Thing get(int v, int b, int e, int l, int r){
	if (l > e || r < b)	return Thing(-1, -1, -1);
	if (l <= b && e <= r)	return	Thing(maxi[v], first[v], second[v]);
	int mid = (b + e) / 2;
	Thing a = get(v<<1, b, mid, l, r);
	Thing f = get(v<<1^1, mid + 1, e, l, r);
	if (a.maxi == -1)	return	f;
	if (f.maxi == -1)	return	a;
	int t = min(a.l, f.r);
	a.maxi = a.maxi + f.maxi + 2 * t;
	a.l = f.l + (a.l - t);
	a.r = a.r + (f.r - t);
	return	a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = s.size();
	init(1, 0, n - 1);
	cin >> q;
	while (q--){
		int l, r;	cin >> l >> r;	l--, r--;
		cout << get(1, 0, n - 1, l, r).maxi << "\n";
	}
	return 0;
}