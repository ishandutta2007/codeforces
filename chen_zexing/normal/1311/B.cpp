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
int a[105],p[105],b[105],v[105];
int check(int l,int r){
    int cnt[105]={};
    for(int i=l;i<=r;i++) cnt[b[i]]++;
    for(int i=l;i<=r;i++){
        if(cnt[a[i]]<=0) return 0;
        cnt[a[i]]--;
    }
    return 1;
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
        sort(b+1,b+n+1);
        for(int i=1;i<=m;i++) cin>>p[i];
        sort(p+1,p+m+1);
        p[m+1]=0;
        int st=1,f=1;
        for(int i=1;i<=m+1;i++){
            if(i>1&&p[i]-p[i-1]!=1) f&=check(p[st],p[i-1]+1),st=i;
        }
        for(int i=1;i<=n;i++) v[i]=0;
        for(int i=1;i<=m;i++) v[p[i]]=v[p[i]+1]=1;
        for(int i=1;i<=n;i++) if(!v[i]&&a[i]!=b[i]) f=0;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
//
/// 
//01
// 