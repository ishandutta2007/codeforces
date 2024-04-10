#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string ans;
string str;

int n;
int cnt;

int main(){
	int i, j;
	int x;
	
	cin >> n;
	
	cin >> str;
	
	for(i=0;i<str.length();i++){
		ans.push_back('-');
	}
	
	for(i=0;i<str.length();i++){
		for(j=0;j<ans.length();j++){
			if(ans[j] == '-'){
				cnt++;
			}
			if(cnt * 2 >= n){
				ans[j] = str[i];
				n--;
				cnt = 0;
				break;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}