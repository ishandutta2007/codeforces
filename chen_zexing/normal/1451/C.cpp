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
char a[1000005],b[1000005];
int cnta[30],cntb[30];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        scanf("%s",a+1);
        scanf("%s",b+1);
        memset(cnta,0,sizeof(cnta));
        memset(cntb,0,sizeof(cntb));
        for(int i=1;i<=n;i++) cnta[a[i]-'a']++;
        for(int i=1;i<=n;i++) cntb[b[i]-'a']++;
        int f=1;
        for(int i=0;i<26;i++){
            if(cnta[i]<cntb[i])
            {
                f=0;
                break;
            }
            if((cnta[i]-cntb[i])%k){
                f=0;
                break;
            }
            cnta[i+1]+=cnta[i]-cntb[i];
        }
        if(f) puts("Yes");
        else puts("No");
    }
    return 0;
}