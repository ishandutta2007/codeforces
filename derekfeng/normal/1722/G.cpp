#include<bits/stdc++.h>
using namespace std;
int t,n;
void sol(){
	scanf("%d",&n);t=0;
	if(n%4==0){
		for(int i=1;i<=n/4;i++){
			++t,printf("%d %d ",(t<<4),(t<<4)+1);
			++t,printf("%d %d ",(t<<4)+1,(t<<4));
		}puts("");
		return;
	}
	if(n%4==1){
		for(int i=1;i<=n/4-1;i++){
			++t,printf("%d %d ",(t<<4),(t<<4)+1);
			++t,printf("%d %d ",(t<<4)+1,(t<<4));
		}
		printf("1 8 2 15 4\n");
		return;
	}
	if(n%4==2){
		for(int i=1;i<=n/4-1;i++){
			++t,printf("%d %d ",(t<<4),(t<<4)+1);
			++t,printf("%d %d ",(t<<4)+1,(t<<4));
		}
		printf("1 4 3 9 5 10\n");
		return;
	}
	for(int i=1;i<=n/4;i++){
		++t,printf("%d %d ",(t<<4),(t<<4)+1);
		++t,printf("%d %d ",(t<<4)+1,(t<<4));
	}
	printf("1 2 3\n");
}
int main(){
	int tc;scanf("%d",&tc);
	while(tc--)sol();
}