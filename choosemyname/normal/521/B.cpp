#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
typedef pair<int,int> pii;
map<pii,int> mp;
int can(int i,int j)
{
    if(mp[make_pair(i,j)]==0)
        return 1;
    if(j==0)
        return 1;
    if(mp[make_pair(i-1,j-1)]==0&&mp[make_pair(i,j-1)]==0&&mp[make_pair(i+1,j-1)]==0)
        return 0;
    else
        return 1;
}
int check(int i,int j)
{
    int x=mp[make_pair(i,j)];
    mp[make_pair(i,j)]=0;
    if(can(i-1,j+1)&&can(i,j+1)&&can(i+1,j+1))
    {
        mp[make_pair(i,j)]=x;
        return 1;
    }
    else
    {
        mp[make_pair(i,j)]=x;
        return 0;
    }
    
}
int x[100010],y[100010];
set<int> s;
set<int>::iterator it;
void go(int i,int j)
{
    if(mp[make_pair(i,j)]==0)
        return;
    if(mp[make_pair(i-1,j-1)]!=0&&mp[make_pair(i,j-1)]==0&&mp[make_pair(i+1,j-1)]==0)   
        s.erase(mp[make_pair(i-1,j-1)]);
    if(mp[make_pair(i-1,j-1)]==0&&mp[make_pair(i,j-1)]!=0&&mp[make_pair(i+1,j-1)]==0)   
        s.erase(mp[make_pair(i,j-1)]);  
    if(mp[make_pair(i-1,j-1)]==0&&mp[make_pair(i,j-1)]==0&&mp[make_pair(i+1,j-1)]!=0)   
        s.erase(mp[make_pair(i+1,j-1)]);    
}
int main()
{
    int n,n1;
    cin>>n;
    for(n1=1;n1<=n;n1++)
    {
        scanf("%d%d",&x[n1],&y[n1]);
        mp[make_pair(x[n1],y[n1])]=n1;
    }
    for(n1=1;n1<=n;n1++)
        if(check(x[n1],y[n1]))
        {
            s.insert(n1);
        }
    long long ans=0;
    for(n1=1;n1<=n;n1++)
    {
        if(n1&1)
        {
            it=s.end();
            it--;
            int p=*it;
            s.erase(p);
            mp[make_pair(x[p],y[p])]=0;
            go(x[p]-1,y[p]+1);
            go(x[p],y[p]+1);
            go(x[p]+1,y[p]+1);
            if(y[p])
            {
                if(mp[make_pair(x[p]-1,y[p]-1)]!=0&&check(x[p]-1,y[p]-1))
                    s.insert(mp[make_pair(x[p]-1,y[p]-1)]);
                if(mp[make_pair(x[p],y[p]-1)]!=0&&check(x[p],y[p]-1))
                    s.insert(mp[make_pair(x[p],y[p]-1)]);
                if(mp[make_pair(x[p]+1,y[p]-1)]!=0&&check(x[p]+1,y[p]-1))
                    s.insert(mp[make_pair(x[p]+1,y[p]-1)]); 
            }
            ans=(ans*n+p-1)%(inf+9);
        }
        else
        {
            it=s.begin();
            int p=*it;
            mp[make_pair(x[p],y[p])]=0;
            s.erase(p);
            go(x[p]-1,y[p]+1);
            go(x[p],y[p]+1);
            go(x[p]+1,y[p]+1);
            if(y[p])
            {
                if(mp[make_pair(x[p]-1,y[p]-1)]!=0&&check(x[p]-1,y[p]-1))
                    s.insert(mp[make_pair(x[p]-1,y[p]-1)]);
                if(mp[make_pair(x[p],y[p]-1)]!=0&&check(x[p],y[p]-1))
                    s.insert(mp[make_pair(x[p],y[p]-1)]);
                if(mp[make_pair(x[p]+1,y[p]-1)]!=0&&check(x[p]+1,y[p]-1))
                    s.insert(mp[make_pair(x[p]+1,y[p]-1)]); 
            }
            ans=(ans*n+p-1)%(inf+9);
        }       
    }
    cout<<ans;
}