#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n;

string str[500005];

int main(){
	std::ios::sync_with_stdio(false);
	
	int i, j;
	int l;
	string tmp;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> str[i];
	}
	
	for(i=n-1;i>0;i--){
		l = min(str[i].length(), str[i + 1].length());
		tmp = "#";
		for(j=1;j<l;j++){
			if(str[i][j] > str[i + 1][j]){
				break;
			}else if(str[i][j] == str[i + 1][j]){
				tmp.push_back(str[i][j]);
			}else{
				tmp = str[i];
				break;
			}
		}
		str[i] = tmp;
	}
	
	for(i=1;i<=n;i++){
		cout << str[i] << endl;
	}
	
	return 0;
}