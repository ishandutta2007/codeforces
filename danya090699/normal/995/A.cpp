#include <bits/stdc++.h>
using namespace std;
const int sz=2e4;
int an[sz][3];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, q=0, ok=1;
    cin>>n>>k;
    int ar[4][n];
    for(int a=0; a<4; a++) for(int b=0; b<n; b++) cin>>ar[a][b];
    while(1)
    {
        for(int a=0; a<n; a++)
        {
            if(ar[1][a]!=0 and ar[1][a]==ar[0][a])
            {
                an[q][0]=ar[1][a], an[q][1]=1, an[q][2]=a+1, q++;
                ar[1][a]=0, k--;
            }
        }
        for(int a=0; a<n; a++)
        {
            if(ar[2][a]!=0 and ar[2][a]==ar[3][a])
            {
                an[q][0]=ar[2][a], an[q][1]=4, an[q][2]=a+1, q++;
                ar[2][a]=0, k--;
            }
        }
        /*for(int a=0; a<4; a++)
        {
            for(int b=0; b<n; b++) cout<<ar[a][b]<<" ";
            cout<<"\n";
        }*/
        if(k==0) break;
        int x=-1, y=-1;
        for(int a=1; a<=2; a++)
        {
            for(int b=0; b<n; b++)
            {
                if(ar[a][b]==0)
                {
                    x=a, y=b;
                }
            }
        }
        if(x==-1)
        {
            ok=0;
            break;
        }
        for(int a=1; a<n*2; a++)
        {
            int nx=x, ny=y;
            if(x==1)
            {
                if(y) ny=y-1;
                else
                {
                    nx=2, ny=0;
                }
            }
            else
            {
                if(y!=n-1) ny=y+1;
                else
                {
                    nx=1, ny=n-1;
                }
            }
            if(ar[nx][ny])
            {
                ar[x][y]=ar[nx][ny], ar[nx][ny]=0;
                an[q][0]=ar[x][y], an[q][1]=x+1, an[q][2]=y+1, q++;
            }
            x=nx, y=ny;
        }
    }
    if(ok)
    {
        cout<<q<<"\n";
        for(int a=0; a<q; a++)
        {
            for(int b=0; b<3; b++) cout<<an[a][b]<<" ";
            cout<<"\n";
        }
    }
    else cout<<-1;
}