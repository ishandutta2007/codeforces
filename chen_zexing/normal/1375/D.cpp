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
int a[1005],n;
queue <int> q;
int check()
{
    for(int i=1;i<=n;i++)
        if(a[i]!=i-1)
            return 0;
    return 1;
}
int cnt[1005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        while(!q.empty()) q.pop();
        while(!check())
        {
            memset(cnt,0,sizeof(cnt));
            for(int i=1;i<=n;i++) cnt[a[i]]++;
            int mex=0;
            for(int i=0;i<=n;i++)
                if(cnt[i]==0)
                {
                    mex=i;
                    break;
                }
            if(mex!=n)
            {
                a[mex+1]=mex;
                q.push(mex+1);
                ans++;
            }
            else{
                int t;
                for(int i=1;i<=n;i++)
                    if(a[i]!=i-1)
                    {
                        t=i-1;
                        break;
                    }
                for(int i=1;i<=n;i++)
                    if(a[i]==t)
                    {
                        a[i]=mex;
                        q.push(i);
                        ans++;
                    }
            }
        }
        printf("%d\n",ans);
        while(!q.empty())
        {
            printf("%d ",q.front());
            q.pop();
        }
        printf("\n");
    }
    return 0;
}