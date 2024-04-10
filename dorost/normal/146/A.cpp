#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
bool lucky(string s,int n){
	for(int i = 0; i < n; i++){
		if(s[i] != '4' && s[i] != '7'){
			return false;
		}
	}
	return true;
}
int main(){
	int n,sum1 = 0, sum2 = 0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n / 2; i++){
		sum1 += s[i] - '0';
	}
	for(int i = n / 2; i < n; i++){
		sum2 += s[i] - '0';
	}
	cout << (sum1 == sum2 && lucky(s,n) ? "YES" : "NO");
}