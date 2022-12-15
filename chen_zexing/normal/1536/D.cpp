#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
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
using namespace std;
int a[200005],b[200005],tree[200005],f[200005],n;
void add(int x,int v){
    if(f[x]) return;
    while(x<=n) tree[x]+=v,x+=x&-x;
}
int query(int x){
    int ans=0;
    while(x) ans+=tree[x],x-=x&-x;
    return ans;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i],tree[i]=0,f[i]=0;
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+n+1,a[i])-b;
        int fl=1;
        add(a[1],1);
        f[a[1]]=1;
        for(int i=2;i<=n;i++){
            add(a[i],1);
            f[a[i]]=1;
            if(abs(query(a[i-1])-query(a[i]))>1) fl=0;
        }
        puts(fl?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp