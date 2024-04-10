#include<bits/stdc++.h>
using namespace std;
int n,T;	
int a[200004],b[200004];
bool check(int x){
	int cur=0;
	for(int i=1;i<=n;i++)if(b[i]>=cur&&a[i]>=x-cur-1)cur++;
	return cur>=x;
}
void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	int l=-1,r=n+1;
	while(r>l+1){
		int m=(l+r)/2;
		if(check(m))l=m;
		else r=m;
	}
	printf("%d\n",l);
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}