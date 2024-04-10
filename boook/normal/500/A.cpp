#include<bits/stdc++.h>
using namespace std;
int num[30005];
int main(){
	int n , m , k;
	while(scanf("%d%d" ,&n ,&m) == 2){
		queue<int> q;
		for(int i = 0; i < n - 1; i++)
			scanf("%d" ,&num[i+1]);
		int p = 1;
		while(p < m){
			p += num[p];
		}
		if(p == m) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}