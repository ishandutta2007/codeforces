#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#define maxn 100009
using namespace std;
int n;
long long a[maxn];
map<long long, int>mp;
int rs[maxn];
vector<int>ans;

bool check(int x, int r){
	//cout << x << endl;
	//int r = 0;
	for(int i = 1; i < 60; i++){
		//cout << rs[i] << endl;
		
		if(x < mp[1LL << i]){
			r += mp[1LL << i] - x;
		}
		else{
			int y = mp[1LL << i];
			r -= min(r, x - y);
			x = y;
		}
		r += rs[i];
		//cout << i << " " << x << " " << r << endl;
	}
	return r <= x;
}

int main(){
	for(int i = 0; i < 60; i++)
		mp[1LL << i] = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%I64d", &a[i]);
		if(mp.count(a[i]))
			mp[a[i]]++;
	}
	for(int i = 1; i <= n; i++){
		if(!mp.count(a[i])){
			for(int j = 59; j >= 0; j--){
				if((1LL << j) < a[i]){
					rs[j]++;
					break;
				}
			}
		}
	}
	//cout << check(2) << endl;
	
	int sz = mp[1];
	for(int i = 1; i <= sz; i++){
		if(check(i, sz - i)){
			ans.push_back(i);
		}
	}
	
	sort(ans.begin(), ans.end());
	if(ans.size() == 0)
		puts("-1");
	else
		for(auto x: ans)
			printf("%d ",x);
	return 0;
}