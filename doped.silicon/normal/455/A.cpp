#include <iostream>
using namespace std;
long long int max1=0;
long long int find(long long int ar[],long long int arr[],int i)
{   
    if(i>=max1+1)
    return 0;
    if(arr[i]!=0)
    {
        return arr[i];
    }
    if(ar[i]==0)
    {
        arr[i]=find(ar,arr,i+1);
        return arr[i];
    }
    if(ar[i]>ar[i+1]){
    arr[i]= ar[i]+find(ar,arr,i+2);
    	return arr[i];
    }
    arr[i]=max(ar[i]+find(ar,arr,i+2),find(ar,arr,i+1));
    return arr[i];
}
int main() {
	long long int n;
	cin>>n;
	long long int k;
	long long int ar[100005],arr[100005];
	
	for(int i=0;i<100005;i++)
	{
		ar[i]=0;
		arr[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>k;
		if(k>max1)
		max1=k;
		ar[k]+=k;
	}
	long long int ans=find(ar,arr,1);
    
	cout<<ans;
	return 0;
}