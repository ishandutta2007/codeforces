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
int a[200005],id[200005];
bool cmp(int x,int y){
    return a[x]>a[y]||a[x]==a[y]&&x<y;
}
struct que{
    int k, pos,id;
}b[200005];
bool cmp2(que a,que b){
    return a.k<b.k;
}
int ans[200005],tr[200005],n;
int query(int x){
    int ans=0;
    while(x) ans+=tr[x],x-=x&-x;
    return ans;
}
void add(int x){
    while(x<=n) tr[x]++,x+=x&-x;
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),id[i]=i;
    sort(id+1,id+n+1,cmp);
    int q;
    cin>>q;
    for(int i=1;i<=q;i++) scanf("%d%d",&b[i].k,&b[i].pos),b[i].id=i;
    sort(b+1,b+q+1,cmp2);
    int now=0;
    for(int i=1;i<=q;i++){
        while(now<b[i].k) add(id[++now]);
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            //cout<<query(mid)<<" "<<mid<<endl;
            if(query(mid)<b[i].pos) l=mid+1;
            else r=mid;
        }
        ans[b[i].id]=a[l];
    }
    for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
    return 0;
}