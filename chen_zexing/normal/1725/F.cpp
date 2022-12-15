#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int l[100005],r[100005],b[300005];
int ans[30];
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n,q;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
        for(int i=0;i<30;i++){
            unordered_map <int,int> mp;
            int x=0;
            b[++x]=0,b[++x]=1<<i;
            for(int j=1,ll,rr;j<=n;j++){
                if(r[j]-l[j]+1>=(1<<i)){
                    mp[0]++,mp[1<<i]--;
                    continue;
                }
                ll=l[j]%(1<<i),rr=r[j]%(1<<i);
                if(ll<=rr) mp[ll]++,mp[rr+1]--,b[++x]=ll,b[++x]=rr+1;
                else mp[0]++,mp[rr+1]--,mp[ll]++,mp[1<<i]--,b[++x]=rr+1,b[++x]=ll;
            }
            sort(b+1,b+x+1);
            int now=0;
            for(int j=1;j<=x;j++)
                if(j==1||b[j]!=b[j-1])
                    now+=mp[b[j]],ans[i]=max(ans[i],now);
        }
        cin>>q;
        for(int i=1,x;i<=q;i++){
            scanf("%d",&x);
            for(int j=0;j<30;j++)
                if((1<<j)&x){
                    printf("%d\n",ans[j]);
                    break;
                }
        }
    }
    return 0;
}