#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	int sum=0;
	bool flag = false;
	while (n--){
		int temp;
		scanf("%d",&temp);
		if (temp&1){
			flag =true;
		}
		sum+=temp;
		sum%=2;
	}
	if (sum==1||flag){
		printf("First\n");
	}else{
		printf("Second\n");
	}
	return 0;
}