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
char s[200005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,cnt=1,ans=0;
        cin>>n;
        scanf("%s",s);
        int t=1;
        while(s[t]==s[t-1]&&t<=n) t++;
        for(int i=t+1;i<=n+t+1;i++)
        {
            if(s[i%n]==s[(i-1)%n]) cnt++;
            else{
                ans+=cnt/3;
                cnt=1;
            }
        }
        ans+=cnt/3;
        printf("%d\n",ans);
    }
    return 0;
}