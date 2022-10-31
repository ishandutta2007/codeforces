#include <iostream>
using namespace std;
int a[1003], cnt[1003];
int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++ i){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	int c = 0;
	for (int i = 1; i <= n; ++ i)
		if (cnt[a[i]] == 1)
			++ c;
	if (c % 2 == 0){
		cout << "YES" <<endl;
		c /= 2;
		for (int i = 1; i <= n; ++ i){
			if (cnt[a[i]] > 1)
				cout << "A";
			else if (cnt[a[i]] == 1 && c)
				cout << "A", -- c;
			else
				cout << "B";
		}
	}
	else{
		int flag = -1;
		for (int i = 1; i <= n; ++ i)
			if (cnt[a[i]] > 2)
				flag = i;
		if (flag == -1){
			cout << "NO" << endl;
			return 0;
		}
		c /= 2;
		cout << "YES" <<endl;
		for (int i = 1; i <= n; ++ i){
			if (cnt[a[i]] == cnt[a[flag]]){
				cout << "A";
				flag = 0;
			}
			else if (cnt[a[i]] == 1 && c){
				cout << "A";
				-- c;
			}
			else
				cout << "B";
		}
	}
}