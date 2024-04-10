#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(n%2 == 0){
		printf("%d\n", n / 2);
		for(int i = 0; i < n / 2; i++)
			printf("2 ");
	}
	else{
		printf("%d\n", (n - 3) / 2 + 1);
		printf("3");
		for(int i = 0; i < (n - 3) / 2; i++)
			printf(" 2");
	}
	//system("pause");
	return 0;
}