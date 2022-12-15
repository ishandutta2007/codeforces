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
int f[300005][2];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        scanf("%s",s);
        for(int i=0;i<n;i++) f[i][0]=f[i][1]=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') f[i%k][0]=1;
            if(s[i]=='1') f[i%k][1]=1;
        }
        int cnt[2]={},fl=1;
        for(int i=0;i<k;i++){
            //cout<<f[i][0]<<" "<<f[i][1]<<endl;
            if(f[i][0]&&f[i][1]) fl=0;
            cnt[0]+=f[i][0],cnt[1]+=f[i][1];
        }
        //cout<<cnt[0]<<" "<<cnt[1]<<endl;
        if(!fl||cnt[1]>k/2||cnt[0]>k/2) puts("NO");
        else puts("YES");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp