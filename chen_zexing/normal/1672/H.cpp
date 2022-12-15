#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
char s[200005];
int n;
struct fenwick{
    int tree[200005];
    void add(int x){
        while(x<=n) tree[x]++,x+=x&-x;
    }
    int pre(int x){
        int ans=0;
        while(x) ans+=tree[x],x-=x&-x;
        return ans;
    }
    int query(int l,int r){
        return pre(r)-pre(l-1);
    }
}Tr[2];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int q;
        cin>>n>>q;
        scanf("%s",s+1);
        for(int i=1;i<n;i++)
            if(s[i]==s[i+1])
                Tr[s[i]-'0'].add(i);
        for(int i=1,l,r;i<=q;i++){
            scanf("%d%d",&l,&r);
            printf("%d\n",max(Tr[0].query(l,r-1),Tr[1].query(l,r-1))+1);
        }
    }
    return 0;
}