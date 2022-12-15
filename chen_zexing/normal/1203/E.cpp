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
int can[150005];
int main()
{
    int n,t,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        can[t]++;
    }
    for(int i=1;i<=150001;i++)
        if(can[i]==0)
        {
            if(can[i-1]>1)
            {
                can[i]++;
                can[i-1]--;
            }
            else if(can[i+1])
            {
                can[i]++;
                can[i+1]--;
            }
        }
        else if(can[i]>1)
        {
            can[i+1]++;
            can[i]--;
        }
    for(int i=1;i<=150001;i++) if(can[i]) ans++;
    printf("%d\n",ans);
}