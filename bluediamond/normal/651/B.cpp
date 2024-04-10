#include <bits/stdc++.h>

using namespace std;

const int N=1000;
int n,ap[N+5],sol=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        ap[x]++;
    }
    for(int i=1;i<=1000;i++)
    {
        int cnt=0;
        for(int j=1;j<=1000;j++)
            if(ap[j]>=1)
            {
                cnt++;
                ap[j]--;
            }
        if(cnt==0)
            break;
        sol+=(cnt-1);
    }
    cout<<sol<<"\n";
    return 0;
}
/**

**/