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
char s[500005];
int l[500005],fst[500005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        long long ans=0,now=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='1'){
                cnt++;
                now+=i-fst[cnt];
                //cout<<i-fst[cnt]<<endl;
                ans+=now;
            }
            else{
                while(cnt) fst[cnt]=i-cnt,cnt--;
                ans+=now;
            }
            //cout<<now<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}