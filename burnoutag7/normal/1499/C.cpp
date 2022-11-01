#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,c[100005];
ll p[100005],ans;

void mian(){
    cin>>n;
    priority_queue<int,vector<int>,greater<int>> pq[2];
    ans=1e18;
    for(int i=1;i<=n;i++){
        cin>>c[i];
        p[i]=c[i]+(i>1?p[i-2]:0);
        pq[i&1].emplace(c[i]);
        if(i>=2){
            ans=min(ans,p[i]+(ll)pq[i&1].top()*(n-(i+1>>1))+p[i-1]+(ll)pq[i&1^1].top()*(n-(i>>1)));
        }
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}