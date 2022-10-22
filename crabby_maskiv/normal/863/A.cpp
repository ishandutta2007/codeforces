#include<iostream>
using namespace std;
int n,x[10]; 
bool d(int a)
{
	int cnt=0;
	while(a!=0)
	{
		x[cnt++]=a%10;
		a/=10;
	}
	for(int i=0;i<cnt;i++)
		if(x[i]!=x[cnt-i-1]) return 0;
	return 1;
}
int main()
{
	cin>>n;
	if(n==0)
	{
		cout<<"YES";
		return 0;
	}
	while(n%10==0) n/=10;
	bool ans=d(n);
	if(ans==1) cout<<"YES";
	else cout<<"NO";
	return 0;
}