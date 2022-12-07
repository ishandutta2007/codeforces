#include <bits/stdc++.h>
using namespace std;
const int sz=3e2+10, sz2=4e5+10;
queue <int> qu[sz][sz];
string re[sz][sz];
int an[sz2][4], q=0;
void mov(int x1, int y1, int x2, int y2)
{
    int x=qu[x1][y1].front();
    qu[x1][y1].pop();
    qu[x2][y2].push(x);
    an[q][0]=x1, an[q][1]=y1, an[q][2]=x2, an[q][3]=y2, q++;
}
void build(int x1, int y1)
{
    while(re[x1][y1].size())
    {
        int x=re[x1][y1].back()-'0';
        if(x==0)
        {
            if(y1!=1) mov(0, 1, 0, y1);
            if(x1!=0) mov(0, y1, x1, y1);
        }
        else
        {
            if(x1!=1) mov(1, 0, x1, 0);
            if(y1!=0) mov(x1, 0, x1, y1);
        }
        re[x1][y1].pop_back();
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            string s;
            cin>>s;
            for(int c=s.size()-1; c>=0; c--) qu[a][b].push(s[c]-'0');
        }
    }
    while(qu[0][1].size()) mov(0, 1, 0, 0);
    while(qu[1][0].size()) mov(1, 0, 0, 0);
    while(qu[0][0].size())
    {
        int x=qu[0][0].front();
        if(x==0) mov(0, 0, 0, 1);
        else mov(0, 0, 1, 0);
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(a+b!=1)
            {
                while(qu[a][b].size())
                {
                    int x=qu[a][b].front();
                    if(x==0)
                    {
                        if(a==0 or b==1) mov(a, b, 0, 1);
                        else
                        {
                            mov(a, b, a, 1);
                            if(qu[a][1].size()==1) mov(a, 1, 0, 1);
                        }
                    }
                    else
                    {
                        if(a==1 or b==0) mov(a, b, 1, 0);
                        else
                        {
                            mov(a, b, 1, b);
                            if(qu[1][b].size()==1) mov(1, b, 1, 0);
                        }
                    }
                }
            }
        }
    }
    for(int a=0; a<n; a++) for(int b=0; b<m; b++) cin>>re[a][b];
    for(int i=0; i<2; i++)
    {
        int fx=0, fy=1;
        if(i) swap(fx, fy);
        while(re[fx][fy].size())
        {
            int x=re[fx][fy].back()-'0';
            int x1=0, y1=1;
            if(x) swap(x1, y1);
            mov(x1, y1, 0, 0);
            mov(0, 0, fx, fy);
            re[fx][fy].pop_back();
        }
    }
    for(int a=n-1; a>=0; a--)
    {
        for(int b=m-1; b>=0; b--) if(a+b!=1) build(a, b);
    }
    cout<<q<<"\n";
    for(int a=0; a<q; a++)
    {
        for(int b=0; b<4; b++) printf("%d ", an[a][b]+1);
        printf("\n");
    }
}