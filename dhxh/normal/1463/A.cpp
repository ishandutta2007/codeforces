#include <bits/stdc++.h>

using namespace std;

int n, m, t;

int main(){
	int i, j;
	
	scanf("%d", &t);
	
	while(t--){
		int a, b, c;
		cin >> a >> b >> c;
		int mn = min(a, min(b, c));
		int sum = a + b + c - mn * 3;
		
		if(sum % 6 == 3){
			sum += 3;
			mn -= 1;
		}
		
		if(sum % 6 == 0 and sum / 6 <= mn and (mn - sum / 6) % 3 == 0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}