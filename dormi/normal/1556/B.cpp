#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
const int MN=1e5+1;
int arr[MN];
int bit[MN];
int n;
void update(int loc, int val){
    for(;loc<=n;loc+=loc&-loc)bit[loc]+=val;
}
ll query(int loc){
    ll am=0;
    for(;loc>0;loc-=loc&-loc)am+=bit[loc];
    return am;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int cnt[2]={0,0};
        vector<int> inds[2];
        for(int i=0;i<n;i++){
            bit[i+1]=0;
            cin>>arr[i];
            arr[i]%=2;
            inds[arr[i]].push_back(i+1);
            cnt[arr[i]]++;
        }
        if(abs(cnt[0]-cnt[1])>1){
            printf("-1\n");
            continue;
        }
        reverse(inds[0].begin(),inds[0].end());
        reverse(inds[1].begin(),inds[1].end());
        if(n%2==0){
            ll ans1=0;
            vector<int> te1=inds[0],te2=inds[1];
            for(int i=0;i<n;i++){
                ans1+=query(n)-query(inds[i%2].back());
                update(inds[i%2].back(),1);
                inds[i%2].pop_back();
            }
            for(int i=0;i<n;i++)bit[i+1]=0;
            inds[1]=te1,inds[0]=te2;
            ll ans2=0;
            for(int i=0;i<n;i++){
                ans2+=query(n)-query(inds[i%2].back());
                update(inds[i%2].back(),1);
                inds[i%2].pop_back();
            }
            printf("%lli\n",min(ans1,ans2));
            continue;
        }
        if(cnt[1]>cnt[0])swap(inds[0],inds[1]);
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=query(n)-query(inds[i%2].back());
            update(inds[i%2].back(),1);
            inds[i%2].pop_back();
        }
        printf("%d\n",ans);
    }
    return 0;
}