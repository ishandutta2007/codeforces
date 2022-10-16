#include<bits/stdc++.h>
using namespace std;
int a,ans;
int sum(int x,int A){return A?sum(x,A/x)+A%x:0;}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	cin>>a;
	for(int i=2;i<a;i++)
		ans+=sum(i,a);
	cout<<ans/gcd(ans,a-2)<<"/"<<(a-2)/gcd(ans,a-2);
}