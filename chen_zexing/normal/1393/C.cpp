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
    int T;
    cin>>T;
    while(T--)
    {
        int n,t,mx=0,num=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&t);
            cnt[t]++;
        }
        for(int i=1;i<=n;i++)
        {
            if(cnt[i]>mx)
            {
                mx=cnt[i];
                num=1;
            }
            else if(cnt[i]==mx)
                num++;
        }
        int k=n-mx*num;
        printf("%d\n",k/(mx-1)+num-1);
    }

}