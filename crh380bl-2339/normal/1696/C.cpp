#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<pair<ll,ll>>S1,S2;
bool judge(){
    if(S1.size()!=S2.size()){
        return 0;
    }
    int i;
    for(i=0;i<S1.size();++i){
        if(S1[i]!=S2[i])return 0;
    }
    return 1;
}
int main(){
    int t,n,z,i,x;
    scanf("%d",&t);
    while(t--){
        S1.clear();
        S2.clear();
        int ans=0;
        bool flag=0;
        scanf("%d%d",&n,&z);
        for(i=1;i<=n;++i){
            int t=1;
            scanf("%d",&x);
            while(x%z==0){
                t*=z;
                x/=z;
            }
            if(S1.empty()||S1[S1.size()-1].first != x){
                S1.push_back(make_pair((ll)x, (ll)t));
            }
            else{
                S1[S1.size()-1].second+=(ll)t;
            }
        }
        scanf("%d",&n);
        for(i=1;i<=n;++i){
            int t=1;
            scanf("%d",&x);
            while(x%z==0){
                t*=z;
                x/=z;
            }
            if(S2.empty()||S2[S2.size()-1].first != x){
                S2.push_back(make_pair(x, t));
            }
            else{
                S2[S2.size()-1].second+=t;
            }
        }
        if(judge())puts("Yes");
        else puts("No");    
    }
    return 0;
}