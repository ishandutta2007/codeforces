#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=1e5+3;
ll arr[MN];
ll psa[MN];
ll sparsel[17][MN];
ll sparser[17][MN];
int n,q;
void ms(){
    for(int i=1;i<17;i++){
        for(int j=1;j+(1<<i)<=n+1;j++){
            sparsel[i][j]=min(sparsel[i-1][j],sparsel[i-1][j+(1<<(i-1))]);
            sparser[i][j]=max(sparser[i-1][j],sparser[i-1][j+(1<<(i-1))]);
        }
    }
}

ll getl(int a, int b){
    int k=__lg(b-a+1);
    return min(sparsel[k][a],sparsel[k][b-(1<<k)+1]);
}
ll getr(int a, int b){
    int k=__lg(b-a+1);
    return max(sparser[k][a],sparser[k][b-(1<<k)+1]);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    ll a,b;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a,arr[i]-=a;
        psa[i]=psa[i-1]+arr[i];
        sparsel[0][i]=psa[i];
        sparser[0][i]=psa[i];
    }
    ms();
    while(q--){
        cin>>a>>b;
        if(psa[b]-psa[a-1]!=0){
            printf("-1\n");
            continue;
        }
        ll ma=getr(a,b),mi=getl(a,b);
        if(ma-psa[a-1]>0){
            printf("-1\n");
            continue;
        }
        printf("%lli\n",abs(mi-psa[a-1]));
    }
    return 0;
}