#include <bits/stdc++.h>
using namespace std;
int n,ans=0,key=0;
int main()
{
    cin>>n;
    while(n--)
    {
        cin>>key;
        int A,B;
        A=key-1;
        B=1e6-key;
        ans=max(ans,min(A,B));
    }
    cout<<ans;
    return 0;
}