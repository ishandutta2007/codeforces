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
int a[200005],cnt[200005];
struct node{
    int l,r,v;
    friend bool operator <(node a,node b){
        return a.l<b.l;
    }
}b[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,q,l=1,r=0,mx=0,ans=0;
        cin>>n>>q;
        for(int i=1;i<=200000;i++) b[i].v=i;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(!b[a[i]].l) b[a[i]].l=b[a[i]].r=i;
            else b[a[i]].r=i;
        }
        sort(b+1,b+200000+1);
        for(int i=1;i<=200000;i++){
            if(b[i].l==0) continue;
            if(r<b[i].l){
                ans+=r-l+1-mx;
                mx=0;
                for(int j=l;j<=r;j++) cnt[a[j]]=0;
                l=b[i].l,r=b[i].r;
                for(int j=l;j<=r;j++) cnt[a[j]]++,mx=max(mx,cnt[a[j]]);
            }
            else{
                while(r<b[i].r) r++,cnt[a[r]]++,mx=max(mx,cnt[a[r]]);
            }
            //cout<<ans<<endl;
        }
        ans+=r-l+1-mx;
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp