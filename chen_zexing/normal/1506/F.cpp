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
    int x,y;
}a[200005];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i].x);
        for(int i=1;i<=n;i++) scanf("%d",&a[i].y);
        sort(a+1,a+n+1,cmp);
        a[0].x=1,a[0].y=1;
        long long ans=0;
        for(int i=1;i<=n;i++){
            if(a[i].x-a[i].y!=a[i-1].x-a[i-1].y) ans+=abs((a[i].x-a[i].y)/2-(a[i-1].x-a[i-1].y)/2);
            else if((a[i].x+a[i].y)%2==0)ans+=a[i].y-a[i-1].y;
            //cout<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp