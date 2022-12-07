//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n=10, pos=0;
    char ar[n][n];
    for(int a=0; a<n; a++) for(int b=0; b<n; b++) cin>>ar[a][b];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(ar[a][b]=='.')
            {
                ar[a][b]='X';
                for(int c=0; c<n; c++)
                {
                    for(int d=0; d<6; d++)
                    {
                        bool ok=1;
                        for(int e=d; e<d+5; e++) if(ar[c][e]!='X') ok=0;
                        if(ok) pos=1;
                        ok=1;
                        for(int e=d; e<d+5; e++) if(ar[e][c]!='X') ok=0;
                        if(ok) pos=1;
                    }
                }
                for(int c=0; c<6; c++)
                {
                    for(int d=0; d<6; d++)
                    {
                        bool ok=1;
                        for(int e=0; e<5; e++) if(ar[c+e][d+e]!='X') ok=0;
                        if(ok) pos=1;
                    }
                    for(int d=9; d>3; d--)
                    {
                        bool ok=1;
                        for(int e=0; e<5; e++) if(ar[c+e][d-e]!='X') ok=0;
                        if(ok) pos=1;
                    }
                }
                ar[a][b]='.';
            }
        }
    }
    if(pos) cout<<"YES";
    else cout<<"NO";
}