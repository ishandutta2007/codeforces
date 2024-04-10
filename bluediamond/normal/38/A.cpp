#include <bits/stdc++.h>

using namespace std;

const int N=100;

int n,v[N+5],a,b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++)
        cin>>v[i];
    cin>>a>>b;
    int sum=0;
    for(int i=a;i<b;i++)
        sum+=v[i];
    cout<<sum;
    return 0;
}
/**

**/