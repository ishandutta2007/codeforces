#include<bits/stdc++.h>
using namespace std;
const int maxn = 30;
int a[maxn];
int rk[maxn];
int sa[maxn];
int n;
int ans[maxn];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		rk[i]=i;
	}
	sort(rk,rk+n,cmp);
	for (int i=1;i<n;i++){
		if (a[rk[i-1]]==a[rk[i]]){
			cout<<-1<<endl;
			return 0;
		}
	}
	for (int i=0;i<n-1;i++){
		ans[rk[i+1]] = a[rk[i]];
	}
	ans[rk[0]] = a[rk[n-1]];
	for (int i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}