#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
using namespace std;
int a[100005],k[100005],f[100005];
vector <int> v[100005];
long long sum[100005];
int tree[400005],lz[400005];
void pushdown(int node,int l,int r){
    if(lz[node]){
        tree[node*2]+=lz[node],tree[node*2+1]+=lz[node];
        lz[node*2]+=lz[node],lz[node*2+1]+=lz[node],lz[node]=0;
    }
}
void update(int node,int l,int r,int L,int R,int v){
    if(l>=L&&r<=R){
        tree[node]+=v,lz[node]+=v;
        return;
    }
    pushdown(node,l,r);
    int mid=(l+r)>>1;
    if(mid>=L) update(node*2,l,mid,L,R,v);
    if(mid<R) update(node*2+1,mid+1,r,L,R,v);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,m,cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=m;i++){
            scanf("%d",&k[i]),f[i]=0,v[i].clear(),sum[i]=0;
            for(int j=1,t;j<=k[i];j++) scanf("%d",&t),sum[i]+=t,v[i].push_back(t);
        }
        for(int i=1;i<=n;i++) update(1,1,100000,1,a[i],1);
        for(int i=1;i<=m;i++){
            int tar=sum[i]/k[i]+(sum[i]%k[i]>0);
            update(1,1,100000,1,tar,-1);
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=k[i];j++){
                int tar0=sum[i]/k[i]+(sum[i]%k[i]>0);
                int tar=(sum[i]-v[i][j-1])/(k[i]-1)+((sum[i]-v[i][j-1])%(k[i]-1)>0);
                update(1,1,100000,1,tar0,1);
                update(1,1,100000,1,tar,-1);
                //cout<<tar0<<" "<<tar<<endl;
                if(tree[1]>=0) printf("1");
                else printf("0");
                update(1,1,100000,1,tar0,-1),update(1,1,100000,1,tar,1);
            }
        for(int i=1;i<=m;i++){
            int tar=sum[i]/k[i]+(sum[i]%k[i]>0);
            update(1,1,100000,1,tar,1);
        }
        for(int i=1;i<=n;i++) update(1,1,100000,1,a[i],-1);
        puts("");
    }
    return 0;
}