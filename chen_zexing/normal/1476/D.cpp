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
char s[300005];
int ll[300005],rr[300005],lr[300005],rl[300005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        scanf("%s",s);
        rl[n]=rr[n]=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='R') rr[i]=rl[i+1]+1,rl[i]=0;
            else rr[i]=0,rl[i]=rr[i+1]+1;
        }
        ll[0]=lr[0]=0;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='R') lr[i]=ll[i-1]+1,ll[i]=0;
            else ll[i]=lr[i-1]+1,lr[i]=0;
        }
        for(int i=0;i<=n;i++) printf("%d ",rr[i]+ll[i]+1);
        puts("");
    }
    return 0;
}