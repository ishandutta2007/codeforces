#include<bits/stdc++.h>
const int N=10005;
using namespace std;

bool cmd(int a,int b){
	return (a&1)<(b&1);
} 

int n,a[N],t;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n,cmd);
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		putchar('\n');
	}
}