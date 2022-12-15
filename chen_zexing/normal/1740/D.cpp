#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005];
int tree[100005];
void add(int x,int n){
    while(x<=n) tree[x]++,x+=x&-x;
}
int query(int x){
    int ans=0;
    while(x) ans+=tree[x],x-=x&-x;
    return ans;
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n,m,k,f=1;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=k;i++) tree[i]=0;
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]);
            if(query(a[i])>n*m-4) f=0;
            add(a[i],k);
        }
        puts(f?"YA":"TIDAK");
    }
    return 0;
}