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
int cnt[100005];
int main() {
    int n,t,four=0,two=0,six=0,eight=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t);
        cnt[t]++;
    }
    for(int i=1;i<=100000;i++)
    {
        if(cnt[i]>=4) four++;
        if(cnt[i]>=2) two++;
        if(cnt[i]>=6) six++;
        if(cnt[i]>=8) eight++;
    }
    int q;
    scanf("%d\n",&q);
    for(int i=1;i<=q;i++)
    {
        char c;
        scanf("%c",&c);
        if(c!='+'&&c!='-')
        {
            i--;
            continue;
        }
        scanf("%d",&t);
        if(c=='+')
        {
            cnt[t]++;
            if(cnt[t]==2) two++;
            if(cnt[t]==4) four++;
            if(cnt[t]==6) six++;
            if(cnt[t]==8) eight++;
        }
        else
        {
            cnt[t]--;
            if(cnt[t]==1) two--;
            if(cnt[t]==3) four--;
            if(cnt[t]==5) six--;
            if(cnt[t]==7) eight--;
        }
        //cout<<mx<<" "<<two<<" "<<cnt[t]<<endl;
        if(eight||six&&two>=2||four&&two>=3||four>=2) printf("YES\n");
        else printf("NO\n");
    }
}