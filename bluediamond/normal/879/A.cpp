#include <bits/stdc++.h>

using namespace std;

const int N=1000+5;
int n,st[N],l[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>st[i]>>l[i];
    for(int i=2;i<=n;i++)
    {
        while(st[i-1]>=st[i])
            st[i]+=l[i];
    }
    cout<<st[n]<<"\n";
    return 0;
}
/**
**/