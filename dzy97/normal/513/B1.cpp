#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a[60];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i ++) a[i] = i;
	int maxsum = 0;
	do{
		int sum = 0;
		for(int i = 1;i <= n;i ++){
			int mx = a[i];
			for(int j = i;j <= n;j ++){
				mx = min(mx, a[j]);
				sum += mx;
			}
		}
		maxsum = max(sum, maxsum);
	}while(next_permutation(a + 1, a + n + 1));
	for(int i = 1;i <= n;i ++) a[i] = i;
	do{
		int sum = 0;
		for(int i = 1;i <= n;i ++){
			int mx = a[i];
			for(int j = i;j <= n;j ++){
				mx = min(mx, a[j]);
				sum += mx;
			}
		}
		if(sum == maxsum){
			if(-- m == 0){
				for(int j = 1;j <= n;j ++) printf("%d ", a[j]);
				return 0;
			}
		}
	}while(next_permutation(a + 1, a + n + 1));
	return 0;
}