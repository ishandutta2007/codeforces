#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, k;

string str;

int a[105];

int ans = 0;
int cnt = 0;

int main(){
	int i, j;
	
	cin >> n >> k;
	
	cin >> str;
	
	for(i=0;i<n;i++){
		a[str[i] - 'a']++;
	}
	
	for(i=0;i<26;){
		if(a[i]){
			ans += i + 1;
			cnt++;
			i += 2;
			if(cnt == k){
				break;
			}
		}else{
			i++;
		}
	}
	
	if(cnt == k){
		cout << ans << endl;
	}else{
		cout << -1 << endl;
	}
	
	return 0;
}