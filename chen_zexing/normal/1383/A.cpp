#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
char a[100005],b[100005];
int cnt[25][25];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        int n,f=1,ans=0;
        cin>>n;
        scanf("%s",a);
        scanf("%s",b);
        for(int i=0;i<n;i++) {
            cnt[a[i] - 'a'][b[i] - 'a']++;
            if(a[i]-'a'>b[i]-'a')
            {
                f=0;
                break;
            }
        }
        if(f==0)
        {
            printf("-1\n");
            continue;
        }
        for(int i=0;i<20;i++)
            for(int j=i+1;j<20;j++)
            {
                if(cnt[i][j])
                {
                    ans++;
                    for(int k=j+1;k<20;k++)
                    {
                        cnt[j][k]+=cnt[i][k];
                        cnt[i][k]=0;
                    }
                }
            }
        printf("%d\n",ans);

    }
}