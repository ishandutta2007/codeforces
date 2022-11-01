#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, t;

string a, b;

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> n;
	
	for(t=1;t<=n;t++){
		cin >> a >> b;
		if(a.length() > b.size()){
			cout << "NO" << endl;
			continue;
		}
		
		int flag = 0;
		string ans = "YES";
		for(i=0,j=0;j<b.length();j++){
			if(a[i] == b[j]){
				if(i + 1 < a.length() and a[i + 1] == b[j] and flag == 1){
					i++;
				}
				flag = 1;
			}else{
				if(flag == 0){
					ans = "NO";
					break;
				}else{
					i++;
					if(i < a.length() and a[i] == b[j]){
						flag = 1;
					}else{
						ans = "NO";
						break;
					}
				}
			}
		}
		
		if(i != a.length() - 1){
			ans = "NO";
		}
		
		cout << ans << endl;
	}
	
	return 0;
}