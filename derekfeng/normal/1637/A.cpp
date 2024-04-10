#include<bits/stdc++.h>
using namespace std;
int mx[10004],mn[10004],a[10004];
void sol(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),mx[i]=max(mx[i-1],a[i]);
	mn[n+1]=2e9;
	for(int i=n;i;i--)mn[i]=min(mn[i+1],a[i]);
	for(int i=1;i<n;i++)if(mx[i]>mn[i+1]){
		puts("YES");
		return;
	}
	puts("NO");
}
int main(){
	int t;scanf("%d",&t);
	while(t--)sol();
}