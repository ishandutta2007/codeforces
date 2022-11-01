#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;

string str;

int f[maxn];
int minx[maxn];

vector <int> vec[2];

int read(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){
	int i, j;
	int x, y;
	int ans = 0;
	
	cin >> n;
	
	for(i=1;i<=n;i++){
		cin >> str;
		if(str[0] == '('){
			f[i] = minx[i] = 1;
		}else{
			f[i] = minx[i] = -1;
		}
		for(j=1;j<str.length();j++){
			if(str[j] == '('){
				f[i]++;
			}else{
				f[i]--;
				minx[i] = min(minx[i], f[i]);
			}
		}
	}
	
	for(i=1;i<=n;i++){
		if(f[i] > 0){
			if(minx[i] < 0){
				continue;
			}else{
				vec[0].push_back(f[i]);
			}
		}else if(f[i] < 0){
			if(minx[i] < f[i]){
				continue;
			}else{
				vec[1].push_back(-f[i]);
			}
		}else{
			if(minx[i] >= 0){
				ans++;
			}
		}
	}
	
	ans /= 2;
	
	sort(vec[0].begin(), vec[0].end());
	sort(vec[1].begin(), vec[1].end());
	
	i = 0, j = 0;
	
	while(i < vec[0].size() and j < vec[1].size()){
		if(vec[0][i] == vec[1][j]){
			ans++;
			i++,j++;
		}else{
			if(vec[0][i] < vec[1][j]){
				i++;
			}else{
				j++;
			}
		}
	}
	
	cout << ans << endl;
	
	return 0;
}