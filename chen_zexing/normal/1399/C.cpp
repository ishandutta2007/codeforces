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
#include <cstring>
using namespace std;
int a[55],cnt[105];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        int n,mx=0,t=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        for(int i=2;i<=2*n;i++)
        {
            t=0;
            for(int j=1;j<=(i-1)/2;j++)
                t+=min(cnt[j],cnt[i-j]);
            if(i%2==0) t+=cnt[i/2]/2;
            if(mx<t)
            {
                mx=t;
            }
        }
        printf("%d\n",mx);
    }
    return 0;
}