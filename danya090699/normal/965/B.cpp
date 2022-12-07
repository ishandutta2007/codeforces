#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    char fi[n][n];
    int q[n][n];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            cin>>fi[a][b];
            q[a][b]=0;
        }
    }
    for(int a=0; a<n; a++)
    {
        int yk=0;
        while(yk<n)
        {
            if(fi[a][yk]=='#') yk++;
            else
            {
                int st=yk;
                while(yk<n)
                {
                    if(fi[a][yk]=='.') yk++;
                    else break;
                }
                for(st; st+k<=yk; st++)
                {
                    for(int i=st; i<st+k; i++) q[a][i]++;
                }
            }
        }
        yk=0;
        while(yk<n)
        {
            if(fi[yk][a]=='#') yk++;
            else
            {
                int st=yk;
                while(yk<n)
                {
                    if(fi[yk][a]=='.') yk++;
                    else break;
                }
                for(st; st+k<=yk; st++)
                {
                    for(int i=st; i<st+k; i++) q[i][a]++;
                }
            }
        }
    }
    int be=0, x=0, y=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            if(q[a][b]>be)
            {
                be=q[a][b], x=a, y=b;
            }
        }
    }
    cout<<x+1<<" "<<y+1;
}