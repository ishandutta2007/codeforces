#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>
#include <string>
#include <set>
#include <map>

using namespace std;

int a1[100005],a2[100005];
int w1[100005],w2[100005];

pair<int,int> mtree[500005];
int d[500005];

void update(int i,int l,int r,int pos,int add) {
    if (l==r) {
        mtree[i].first=add;
        mtree[i].second=l;
        d[i]=0;
        return;
    }
    if (d[i]) {
        mtree[i].first+=d[i];
        d[2*i]+=d[i]; d[2*i+1]+=d[i]; d[i]=0;
    }
    int m=(l+r)>>1;
    if (pos<=m) update(2*i,l,m,pos,add);
    else update(2*i+1,m+1,r,pos,add);
    int val1=mtree[2*i].first+d[2*i],val2=mtree[2*i+1].first+d[2*i+1];
//  if (val1<=val2) mtree[i]=mtree[2*i];
//  else mtree[i]=mtree[2*i+1];
    mtree[i]=make_pair(min(val1,val2),val1<=val2 ? mtree[2*i].second : mtree[2*i+1].second);
}

int ans[100005];

//pair <int,int> fen[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    pair <int,int> WW=make_pair(1000000000,-1);
    for(int i=0;i<500000;++i) mtree[i]=WW;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&a1[i]);
        w1[--a1[i]]=i;
        ans[i]=1000000000;
    }
    for(int i=0;i<n;++i) {
        scanf("%d",&a2[i]);
        w2[--a2[i]]=i;
    }
    for(int i=0;i<n;++i) update(1,0,n,i,w1[i]<=w2[i] ? (w2[i]-w1[i]) : 1000000000);
    for(int i=0;i<n;++i) {
        if (d[1]) {
            mtree[1].first+=d[1];
            d[2]+=d[1]; d[3]+=d[1]; d[1]=0;
        }
        while(mtree[1].first<0) {
            update(1,0,n,mtree[1].second,1000000000);
        }
        ans[i]=mtree[1].first;
        --d[1];
        update(1,0,n,a2[i],n-1-w1[a2[i]]);
    }

    for(int i=0;i<500000;++i) mtree[i]=WW;
    memset(d,0,sizeof(d));
    for(int i=0;i<n;++i) update(1,0,n,i,w1[i]>=w2[i] ? (w1[i]-w2[i]) : 1000000000);
    int pos=0;
    for(int i=0;i<n;++i) {
        if (d[1]) {
            mtree[1].first+=d[1];
            d[2]+=d[1]; d[3]+=d[1]; d[1]=0;
        }
        while(mtree[1].first<0) {
            update(1,0,n,mtree[1].second,1000000000);
        }
        ans[pos]=min(ans[pos],mtree[1].first);
        --d[1];
        update(1,0,n,a2[n-1-i],w1[a2[n-1-i]]);
        pos--;
        if (pos<0) pos+=n;
    }
/*  cout << 100000 << endl;
    for(int i=0;i<100000;++i)
        cout << i+1 << "    ";
    cout << endl;
    for(int i=0;i<100000;++i)
        cout << 100000-i << "   ";
    cout << endl;*/
    for(int i=0;i<n;++i)
        printf("%d\n",ans[i]);
    return 0;
}