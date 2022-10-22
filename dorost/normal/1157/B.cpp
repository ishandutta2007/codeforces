#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[9];
	for (int i = 0; i < 9; i++) {
		cin >> a[i];
	}
	int fst = -1, lst = n;
	for (int i = 0; i < n; i++) {
		if(s[i] - '0' < a[(s[i] - '0' - 1)]){
			fst = i;
			break;
		}
	}
	for (int i = fst; i < n; i++){
		if(s[i] - '0' > a[(s[i] - '0' - 1)]){
			lst = i;
			break;
		}
	}
	if(fst == -1){
		cout << s << endl;
		return 0;
	}
	for (int i = 0; i < n; i++){
		if (i >= fst && i < lst){
			cout << a[(s[i] - '0' - 1)];
		}else{
			cout << s[i];
		}
	}
}