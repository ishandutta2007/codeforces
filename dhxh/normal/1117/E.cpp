#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int n, m, t;

string str[5];
string ans[5];

map <string, int> s;

int len[10005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j, k, l;
	
	cin >> str[0];
	
	n = str[0].length();
	
	len[0] = n;
	
	for(i=1;i<=3;i++){
		for(j=0;j<n;){
			int c = len[j] / 26;
			int tc = len[j];
			for(k=0;k<26;k++){
				if(k < tc % 26){
					t = c + 1;
				}else{
					t = c;
				}
				if(t > 0){
					len[j] = t;
				}
				for(l=1;l<=t;l++){
					str[i].push_back('a' + k);
					j++;
				}
			}
		}
		cout << "? " << str[i] << endl;
		cin >> ans[i];
	}
	
	for(i=0;i<n;i++){
		string tmp;
		tmp.push_back(ans[1][i]);
		tmp.push_back(ans[2][i]);
		tmp.push_back(ans[3][i]);
		s[tmp] = i;
	}
	
	for(i=0;i<n;i++){
		string tmp;
		tmp.push_back(str[1][i]);
		tmp.push_back(str[2][i]);
		tmp.push_back(str[3][i]);
		ans[0].push_back(str[0][s[tmp]]);
	}
	
	cout << "! " << ans[0] << endl;
	
	return 0;
}