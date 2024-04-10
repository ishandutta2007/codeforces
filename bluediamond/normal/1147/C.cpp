#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,mi,f=1;
    cin>>n>>mi;
    for(int i=1;i<n;i++)
    {
        int x;
        cin>>x;
        if(x<mi)
        {
            mi=x;
            f=0;
        }
        f+=(mi==x);
    }
    if(f<=(n>>1))
    {
        cout<<"Alice\n";
    }
    else
    {
        cout<<"Bob\n";
    }
    return 0;
}