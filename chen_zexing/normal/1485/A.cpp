#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
unordered_map<int,int>mp;
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int a,b,f=0;
        int ans=INT_MAX;
        scanf("%d%d",&a,&b);
        if(a<b){
            puts("1");
            continue;
        }
        if(b==1) b++,f=1;
        mp.clear();
        for(int i=b;i<=a+1;i++){
            int cnt=0,temp=a;
            while(temp) temp/=i,cnt++;
            mp[i]=cnt;
            ans=min(mp[i]+i-b,ans);
            if(mp[i]==mp[i-1]) break;
        }
        printf("%d\n",ans+f);
    }
    return 0;
}