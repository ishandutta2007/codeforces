#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int n, cnt = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++){	
		cnt += (s[i] == '0');
	}
	if(cnt * 2 == n){
		cout << 2 << endl;
		cout << s[0] << ' ';
		for (int i = 1; i < n; i++){
			cout << s[i];
		}
	}else{
		cout << 1 << endl << s;
	}
}