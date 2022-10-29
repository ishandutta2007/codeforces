#include <iostream>
using namespace std;
int k;
int mod=1000000007;
long long int find(long long int ar[],long long int arr[],int d,int n)
{
	if(n==0)
	return 1;
	if(n<d)
	return 0;
	if(d==0&&arr[n]!=0)
	return arr[n];
	if(d!=0&&ar[n]!=0)
	return ar[n];
	long long int ans=0,e;
	if(d==0)
	{
	for(int i=1;i<=min(n,k);i++)
	{
	     e=find(ar,arr,0,n-i);
	     ans+=e%mod;
	     ans=ans%mod;
	}
	arr[n]=ans;
	return arr[n];
	}
	else
	{
           	     for(int i=1;i<=min(n,k);i++)
	     {
	     if(i>=d)
	     e=find(ar,arr,0,n-i);
	     else
	     e=find(ar,arr,d,n-i);
	     ans+=e%mod;
	     ans=ans%mod;
            }
            if(d==0){
	arr[n]=ans;
	return arr[n];}
	ar[n]=ans;
	return ar[n];
	}
}
int main() {
	int d,n;
	cin>>n>>k>>d;
	long long int ar[103],arr[103];
	for(int i=0;i<103;i++)
	{
		ar[i]=0;
		arr[i]=0;
	}
	int ans=find(ar,arr,d,n);
	cout<<ans;
	return 0;
}