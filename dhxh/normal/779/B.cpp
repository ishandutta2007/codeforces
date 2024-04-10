#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string str;
int k;
int cnt = 0;
int ans = 0;
string tmp;

int main(){
	int i, j;
	
	cin >> str >> k;
	
	for(i=str.length()-1;i>=0;i--){
		if(str[i] == '0' or cnt >= k){
			cnt++;
			tmp = str[i] + tmp;
		}else{
			ans++;
		}
	}
	
	if(tmp[0] == '0'){
		ans += tmp.length() - 1;
	}
	
	cout << ans << endl;
	
	return 0;
}