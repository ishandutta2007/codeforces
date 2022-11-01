#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

int n,k,a[200005],b[200005],sum[200005],p[2][200005];

bool check(int bound){
    memset(p,0x3f,sizeof(p));
    for(int i=1;i<=n;i++){
        b[i]=a[i]>=bound;
        sum[i]=sum[i-1]+b[i];
        p[i&1][i]=min(p[i&1][i-1],sum[i-1]-i+i/2);
        p[i&1^1][i]=p[i&1^1][i-1];
        if(i>=k){
            if(i&1){
                if(i+1-sum[i]+p[0][i-k+1]<=i/2)return true;
                if(i+1-sum[i]+p[1][i-k+1]<=i/2)return true;
            }else{
                if(i+1-sum[i]+p[0][i-k+1]<=i/2)return true;
                if(i+1-sum[i]+p[1][i-k+1]+1<=i/2)return true;
            }
        }
        // j <- [1 .. i-k+1] , i+1-sum[i] + sum[j-1]-j <= (i-j)/2
    }
    return false;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    int l=1,r=n,m,res;
    while(l<=r){
        m=l+r>>1;
        if(check(m)){
            l=m+1;
            res=m;
        }else{
            r=m-1;
        }
    }
    cout<<res<<endl;

    return 0;
}