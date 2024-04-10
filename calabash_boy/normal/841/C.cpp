#include<bits/stdc++.h>
using namespace std;
const int maxx = 200005;
int a[maxx],b[maxx];
int rka[maxx],rkb[maxx];
bool cmpa(int x,int y){
	return a[x]>a[y];
}
bool cmpb(int x,int y){
	return b[x]<b[y];
}
int ans[maxx];
int main(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		rka[i]=i;
	}
	for (int i=0;i<n;i++){
		scanf("%d",b+i);
		rkb[i]=i;
	}
	sort(rka+0,rka+n,cmpa);
	sort(rkb+0,rkb+n,cmpb);

	for (int i=0;i<n;i++){
		ans[rkb[i]] = a[rka[i]];
	}
	for (int i=0;i<n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}