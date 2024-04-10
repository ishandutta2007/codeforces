#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[55],t[55];
int fails[55],failt[55];
char a[1005];
int dp[1005][55][55];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        scanf("%s",a+1);
        scanf("%s",s+1);
        scanf("%s",t+1);
        int l=strlen(a+1),ls=strlen(s+1),lt=strlen(t+1),ans=INT_MIN/10;
        for(int i=1;i<=ls;i++){
            if(i==1) fails[i]=0;
            else{
                fails[i]=fails[i-1];
                while(fails[i]&&s[fails[i]+1]!=s[i]) fails[i]=fails[fails[i]];
                if(s[fails[i]+1]==s[i]) fails[i]++;
            }
        }
        for(int i=1;i<=lt;i++){
            if(i==1) failt[i]=0;
            else{
                failt[i]=failt[i-1];
                while(failt[i]&&t[failt[i]+1]!=t[i]) failt[i]=failt[failt[i]];
                if(t[failt[i]+1]==t[i]) failt[i]++;
            }
        }
        for(int i=0;i<=l;i++)
            for(int j=0;j<=ls;j++)
                for(int k=0;k<=lt;k++)
                    dp[i][j][k]=INT_MIN/10;
        dp[0][0][0]=0;
        for(int i=1;i<=l;i++)
            for(int j=0;j<ls;j++)
                for(int k=0;k<lt;k++){
                    if(a[i]=='*'){
                        for(int f=0;f<26;f++){
                            int ps=j,pt=k,cnt=dp[i-1][j][k];
                            while(ps&&s[ps+1]!=f+'a') ps=fails[ps];
                            if(s[ps+1]==f+'a') ps++;
                            while(pt&&t[pt+1]!=f+'a') pt=failt[pt];
                            if(t[pt+1]==f+'a') pt++;
                            if(ps==ls) ps=fails[ps],cnt++;
                            if(pt==lt) pt=failt[pt],cnt--;
                            dp[i][ps][pt]=max(dp[i][ps][pt],cnt);
                            if(i==l) ans=max(ans,cnt);
                        }
                    }
                    else{
                        int ps=j,pt=k,cnt=dp[i-1][j][k];
                        while(ps&&s[ps+1]!=a[i]) ps=fails[ps];
                        if(s[ps+1]==a[i]) ps++;
                        while(pt&&t[pt+1]!=a[i]) pt=failt[pt];
                        if(t[pt+1]==a[i]) pt++;
                        if(ps==ls) ps=fails[ps],cnt++;
                        if(pt==lt) pt=failt[pt],cnt--;
                        dp[i][ps][pt]=max(dp[i][ps][pt],cnt);
                        //cout<<i<<" "<<j<<" "<<k<<" "<<cnt<<endl;
                        if(i==l) ans=max(ans,cnt);
                    }
                }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//