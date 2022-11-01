#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

string str[105];
int n;

bool cmp(string x, string y){
	return x.length() < y.length();
}

int main(){
	int i, j;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> str[i];
	}
	
	sort(str + 1, str + n + 1, cmp);
	
	for(i=2;i<=n;i++){
		if(str[i].find(str[i - 1]) == -1){
			cout << "NO" << endl;
			return 0;
		}
	}
	
	cout << "YES" << endl;
	
	for(i=1;i<=n;i++){
		cout << str[i] << endl;
	}
	
	
	
	return 0;
}