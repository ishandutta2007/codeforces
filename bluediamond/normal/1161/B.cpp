#include <bits/stdc++.h>

using namespace std;

const int M=(int)2e5+7;
int n,m;
int a[M],b[M];

pair<int,int>get(int x,int y)
{
        if(x<y)
        {
                return {x,y};
        }
        else
        {
                return {y,x};
        }
}

map<pair<int,int>,bool>mp;

bool chk(int k)
{
        for(int i=1;i<=m;i++)
        {
                int x=(a[i]+k);
                int y=(b[i]+k);
                if(x>=n) x-=n;
                if(y>=n) y-=n;
                if(mp[get(x,y)]==0)
                {
                        return 0;
                }
        }
        return 1;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=m;i++)
        {
                cin>>a[i]>>b[i];
                a[i]--; b[i]--;
                mp[get(a[i],b[i])]=1;
        }
        for(int rot=1;rot<n;rot++)
        {
                if(n%rot==0 && chk(rot))
                {
                        cout<<"Yes\n";
                        return 0;
                }
        }
        cout<<"No\n";
        return 0;
}