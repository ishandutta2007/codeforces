#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    cout<<"YES\n";
    char fi[4][n];
    for(int a=0; a<4; a++) for(int b=0; b<n; b++) fi[a][b]='.';
    if(k%2==0)
    {
        for(int a=1; a+1<n; a++)
        {
            if(k)
            {
                fi[1][a]='#', fi[2][a]='#', k-=2;
            }
        }
    }
    else
    {
        for(int a=1; a<=2; a++)
        {
            for(int b=1; b<=n-1-b; b++)
            {
                int p=n-1-b;
                if(k)
                {
                    if(b==p)
                    {
                        fi[a][b]='#', k--;
                    }
                    else
                    {
                        if(k==1)
                        {
                            fi[a][n/2]='#', k--;
                        }
                        else
                        {
                            fi[a][b]='#', fi[a][p]='#', k-=2;
                        }
                    }
                }
            }
        }
    }
    for(int a=0; a<4; a++)
    {
        for(int b=0; b<n; b++) cout<<fi[a][b];
        cout<<"\n";
    }
}