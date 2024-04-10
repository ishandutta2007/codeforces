#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

string str;

string ans;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n;
	
	cin >> str;
	
	ans.push_back(str[0]);
	
	for(i=1;i<str.length();i++){
		if(ans[ans.length() - 1] == 'a' or ans[ans.length() - 1] == 'e' or ans[ans.length() - 1] == 'i' or ans[ans.length() - 1] == 'o' or ans[ans.length() - 1] == 'u' or ans[ans.length() - 1] == 'y'){
			if(str[i] == 'a' or str[i] == 'e' or str[i] == 'i' or str[i] == 'o' or str[i] == 'u' or str[i] == 'y'){
				continue;
			}
		}
		
		ans.push_back(str[i]);
	}
	
	cout << ans << endl;
	
	return 0;
}