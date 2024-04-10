#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=1e6+1;
ll cost[MAXN];
ll cap[MAXN];
ll te[MAXN],te2[MAXN];
int n;
int check(ll am){
    if(am>min(cost[0],cap[n-1]))return 0;
    for(int i=0;i<n;i++){
        te[i]=cost[i],te2[i]=cap[i];
    }
    te[0]-=am;
    te2[n-1]-=am;
    int ret=0;
    for(int i=0;i<n;i++){
        te2[i]-=te[i];
        if(te2[i]<0)return ret;
        if(i<n-1){
            ll x=min(te[i+1],te2[i]);
            te[i+1]-=x,te2[i]-=x;
            if(te2[i])ret=-1;
        }
    }
    return 1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>cost[i];
        }
        for(int i=0;i<n;i++){
            cin>>cap[i];
        }
        ll lo=0,hi=min(cost[0],cap[n-1]);
        bool done=false;
        while(lo!=hi){
            ll mid=(lo+hi)/2+1;
            int te=check(mid);
            if(te==1){
                printf("YES\n");
                done=true;
                break;
            }
            else if(te==-1)hi=mid-1;
            else lo=mid;
        }
        if(!done){
            if(check(lo)==1||check(lo+1)==1){
                printf("YES\n");
                done=true;
            }
           
        }
        if(!done){
            printf("NO\n");
        }
    }
    return 0;
}