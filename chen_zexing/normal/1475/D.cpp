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
struct app{
    int sz,b;
}a[200005];
app a1[200005],a2[200005];
bool cmp(app a,app b){
    return a.sz>b.sz;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,x=0,y=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i].sz);
        for(int i=1;i<=n;i++) scanf("%d",&a[i].b);
        for(int i=1;i<=n;i++){
            if(a[i].b==1) a1[++x]=a[i];
            else a2[++y]=a[i];
        }
        sort(a1+1,a1+x+1,cmp);
        sort(a2+1,a2+y+1,cmp);
        a1[x+1].sz=a2[y+1].sz=0;
        a1[x+2].sz=a2[y+2].sz=0;
        int t1=1,t2=1,ans=0;
        while(m>0&&(t1<=x||t2<=y)){
            //cout<<a1[t1].sz<<" "<<a1[t1+1].sz<<" "<<a2[t2].sz<<endl;
            if(a1[t1].sz>=m){
                m-=a1[t1].sz;
                ans++;
            }
            else if(a1[t1].sz+a1[t1+1].sz<a2[t2].sz){
                m-=a2[t2++].sz;
                ans+=2;
            }
            else m-=a1[t1++].sz,ans++;
        }
        if(m>0) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}