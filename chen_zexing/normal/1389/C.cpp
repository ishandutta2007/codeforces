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
char s[200005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%s",s);
        int ans=0,l=strlen(s),cnt;
        for(int i=0;i<=9;i++) {
            cnt = 0;
            for (int j = 0; j < l; j++)
                if (s[j] == i + '0') cnt++;
            ans=max(ans,cnt);
        }
        for(int i=0;i<=9;i++)
            for(int j=0;j<=9;j++)
            {
                if(i==j) continue;
                int f=1;
                cnt=0;
                for(int k=0;k<l;k++)
                    if((s[k]==i+'0'&&f==1)||(s[k]==j+'0'&&f==0))
                    {
                        cnt++;
                        f=1-f;
                    }
                if(cnt%2) cnt--;
                //if(i==1&&j==0) cout<<cnt<<endl;
                ans=max(ans,cnt);
            }
        printf("%d\n",l-ans);
    }
    return 0;
}