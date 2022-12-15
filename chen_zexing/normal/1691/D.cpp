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
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
long long pre[200005],mn[200005][18],mx[200005][18];
int a[200005];
int n;
struct st{
    void prework(){
        for(int i=0;i<=n;i++) mn[i][0]=mx[i][0]=pre[i];
        for(int i=1;i<18;i++)
            for(int j=0;j<=n;j++) {
                mn[j][i] = min(mn[j][i - 1], mn[min(j + (1 << (i - 1)), n)][i - 1]);
                mx[j][i] = max(mx[j][i - 1], mx[min(j + (1 << (i - 1)), n)][i - 1]);
            }
    }
    long long query(int l,int r,int type){
        if(type==0){
            int f=log2(r-l+1);
            return min(mn[l][f],mn[r-(1<<f)+1][f]);
        }
        else{
            int f=log2(r-l+1);
            return max(mx[l][f],mx[r-(1<<f)+1][f]);
        }
    }
}ST;
struct node{
    int num,pos;
    friend bool operator <(node a,node b){
        return a.num<b.num;
    }
}b[200005];
int l[200005],r[200005],f[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i],f[i]=0,b[i]=node{a[i],i};
        f[0]=f[n+1]=0;
        ST.prework();
        sort(b+1,b+n+1);
        int fl=1;
        for(int i=1;i<=n;i++){
            int id=b[i].pos,v=b[i].num;
            if(f[id-1]) l[id]=l[id-1];
            else l[id]=id;
            if(f[id+1]) r[id]=r[id+1];
            else r[id]=id;
            l[r[id]]=l[id],r[l[id]]=r[id],f[id]=1;
            //cout<<ST.query(id,r[id],1)-ST.query(l[id]-1,id-1,0)<<endl;
            if(ST.query(id,r[id],1)-ST.query(l[id]-1,id-1,0)>v) fl=0;
        }
        puts(fl?"YES":"NO");
    }
    return 0;
}