#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

string a,b;
char mix[1024]={0};

int main() {
	ios::sync_with_stdio(0); cin.tie();
	cin >> a >> b;
	int n = a.size();
	for(int i = 0; i < n; ++i) {
		if(a[i] == b[i]) {
			if((mix[a[i]]==0 && mix[b[i]]==0) || mix[a[i]] == a[i]) {
				mix[a[i]] = a[i];
			} else {
				cout << "-1\n";
				return 0;
			}
		} else {
			if((mix[a[i]]==0 && mix[b[i]]==0) || (mix[a[i]] == b[i] && mix[b[i]] == a[i])) {
				mix[a[i]] = b[i];
				mix[b[i]] = a[i];
			} else {
				cout << "-1\n";
				return 0;
			}
		}
	}
	int cnt = 0;
	for(int c = 'a'; c <= 'z'; ++c)
		cnt += mix[c]!=0 && mix[c]!=c;
	cout << cnt/2 << "\n";
	for(int c = 'a'; c <= 'z'; ++c) {
		if(mix[c] != 0 && mix[c] != c) {
			cout << char(c) << " " << char(mix[c]) << "\n";
			mix[mix[c]] = 0;
		}
	}
	return 0;
}