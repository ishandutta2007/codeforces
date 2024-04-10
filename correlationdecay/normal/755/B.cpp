#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
vector<string>a,b;
map<string,int>mp;
int main(){
	int n,m;
	string tmp;	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> tmp;
		a.push_back(tmp);
		mp[tmp]++;
	}
	for(int i = 1; i <= m; i++){
		cin >> tmp;
		b.push_back(tmp);
		mp[tmp]++;
	}
	int cnta = 0, cntb, cnt = 0;
	for(int i = 0; i < a.size();i++){
		if(mp[a[i]] == 2)
			cnt ++;
		else
			cnta++;
	}
	cntb = m - cnt;
	if(cnt % 2 ==0){
		if(cnta > cntb){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	else{
		if(cnta >= cntb){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}