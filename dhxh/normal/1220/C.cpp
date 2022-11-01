#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

string str;

bool f[30];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> str;
	n = str.length();
	str = '0' + str;
	
	for(i=1;i<=n;i++){
		bool flag = false;
		for(j=0;j<str[i]-'a';j++){
			if(f[j]){
				flag = true;
				break;
			}
		}
		if(flag){
			cout << "Ann" << endl;
		}else{
			cout << "Mike" << endl;
		}
		f[str[i] - 'a'] = true;
	}
	
	return 0;
}