#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 1e5 + 10;

int n, k, vec[MAXN];
string s;
int cnt[200];

bool cmp(char a, char b){
	if (cnt[a] != cnt[b])
		return	cnt[a] > cnt[b];
	return	a < b;
}

int main(){
	cin >> n >> k;
	cin >> s;
	for (char ch:s)
		cnt[ch]++;
	sort(s.begin(), s.end(), cmp);

	string t = "";
	for (int i = 0; i < k; i++)
		t += s[i];
	fill(cnt, cnt + 200, 0);
	for (char ch:t)
		cnt[ch]++;
	ll sum = 0;
	for (int i = 0; i < k; i++)
		sum += cnt[t[i]];
	cout << sum << endl;
	return	0;
}