
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
typedef long long LL;
struct BIT{
    int val[maxn];
    inline int lowbit(int x){
        return x&(-x);
    }
    void add (int x){
        while (x<maxn){
            val[x]++;
            x+=lowbit(x);
        }
    }
    int query(int x){
        int res =0;
        while (x){
            res+=val[x];
            x-=lowbit(x);
        }
        return res;
    }
}bit;
int n;
int a[maxn];
int rk[maxn];
bool cmp(int x,int y){
    return a[x]<a[y];
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for (int i=1;i<=n;i++){
        rk[i]=i;
    }
    sort(rk+1,rk+n+1,cmp);
    LL ans=0;
    for (int i=n,j=n;i>=1;i--){
        int l = i+1;
        int r = min(n,a[i]);
        while (j>0&&a[rk[j]]>=i){
            bit.add(rk[j]);
            j--;
        }
        if (i<n&&r>=l){
            ans+=bit.query(r)-bit.query(l-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}