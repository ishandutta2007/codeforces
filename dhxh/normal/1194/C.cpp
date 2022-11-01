#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int n, m, T;

string s, t, p;

int cnt[205];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	
	cin >> T;
	
	while(T--){
		cin >> s >> t >> p;
		
		memset(cnt, 0, sizeof(cnt));
		
		for(i=0;i<p.length();i++){
			if(cnt[p[i]]++);
		}
		
		bool flag = true;
		
		for(i=0,j=0;i<t.length();i++){
			if(j < s.length() and t[i] == s[j]){
				j++;
			}else{
				if(cnt[t[i]]){
					cnt[t[i]]--;
				}else{
					flag = false;
					break;
				}
			}
		}
		
		if(j != s.length()){
			flag = false;
		}
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	
	return 0;
}