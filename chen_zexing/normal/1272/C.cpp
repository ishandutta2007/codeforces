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
long long ans=0;
char s[200005],c;
int f[30];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        scanf("%s",s+1);
        for(int i=1;i<=k;i++){
            while(scanf("%c",&c)&&(c>'z'||c<'a'));
            f[c-'a']++;
        }
        int x=0;
        for(int i=1;i<=n;i++){
            if(f[s[i]-'a']) x++;
            else{
                ans+=1LL*x*(x+1)/2;
                x=0;
            }
        }
        ans+=1LL*x*(x+1)/2;
        printf("%lld\n",ans);
    }
    return 0;
}