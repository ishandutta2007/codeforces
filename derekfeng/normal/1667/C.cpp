#include<bits/stdc++.h>
using namespace std;
int n,w[100004];
int main(){
	scanf("%d",&n);
	int ans=n-(n+1)/3,r=0;
	printf("%d\n",ans);
	for(int i=1;i<=ans;i+=2)printf("%d %d\n",++r,i);
	for(int i=2;i<=ans;i+=2)printf("%d %d\n",++r,i);
}