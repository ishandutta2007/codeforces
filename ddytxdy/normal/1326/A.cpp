#include<bits/stdc++.h>
using namespace std;
int T,n;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n==1){puts("-1");continue;}
		putchar('2');
		for(int i=1;i<n;i++)putchar('3');
		puts("");
	}
	return 0;
}