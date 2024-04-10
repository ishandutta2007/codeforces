#include <algorithm>
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int a[200005], b[200005];
map <int, int> mp;
bool flagl[200005], flagr[200005];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	if (n == 2 || n == 3){
		cout << 1 << endl;
		return 0;
	}
	for (int i = 1; i <= n; ++ i)
		mp[a[i]] = i;
	sort(a + 1, a + 1 + n);
	for (int i = 1; i < n; ++ i)
		b[i] = a[i + 1] - a[i];
	bool flag1 = false, flagn = false;
	for (int i = 3; i <= n - 1; ++ i)
		if (b[i] != b[i - 1])
			flag1 = true;
	for (int i = 2; i <= n - 2; ++ i)
		if (b[i] != b[i - 1])
			flagn = true;
	for (int i = 2; i < n; ++ i)
		flagl[i] = flagl[i - 1] || b[i] != b[i - 1];
	for (int i = n - 2; i; -- i)
		flagr[i] = flagr[i + 1] || b[i] != b[i + 1];
	if (! flag1){
		cout << mp[a[1]] << endl;
		return 0;
	}
	if (! flagn){
		cout << mp[a[n]] << endl;
		return 0;
	}
	for (int i = 3; i <= n - 1; ++ i)
		if (flagl[i - 2] == false && flagr[i + 1] == false && b[i - 1] + b[i] == b[i - 2]){
			cout << mp[a[i]] << endl;
			return 0;
		}
	if (flagr[3] == false && b[1] + b[2] == b[3]){
		cout << mp[a[2]] << endl;
		return 0;
	}
	cout << -1 << endl;
}