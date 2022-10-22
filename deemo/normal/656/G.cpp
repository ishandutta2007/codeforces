#include<iostream>
using namespace std;
int cnt[20];
int main(){int n, m, k;cin >> n >> m >> k;while (n--){for (int j = 0; j < m; j++){char ch;	cin >> ch;	if (ch == 'Y')cnt[j]++;}}int ans = 0;
for (int j = 0; j < m; j++)ans +=cnt[j]>=k;
cout << ans;//kitten
return 0;
}