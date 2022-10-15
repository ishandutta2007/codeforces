#include <bits/stdc++.h>

using namespace std;

int l,r,a;
int ans=0;

int main()
{
    cin>>l>>r>>a;
    for(int j=0;j<=a;j++)
        ans=max(ans,min(l+j,r+a-j));
    cout<<2*ans;
    return 0;
}
/**
**/