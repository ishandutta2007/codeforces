#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#define maxn 100009
#define PS system("pause");
using namespace std;
int n1,n2,n,a[maxn];
bool cmp(int a,int b){
	return a>b;
}
double solve(int x,int y){
	double sum1=0,sum2=0;
	for(int i=0;i<x;i++)sum1+=a[i];
	for(int i=x;i<x+y;i++) sum2+=a[i];
	return sum1/x+sum2/y;
}
int main(){
	cin>>n>>n1>>n2;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	double ans=max(solve(n1,n2),solve(n2,n1));
	printf("%.9f\n",ans);
	return 0;
}