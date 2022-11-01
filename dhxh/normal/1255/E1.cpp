#include <bits/stdc++.h>

using namespace std;

const int maxn = 200005;

int n, m, t;

int a[maxn];

long long check(int x){
	long long ret = 0;
	int s = 0, e = 0; 
	int cnt = 0;
	vector <int> vec;
	
	for(int i=1;i<=n;i++){
		if(a[i]){
			cnt++;
			vec.push_back(i);
			if(cnt == 1){
				s = i;
			}else if(cnt == x){
				for(int j=0;j<x/2;j++){
					ret += vec[x / 2] - vec[j];
				}
				for(int j=x/2+1;j<x;j++){
					ret += vec[j] - vec[x / 2];
				}
				vec.clear();
				cnt = 0;
			}
		}
	}
	
	return ret;
}

int main(){
	int i, j;
	long long cnt = 0;
	
	scanf("%d", &n);
	
	for(i=1;i<=n;i++){
		scanf("%d", &a[i]);
		cnt += a[i];
	}
	
	if(cnt == 1){
		printf("%d\n", -1);
		return 0;
	}
	
	long long ans = 1e18;
	ans = check(cnt);
	for(i=1;1ll*i*i<=cnt;i++){
		if(cnt % i == 0){
			if(i > 1)ans = min(ans, check(i));
			ans = min(ans, check(cnt / i));
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
}