#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
struct p{
    int pos,bl;
}a[600006];
bool cmp(p a,p b){
    return a.pos<b.pos;
}
int v[6],c[100005],cnt;
int main() {
    for(int i=0;i<6;i++) cin>>v[i];
    int n,t,x=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&t);
        for(int j=0;j<6;j++) a[++x]=p{t-v[j],i};
    }
    sort(a+1,a+x+1,cmp);
    int r=0,ans=INT_MAX;
    for(int i=1;i<=6*n;i++){
        if(i>1){
            c[a[i-1].bl]--;
            if(c[a[i-1].bl]==0) cnt--;
        }
        while(cnt!=n&&r<n*6){
            r++;
            c[a[r].bl]++;
            if(c[a[r].bl]==1) cnt++;
        }
        if(cnt==n) ans=min(ans,a[r].pos-a[i].pos);
    }
    cout<<ans<<endl;
    return 0;
}