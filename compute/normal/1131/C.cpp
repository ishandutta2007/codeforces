#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int arr[maxn];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	for(int i=0;i<n;i+=2)
		cout<<arr[i]<<" ";
	for(int i=(n-1)%2==0?(n-2):n-1;i>0;i-=2)
		cout<<arr[i]<<" ";
	cout<<endl;

}