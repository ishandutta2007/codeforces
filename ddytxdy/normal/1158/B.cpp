#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+50;
int n,k,a[N],l,r,num=0;
int main(){
	scanf("%d%d",&n,&k);
	if(k==1){
		for(int i=1;i<n;i++)putchar('0');
		putchar('1');
		return 0;
	}
	cout<<1;int m=(n-k)/2;
	for(int i=2;i<=n;i++){
		num++;
		if(num>m)num=0,cout<<1;
		else cout<<0;
	}
	return 0;
}