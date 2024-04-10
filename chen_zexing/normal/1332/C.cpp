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
using namespace std;
char s[200005];
int cnt[30];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        scanf("%s",s+1);
        int ans=0;
        for(int i=1;i<=k/2;i++){
            for(int j=0;j<26;j++) cnt[j]=0;
            for(int j=i;j<=n;j+=k){
                cnt[s[j]-'a']++;
                cnt[s[j+k-2*i+1]-'a']++;
            }
            int mx=0;
            for(int j=0;j<26;j++) mx=max(mx,cnt[j]);
            ans+=n/k*2-mx;
        }
        if(k%2){
            for(int i=0;i<26;i++) cnt[i]=0;
            for(int i=k/2+1;i<=n;i+=k){
                cnt[s[i]-'a']++;
            }
            int mx=0;
            for(int i=0;i<26;i++) mx=max(mx,cnt[i]);
            ans+=n/k-mx;
        }
        cout<<ans<<endl;
    }
    return 0;
}