#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 100 + 10;

int n, pos;
bool pic[MAXN * 5];

int main(){
	cin >> n >> pos, pos--;	pos += 2 * MAXN;
	for (int i = 2 * MAXN; i < 2 * MAXN + n; i++)	cin >> pic[i];
	int ans = 0;
	if (pic[pos])	ans++;
	for (int i = 1; i < MAXN; i++){
		int cnt = int(pic[pos - i]) + int(pic[pos + i]);	
		if (cnt == 2)
			ans += 2;
		else if (pos + i >= 2 * MAXN + n || pos - i < 2 * MAXN)
			ans += cnt;
	}
	cout << ans << endl;
	return 0;
}