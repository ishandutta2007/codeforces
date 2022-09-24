#include <bits/stdc++.h>

using namespace std;

vector <int> V;
int n, d, h, t;

int main()
{
	int i, k, prev;
	
	scanf("%d%d%d", &n, &d, &h);
	
	if(d > h+h || (n > 2 && h == 1 && d == 1)){
		printf("-1\n");
		return 0;
	}
	
	for(i=2;i<=n;i++) V.push_back(i);
	
	prev = 1;
	for(i=1;i<=h;i++){
		k = V.back(); V.pop_back();
		printf("%d %d\n", prev, k);
		prev = k;
	}
	
	if(h == d){
		for(;!V.empty();){
			printf("%d %d\n", n, V.back());
			V.pop_back();
		}
	}
	else{	
		prev = 1;
		for(;i<=d;i++){
			k = V.back(); V.pop_back();
			printf("%d %d\n", prev, k);
			prev = k;
		}
		
		for(;!V.empty();){
			printf("%d %d\n", 1, V.back());
			V.pop_back();
		}
	}
	
	return 0;
}