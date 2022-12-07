#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    bool ma[n][n];
    if(k>n*n) cout<<-1;
    else
    {
        for(int a=0; a<n; a++)
        {
            for(int b=a; b<n; b++)
            {
                if(a==b)
                {
                    if(k>0)
                    {
                        ma[a][b]=1, k--;
                    }
                    else ma[a][b]=0;
                }
                else
                {
                    if(k>1)
                    {
                        ma[a][b]=1, ma[b][a]=1, k-=2;
                    }
                    else
                    {
                        ma[a][b]=0, ma[b][a]=0;
                    }
                }
            }
        }
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<n; b++) cout<<ma[a][b]<<" ";
            cout<<"\n";
        }
    }
}