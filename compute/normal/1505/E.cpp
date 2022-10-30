#include<bits/stdc++.h>
using namespace std;
string maze[10];
int main()
{
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++) cin>>maze[i];
    int x=0,y=0;
    int ans=maze[0][0]=='*';
    while(x!=h-1||y!=w-1)
    {
        bool fd=0;
        int d=10000;
        int tx=-1,ty=-1;
        for(int i=x;i<h;i++)
        {
            for(int j=y;j<w;j++)
            {
                if(i==x&&j==y) continue;
                if(maze[i][j]=='*')
                {
                    fd=1;
                    int cd=i-x+j-y;
                    if(cd<d)
                    {
                        d=cd;
                        tx=i,ty=j;
                    }
                    else if(cd==d)
                    {
                        if(j>ty)
                        {
                            ty=j;
                            tx=i;
                        }
                    }
                }
            }
        }
        if(!fd) break;
        ans++;
        x=tx,y=ty;
        //cout<<x<<" "<<y<<endl;
    }
    cout<<ans<<'\n';

}