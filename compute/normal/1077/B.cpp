#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[105];
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    for(int i=1;i<n;i++)
    {
        if(i>1&&arr[i]==0&&arr[i+1]==1&&arr[i-1]==1)
        {
            ans++;
            arr[i+1]=0;
        }
    }
    cout<<ans<<endl;
}