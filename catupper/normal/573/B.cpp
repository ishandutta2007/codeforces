#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>

using namespace std;

int n;
int h[108000];
int sum[108000];
int dif[108000];
int lef[108000];
int rig[108000];
int res;

int main(){
	cin >> n;
	h[0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> h[i];
	} 
	h[n+1] = 0;
	n += 2;
	for(int i = 0;i < n;i++){
		sum[i] = h[i] + i;
		dif[i] = h[i] - i;
	}
	for(int i = 0;i < n;i++){
		if(i == 0)lef[i] = dif[i];
		else lef[i] = min(lef[i-1], dif[i]);
	}
	for(int i = n-1;i >= 0;i--){
		if(i == n-1)rig[i] = sum[i];
		else rig[i] = min(rig[i+1], sum[i]);
	}
	for(int i = 0;i < n;i++){
		int p = min(lef[i] + i, rig[i] - i);
		p = min(p, h[i]);
		res = max(res, p);
	}
	cout << res << endl;
	return 0;
}