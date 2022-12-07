#include <bits/stdc++.h>
using namespace std;
const int sz=100;
char fi[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, stx, sty;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            cin>>fi[a][b];
            if(fi[a][b]=='S')
            {
                stx=a, sty=b;
            }
        }
    }
    string s;
    cin>>s;
    int p[4]={0, 1, 2, 3}, go[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, q=0;
    for(int a=0; a<24; a++)
    {
        int x=stx, y=sty, ok=0;
        for(int b=0; b<s.size(); b++)
        {
            x=x+go[p[s[b]-'0']][0];
            y=y+go[p[s[b]-'0']][1];
            if(x>=0 and x<n and y>=0 and y<m)
            {
                if(fi[x][y]=='#') break;
                if(fi[x][y]=='E') ok=1;
            }
            else break;
        }
        q+=ok;
        next_permutation(p, p+4);
    }
    cout<<q;
}