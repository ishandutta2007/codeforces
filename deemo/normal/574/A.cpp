#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<utility>

using namespace std;

int n, x;
vector<int>	vec;

int main(){
	scanf("%d%d", &n, &x);
	vec.resize(n - 1);
	for (int i = 0 ; i < n - 1 ;i++)	
		scanf("%d", &vec[i]);
	int ans =0 ;
	for (int i =0  ; i< 1000; i++){
		sort(vec.begin(), vec.end());
		if (vec.back() >= x){
			x++;
			vec.back() -= 1;
			ans++;
		}
	}
	printf("%d\n", ans);
	return	0;
}