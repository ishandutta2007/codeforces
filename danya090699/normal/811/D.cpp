#include <bits/stdc++.h>
using namespace std;
struct poi
{
    int y, x;
};
poi nel;
const int sz=103;
char fi[sz][sz], u='U', d='D', l='L', r='R';
int n, m, y, x, ey, ex;
bool solve()
{
    bool f1=0, f2=0;
    if(n==1) f1=1;
    if(m==1) f2=1;
    if(n>1 and fi[2][1]!='*')
    {
        cout<<"U\n";
        cin>>y>>x;
        if(y==2)
        {
            swap(u, d);
            if(y==ey and x==ex) return 0;
            cout<<u<<"\n";
            cin>>y>>x;
        }
        f1=1;
    }
    if(m>1 and fi[1][2]!='*')
    {
        cout<<"L\n";
        cin>>y>>x;
        if(x==2)
        {
            swap(l, r);
            if(y==ey and x==ex) return 0;
            cout<<l<<"\n";
            cin>>y>>x;
        }
        f2=1;
    }
    if(f1==0)
    {
        while(fi[y+1][x]=='*')
        {
            cout<<r<<"\n";
            cin>>y>>x;
            if(y==ey and x==ex) return 0;
        }
        cout<<"U\n";
        cin>>y>>x;
        if(y==2)
        {
            swap(u, d);
            if(y==ey and x==ex) return 0;
        }
    }
    if(f2==0)
    {
        while(fi[y][x+1]=='*')
        {
            cout<<d<<"\n";
            cin>>y>>x;
            if(y==ey and x==ex) return 0;
        }
        cout<<"L\n";
        cin>>y>>x;
        if(x==2)
        {
            swap(l, r);
            if(y==ey and x==ex) return 0;
        }
    }
    int dp[sz][sz];
    for(int a=1; a<=n; a++) for(int b=1; b<=m; b++) dp[a][b]=-1;
    queue <poi> qu;
    dp[ey][ex]=-2;
    nel.y=ey, nel.x=ex;
    qu.push(nel);
    while(qu.size()!=0)
    {
        int q=qu.size();
        for(int a=0; a<q; a++)
        {
            int cy=qu.front().y, cx=qu.front().x;
            for(int b=0; b<4; b++)
            {
                poi np;
                np.y=cy, np.x=cx;
                if(b==0) np.y++;
                if(b==1) np.y--;
                if(b==2) np.x++;
                if(b==3) np.x--;
                if(np.y>0 and np.y<=n and np.x>0 and np.x<=m)
                {
                    if(dp[np.y][np.x]==-1 and fi[np.y][np.x]!='*')
                    {
                        dp[np.y][np.x]=b, qu.push(np);
                    }
                }
            }
            qu.pop();
        }
    }
    while(y!=ey or x!=ex)
    {
        int ty=dp[y][x];
        if(ty==0) cout<<u;
        if(ty==1) cout<<d;
        if(ty==2) cout<<l;
        if(ty==3) cout<<r;
        cout<<"\n";
        cin>>y>>x;
    }
    return 0;
}
int main()
{
    cin>>n>>m;
    for(int a=1; a<=n; a++)
    {
        for(int b=1; b<=m; b++)
        {
            cin>>fi[a][b];
            if(fi[a][b]=='F')
            {
                ey=a, ex=b;
            }
        }
    }
    solve();
}