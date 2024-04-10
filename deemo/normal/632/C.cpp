#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 5e4 + 10;

int n;
string s[MAXN];

bool cmp(string a, string b){
	//int m = min(a.size(), b.size());
	//int x = max(a.size(), b.size());
	//int aa = 0, bb = 0;
	//for (int i = 0; i < x; i++)
	//	if (a[i] != b[i])	return	a[i] < b[i];
	//return	true;
	return a + b < b + a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> s[i];
	sort(s, s + n, cmp);
	for (int i = 0; i < n; i++)
		cout << s[i];
	cout << "\n";
	return	0;
}