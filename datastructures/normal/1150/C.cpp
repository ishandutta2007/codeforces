#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,x,num1,num2;
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (x==1)num1++;
		if (x==2)num2++;
	}
	if (num2>0){
		if (num1==0){
			for (int i=1;i<=num2;i++)cout<<2<<' ';
			return 0;
		}
		else{
			cout<<2<<' '<<1<<' ';
			num1--,num2--;
			for (int i=1;i<=num2;i++)cout<<2<<' ';
			for (int i=1;i<=num1;i++)cout<<1<<' ';
			return 0;
		}
	}
	else{
		for (int i=1;i<=num1;i++)cout<<1<<' ';
		return 0;
	}
	return 0;
}