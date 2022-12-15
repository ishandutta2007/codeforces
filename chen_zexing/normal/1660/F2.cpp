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
using namespace std;
char s[200005];
int pre[200005];
int tree[400005][3],n;
void add(int x,int id,int v){
    while(x<=n*2+1) tree[x][id]+=v,x+=x&-x;
}
int query(int x,int id){
    int ans=0;
    while(x) ans+=tree[x][id],x-=x&-x;
    return ans;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        long long ans=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n*2+1;i++) tree[i][0]=tree[i][1]=tree[i][2]=0;
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='-'?1:-1);
        for(int i=1;i<=n;i++) pre[i]+=n+1;
        add(n+1,(n+1)%3,1);
        for(int i=1;i<=n;i++){
            ans+=query(pre[i],pre[i]%3);
            //cout<<pre[i]<<" "<<ans<<endl;
            add(pre[i],pre[i]%3,1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map