#include <bits/stdc++.h>

using namespace std;

const int N=1000;

int v[N+5],y;
int n;
string a;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>a;
    for(int i=0;i<n;i++)
        if(a[i]=='1')
            v[++y]=i+1;
    for(int i=1;i<y;i++)
        if(v[i]+1==v[i+1])
        {
            puts("No");
            return 0;
        }
    if(y==0 && n>2)
        puts("No");
    else
    {
        if(v[1]!=1 && v[1]!=2)
            puts("No");
        else
        {
            bool ok=1;
            for(int i=1;i<y;i++)
                if(v[i+1]-v[i]>3)
                {
                    ok=0;
                    break;
                }
            if(ok==0)
                puts("No");
            else
            {
                if(v[y]==n || v[y]==n-1)
                    puts("Yes");
                else
                    puts("No");
            }
        }
    }
    return 0;
}