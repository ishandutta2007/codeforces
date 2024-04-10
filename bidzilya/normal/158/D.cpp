#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <set>
#include <cstring>
#include <deque>
using namespace std;

#define maxint (int)1e9
#define eps 1e-9


int main()
{
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   int n,a[20001];
   scanf("%d",&n);
   for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int ans = -maxint;
    for (int len=3;len<=n;len++)
        if (n%len ==0)
        {
            int tl = n/len;
            for (int i=1;i<=tl;i++)
            {
                int sum =0;
                for (int j=0;j<len;j++)
                    sum+=a[i + j*tl];
                if (sum>ans)
                    ans = sum;
            }
        }
        printf("%d",ans);
   return 0;
}