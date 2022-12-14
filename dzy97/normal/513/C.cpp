#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n, l[10], r[10];
typedef long double db;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i ++) scanf("%d%d", &l[i], &r[i]);
	db ret = 0;
	for(int i = 1;i <= 10000;i ++){
		for(int s = 1;s < (1 << n);s ++){
			if(__builtin_popcount(s) <= 1) continue;
			db t = 1;
			for(int k = 1;k <= n;k ++){
				if((s >> (k - 1)) & 1){
					if(!(l[k] <= i && i <= r[k])) t = 0; else t *= 1 / (db)(r[k] - l[k] + 1);
				}else{
					if(!(l[k] < i)) t = 0; else t *= (db)(min(i - 1, r[k]) - l[k] + 1) / (db)(r[k] - l[k] + 1);
				}
			}
//			if(t)cout << i <<" >< "<< " "<< t << endl;
			ret += t * i;
		}
		for(int j = 1;j <= n;j ++){
			if(r[j] < i + 1) continue;
			for(int s = 1;s < (1 << n);s ++){
				if((s >> (j - 1)) & 1) continue;
				db t = (db)(r[j] - max(i + 1, l[j]) + 1) / (db)(r[j] - l[j] + 1);
				for(int k = 1;k <= n;k ++){
					if(k == j) continue;
					if((s >> (k - 1)) & 1){
						if(!(l[k] <= i && i <= r[k])) t = 0; else t *= 1 / (db)(r[k] - l[k] + 1);
					}else{
						if(!(l[k] < i)) t = 0;
						else t *= (db)(min(i - 1, r[k]) - l[k] + 1) / (db)(r[k] - l[k] + 1);
					}
				}
//				if(t)cout << i <<" "<< j << " "<< t << endl;
				ret += t * i;
			}
		}
	}
	printf("%.10lf\n", (double)ret);
	return 0;
}