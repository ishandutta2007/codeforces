#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
bool used[maxn];
int n;
int main(){
	scanf("%d",&n);
	printf("1");
	int r =n+1;
	for (int i=1;i<=n;i++){
		int index ;
		scanf("%d",&index);
		used[index] =true;
		while (used[r-1])r--;
		printf(" %d",i-(n-r));
	}
	return 0;
}