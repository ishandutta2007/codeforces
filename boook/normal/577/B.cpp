#include <bits/stdc++.h>
using namespace std;
#define MAX 2010
int use[MAX];
int main(){
	int n , m , q;
	scanf("%d %d" , &n , &m);
	if(n >= m) return 0 * puts("YES");
	use[0] = 1;
	for(int i = 0 ; i < n ; i ++){
		scanf("%d" , &q);
		q %= m;
		for(int j = m ; j >= 0 ; j --){
			if(use[j]) use[j + q] ++;
			if(use[0] > 1) return 0 * puts("YES");
		}
		for(int j = m ; j <= m * 2 ; j ++) use[j - m] += use[j];
		if(use[0] > 1) return 0 * puts("YES");
		use[q] ++;
	}
	puts("NO");
    return 0;
}