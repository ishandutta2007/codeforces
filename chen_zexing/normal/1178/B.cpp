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
char s[1000005];
int pre[1000005],suf[1000005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        scanf("%s",s);
        int l=strlen(s);
        long long ans=0;
        for(int i=0;i<l;i++){
            if(i==0) pre[i]=0;
            else{
                if(s[i]=='v'&&s[i-1]=='v') pre[i]=pre[i-1]+1;
                else pre[i]=pre[i-1];
            }
        }
        for(int i=l-1;i>=0;i--){
            if(i==l-1) suf[i]=0;
            else{
                if(s[i]=='v'&&s[i+1]=='v') suf[i]=suf[i+1]+1;
                else suf[i]=suf[i+1];
            }
        }
        for(int i=1;i<l-1;i++)
            if(s[i]=='o')
                ans+=1LL*pre[i-1]*suf[i+1];
        cout<<ans<<endl;
    }
    return 0;
}