#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;

int h,g;
int a[1050000];
int ans[1050000];

__gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> dfs(int x){
    __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> res,tmp;
    res.push(a[x]);
    if((x<<1|1)<1<<h){
        res.join(tmp=dfs(x<<1));
        res.join(tmp=dfs(x<<1|1));
        while(res.top()<max(ans[x<<1],ans[x<<1|1]))res.pop();
    }
    if(x<1<<g){
        ans[x]=res.top();
        res.pop();
    }
    return res;
}

void solve(){
    cin>>h>>g;
    memset(ans,0,4<<h);
    for(int i=1;i<1<<h;i++){
        cin>>a[i];
    }
    dfs(1);
    set<int> st;
    long long sum=0;
    for(int i=1;i<1<<g;i++){
        sum+=ans[i];
        st.insert(ans[i]);
    }
    cout<<sum<<endl;
    for(int i=(1<<h)-1;i>0;i--){
        if(st.find(a[i])==st.end())cout<<i<<' ';
    }
    cout<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}