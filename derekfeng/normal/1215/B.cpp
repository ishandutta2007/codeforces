#include <bits/stdc++.h>
using namespace std;
int n,x;
int num1=0,num2=0;
long long ans1=0,ans2=0;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x;
		if (x<0) swap(num1,num2);
		if (x<0) num2++;
		else num1++;
		ans1+=num1,ans2+=num2;
	}
	cout<<ans2<<" "<<ans1;
}