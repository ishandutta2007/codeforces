#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int l[maxn],r[maxn];
int arr[maxn];
int main()
{
    int n;
    string s;
    cin>>n>>s;
    int ans=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='G')
        {
            arr[i+1]=1;
            cnt++;
        }
        else arr[i+1]=0;
    }
    l[0]=r[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i])
            l[i]=l[i-1]+arr[i];
        else l[i]=0;
    }
    for(int i=n;i>=1;i--)
    {
        if(arr[i])
            r[i]=r[i+1]+arr[i];
        else r[i]=0;
    }
    for(int i=1;i<n;i++)
        ans=max(l[i-1]+r[i+1]+1,ans);
    ans=min(ans,cnt);
    cout<<ans<<endl;
}