#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
struct pos{
    int x,y;
    long long v;
};
map <long long,int> mp;
char s[200005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,mn=INT_MAX,a,b;
        cin>>n;
        scanf("%s",s+2);
        mp.clear();
        pos p;
        p.x=p.y=0;
        p.v=1e9*p.x+p.y;
        mp[p.v]=1;
        for(int i=2;i<=n+1;i++)
        {
            if(s[i]=='U') p.y++;
            if(s[i]=='D') p.y--;
            if(s[i]=='R') p.x++;
            if(s[i]=='L') p.x--;
            p.v=1e9*p.x+p.y;
            if(mp[p.v]&&i-mp[p.v]<mn)
            {
                mn=i-mp[p.v];
                a=mp[p.v],b=i;
            }
            mp[p.v]=i;
        }
        if(mn==INT_MAX) printf("-1\n");
        else printf("%d %d\n",a,b-1);
    }
    return 0;
}