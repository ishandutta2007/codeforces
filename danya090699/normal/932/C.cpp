#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, y, fo=0;
    cin>>n>>x>>y;
    int an[n];
    for(int a=0; a*x<=n; a++)
    {
        if((n-a*x)%y==0)
        {
            int b=(n-a*x)/y, yk=0;
            fo=1;
            for(int i=0; i<a; i++)
            {
                for(int c=yk; c<yk+x-1; c++) an[c+1]=c;
                an[yk]=yk+x-1, yk+=x;
            }
            for(int i=0; i<b; i++)
            {
                for(int c=yk; c<yk+y-1; c++) an[c+1]=c;
                an[yk]=yk+y-1, yk+=y;
            }
            break;
        }
    }
    if(fo)
    {
        for(int a=0; a<n; a++) cout<<an[a]+1<<" ";
    }
    else cout<<-1;
}