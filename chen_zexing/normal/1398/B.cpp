#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
char s[105];
int a[105];
bool cmp(int a,int b)
{
    return a>b;
}
int main() {
    int T;
    cin >> T;
    while(T--)
    {
        scanf("%s",s);
        int l=strlen(s),x=0,cnt=0,ans=0;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='1') cnt++;
            else{
                a[++x]=cnt;
                cnt=0;
            }
        }
        a[++x]=cnt;
        sort(a+1,a+x+1,cmp);
        for(int i=1;i<=x&&a[i];i+=2) ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}