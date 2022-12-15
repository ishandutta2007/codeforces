#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
struct node{
    int pos,v;
    friend bool operator < (node a,node b){
        return a.v>b.v;
    }
};
set <node> s;
int f[200005],lft[200005],rt[200005],a[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k,tag=1;
        cin>>n>>k;
        for(int i=1,t;i<=n;i++) scanf("%d",&t),a[i]=t,s.insert(node{i,t}),lft[i]=i-1,rt[i]=i+1;
        while(1){
            if(!s.size()) break;
            int pos=(*s.begin()).pos;
            f[pos]=tag;
            s.erase(s.begin());
            rt[lft[pos]]=rt[pos],lft[rt[pos]]=lft[pos];
            for(int j=rt[pos],cc=1;cc<=k&&j!=n+1;j=rt[j],cc++){
                f[j]=tag,rt[lft[j]]=rt[j],lft[rt[j]]=lft[j];
                s.erase(node{j,a[j]});
            }
            for(int j=lft[pos],cc=1;cc<=k&&j!=0;j=lft[j],cc++){
                f[j]=tag,rt[lft[j]]=rt[j],lft[rt[j]]=lft[j];
                s.erase(node{j,a[j]});
            }
            tag=3-tag;
        }
        for(int i=1;i<=n;i++) printf("%d",f[i]);
    }
    return 0;
}
//
/// 
//01
//