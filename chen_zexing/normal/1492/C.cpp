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
char s[200005],t[200005];
int fst[200005],lst[200005];
int m,n;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        cin>>n>>m;
        scanf("%s",s+1);
        scanf("%s",t+1);
        int now=1;
        for(int i=1;i<=m;i++){
            while(s[now]!=t[i]) now++;
            fst[i]=now;
            now++;
        }
        now=n;
        for(int i=m;i>=1;i--){
            while(s[now]!=t[i]) now--;
            lst[i]=now;
            now--;
        }
        int ans=0;
        for(int i=1;i<m;i++) ans=max(ans,lst[i+1]-fst[i]);
        printf("%d\n",ans);
    }
    return 0;
}