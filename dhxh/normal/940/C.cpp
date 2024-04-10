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

bool vis[1005];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	char maxx = 'a', minx = 'z';
	
	cin >> n >> m;
	
	cin >> str;
	
	for(i=0;i<n;i++){
		maxx = max(maxx, str[i]);
		minx = min(minx, str[i]);
		vis[str[i]] = true;
	}
	
	if(m > n){
		ans = str;
		for(i=n+1;i<=m;i++){
			ans.push_back(minx);
		}
	}else{
		ans = str.substr(0, m);
		for(i=m-1;i>=0;i--){
			if(maxx > ans[i]){
				break;
			}
		}
		
		for(j=ans[i]+1;j<='z';j++){
			if(vis[j]){
				ans[i] = j;
				break;
			}
		}
		
		for(i++;i<m;i++){
			ans[i] = minx;
		}
	}
	
	cout << ans << endl;
	
	return 0;
}