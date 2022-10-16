#include<iostream>
using namespace std;
int main(){
	int a,b,ans=0;
	cin>>a>>b;
	int c[a+1];
	for(int i=1;i<=a;i++)
		cin>>c[i];
	for(int i=1;i<a;i++)
		for(int j=i+1;j<=a;j++)
			if(b/c[i]*(c[j]-c[i])>ans)
				ans=b/c[i]*(c[j]-c[i]);
	cout<<ans+b;
}