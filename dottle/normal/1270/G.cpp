#include<bits/stdc++.h>
const int N=1000500;
using namespace std;

int a[N],n,t,x,l;

int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n),x=l=1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)x=x-a[x];
		for(int i=x;i-a[i]!=x;i=i-a[i])l++;
		printf("%d\n",l);
		for(int i=1;i<=l;i++)printf("%d ",x),x=x-a[x];
		putchar('\n');
	}
}