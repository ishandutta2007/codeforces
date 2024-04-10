#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	string s;
	cin >> s;
	int n = s.size(),ans = 0;
	for(int i = 0; i < n / 2; i++){
		if(s[i] != s[n - i - 1]){
			ans++;
		}
	}	
	if(ans == 1){
		cout << "YES";
	}else if(ans == 0 && n % 2){
		cout << "YES";
	}else{
		cout << "NO";
	}
}