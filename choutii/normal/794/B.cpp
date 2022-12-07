#include<bits/stdc++.h>
using namespace std;
int n,h;
int main(){
	int i,j,k;
	cin>>n>>h;
	double b=0;
	for(i=1;i<=n;i++)b+=sqrt(i);
	for(i=1;i<n;i++)printf("%.12lf\n",sqrt(i)/sqrt(n)*h);
	return 0;
}