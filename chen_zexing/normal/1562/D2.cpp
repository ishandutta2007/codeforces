#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[300005];
int pre[300005],a[300005],v[300005][2];
void solve(int l,int r){
    int nd=abs(pre[r]-pre[l-1]),type=pre[r]-pre[l-1]>0;
    int ll=l,rr=r,base=v[l-1][type],tar=base+nd/2+1;
    //cout<<"#"<<base<<" "<<l<<" "<<r<<" "<<tar<<" "<<type<<endl;
    while(ll<rr){
        int mid=(ll+rr)/2;
        if(v[mid][type]>=tar) rr=mid;
        else ll=mid+1;
    }
    printf("%d\n",ll);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) a[i]=(s[i]=='+'?1:-1),pre[i]=i%2?pre[i-1]+a[i]:pre[i-1]-a[i];
        for(int i=1;i<=n;i++){
            v[i][0]=v[i-1][0],v[i][1]=v[i-1][1];
            if(i%2==0) a[i]*=-1;
            if(a[i]==1) v[i][1]++,v[i][0]--;
            else v[i][0]++,v[i][1]--;
        }
        //for(int i=1;i<=n;i++) cout<<v[i][1];puts("");
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            int temp=abs(pre[r]-pre[l-1]);
            if(temp==0) puts("0");
            else{
                if(temp%2==0) printf("2\n%d ",l),solve(l+1,r);
                else printf("1\n"),solve(l,r);
            }
        }
    }
    return 0;
}
//
/// 
//01
//