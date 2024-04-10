#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    char ar[9][9];
    for(int a=0; a<9; a++) for(int b=0; b<9; b++) cin>>ar[a][b];
    int x, y, fo=0;
    cin>>x>>y;
    x--, y--;
    for(int a=(x%3)*3; a<(x%3+1)*3; a++)
    {
        for(int b=(y%3)*3; b<(y%3+1)*3; b++)
        {
            if(ar[a][b]=='.')
            {
                ar[a][b]='!', fo=1;
            }
        }
    }
    if(fo==0)
    {
        for(int a=0; a<9; a++) for(int b=0; b<9; b++) if(ar[a][b]=='.') ar[a][b]='!';
    }
    for(int a=0; a<9; a++)
    {
        for(int b=0; b<9; b++)
        {
            cout<<ar[a][b];
            if(b%3==2) cout<<" ";
        }
        cout<<"\n";
        if(a%3==2) cout<<"\n";
    }
}