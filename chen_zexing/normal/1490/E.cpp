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
struct node{
    int v,id;
    friend bool operator <(node a,node b){
        return a.v<b.v;
    }
}a[200005];
long long pre[200005];
int ans[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i].v),a[i].id=i,ans[i]=0;
        int cnt=0;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i].v;
        pre[n+1]=pre[n],a[n+1].v=0;
        for(int i=n;i>=1;i--){
            if(pre[i]>=a[i+1].v) ans[a[i].id]=1,cnt++;
            else break;
            while(pre[i]==pre[i-1]) i--,ans[a[i].id]=1,cnt++;
        }
        printf("%d\n",cnt);
        for(int i=1;i<=n;i++) if(ans[i]) printf("%d ",i);
        puts("");
    }
    return 0;
}