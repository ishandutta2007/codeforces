#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <memory.h>
#include <ctime>

#define ll long long

using namespace std;

char D[152][152];
int l[152],r[152];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> D[i];
    for(int i=0;i<n;i++)
    {
        l[i]=5000; r[i]=-1;
        for(int j=0;j<m;j++)
        {
            if (D[i][j]=='W')
            {
                if (l[i]==5000) l[i]=j;
                r[i]=j;
            }
        }
    }
    int ans=0,pos=0;
    for(int i=0;i<n-1;i++)
    {
        if (i%2==0)
        {
            int npos=max(pos,max(r[i],r[i+1]));
            ans+=npos-pos;
            pos=npos;
        }
        else
        {
            int npos=min(pos,min(l[i],l[i+1]));
            ans+=pos-npos;
            pos=npos;
        }
    }
    if ((n-1)%2==0)
    {
        if (r[n-1]!=-1) ans+=r[n-1]-pos;
    }
    else
        if (l[n-1]!=5000) ans+=pos-l[n-1];
    for(int i=n-1;i>=0;i--)
        if (l[i]!=5000)
        {
            ans+=i;
            break;
        }
    cout << ans << endl;
    return 0;
}