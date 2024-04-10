#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, an=0;
    cin>>n>>m>>k;
    string ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
    }
    for(int a=0; a<n; a++)
    {
        int yk=0;
        while(yk<m)
        {
            if(ar[a][yk]=='*') yk++;
            else
            {
                int st=yk;
                while(yk<m)
                {
                    if(ar[a][yk]=='.') yk++;
                    else break;
                }
                if(yk-st>=k) an+=yk-st-k+1;
            }
        }
    }
    for(int a=0; a<m; a++)
    {
        int yk=0;
        while(yk<n)
        {
            if(ar[yk][a]=='*') yk++;
            else
            {
                int st=yk;
                while(yk<n)
                {
                    if(ar[yk][a]=='.') yk++;
                    else break;
                }
                if(yk-st>=k) an+=yk-st-k+1;
            }
        }
    }
    if(k==1) an/=2;
    cout<<an;
}