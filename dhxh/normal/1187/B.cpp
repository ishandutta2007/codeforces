#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 2e5 + 5;

int n, m, t;

string str;
string que;

int cnt[maxn][30];

int c[30];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

bool check(int x){
	int i, j;
	
	for(i=0;i<26;i++){
		if(cnt[x][i] < c[i]){
			return false;
		}
	}
	
	return true;
}

int main(){
	int i, j;
	
	cin >> n;
	cin >> str;
	cin >> m;
	
	str = '0' + str;
	
	for(i=1;i<=n;i++){
		for(j=0;j<26;j++){
			cnt[i][j] = cnt[i - 1][j];
		}
		cnt[i][str[i] - 'a']++;
	}
	
	for(i=1;i<=m;i++){
		cin >> que;
		int l = 1, r = n;
		memset(c, 0, sizeof(c));
		for(j=0;j<que.length();j++){
			c[que[j] - 'a']++;
		}
		
		while(l < r){
			int mid = (l + r) / 2;
			if(!check(mid)){
				l = mid + 1;
			}else{
				r = mid;
			}
		}
		
		cout << l << endl;
	}
	
	return 0;
}