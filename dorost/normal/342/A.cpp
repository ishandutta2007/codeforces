/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
/*
	Group haye gabel gabool 3 tayi :
	1 2 4
	1 2 6
	1 3 6
	Shart haye badihi :
		cnt[1] == n / 3;
		cnt[5] == 0;
		cnt[7] == 0;
		cnt[2] <= n / 3;
		cnt[3] <= n / 3;
		cnt[4] <= n / 3;
		cnt[6] <= n / 3;
		cnt[6] + cnt[4] == cnt[2] + cnt[3]; // in shart 4 ta balayi ro hichi mikone :|
	Badihi tarin Shart :
		age fagat in shart ha lazem bashe soal besyar badihi ast
*/
	int n;
	cin >> n;
	int a[n], cnt[10] = {};
	for (int i = 0; i < n; i++){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	if (cnt[1] == n / 3 && cnt[5] == 0 && cnt[7] == 0 && cnt[2] + cnt[3] == cnt[4] + cnt[6] && cnt[4] <= cnt[2]){
		for (int i = 0; i < n / 3; i++){
			cout << 1 << ' ';
			if (i < cnt[2]){
				if (i < cnt[4]){
					cout << "2 4\n";
				}else{
					cout << "2 6\n";
				}
			}else{
				cout << "3 6\n";
			}
		}
	}else{
		cout << -1;
	}
}