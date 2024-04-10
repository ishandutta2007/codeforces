#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5 + 5;
const int mod = 998244353;

int n, m;

string str;
string ans, a, b;

int main(){
	int i, j;
	int x, y;
	
	cin >> str;
	
	n = str.length();
	str = '0' + str;
	m = n / 2;
	
	for(i=1;i+1<=m;i+=2){
		if(str[i] == str[n - i + 1]){
			a.push_back(str[i]);
		}else if(str[i] == str[n - i]){
			a.push_back(str[i]);
		}else{
			a.push_back(str[i + 1]);
		}
	}
	
	b = a;
	reverse(b.begin(), b.end());
	
	if(m & 1){
		ans = a;
		ans.push_back(str[m]);
		ans = ans + b;
	}else{
		ans = a + b;
	}
	
	cout << ans << endl;
	
	return 0;
}