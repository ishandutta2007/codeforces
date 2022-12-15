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
int a[3505];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        if(k>m-1) k=m-1;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=0;
        for(int i=0;i<=k;i++){
            int l=i+1,r=n-(k-i),temp=INT_MAX;
            //cout<<l<<" "<<r<<endl;
            for(int j=l;j<=l+m-k-1;j++)
                temp=min(temp,max(a[j],a[r-(m-k-1-(j-l))]));
            ans=max(ans,temp);
            //cout<<temp<<endl;
        }
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