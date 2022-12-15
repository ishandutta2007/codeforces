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
char s[105][1005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        if(x*2<=y){
            long long cnt=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    if(s[i][j]=='.')
                         cnt++;
            printf("%lld\n",cnt*x);
            continue;
        }
        long long ans=0;
        for(int i=1;i<=n;i++)
        {
            long long cnt=0;
            for(int j=1;j<=m;j++)
            {
                if(s[i][j]=='.') cnt++;
                else{
                    ans+=cnt/2*y;
                    ans+=x*(cnt%2>0);
                    cnt=0;
                }
            }
            ans+=cnt/2*y;
            ans+=x*(cnt%2>0);
        }
        printf("%lld\n",ans);
    }
    return 0;
}