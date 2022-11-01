#include<bits/stdc++.h>
using namespace std;

int n,m,L[3005],R[3005],dp[6005][6005];
vector<int> seg[6005];
set<pair<int,int>> st;

int dfs(const int &l,const int &r){
    int &res=dp[l][r];
    if(dp[l][r]!=-1)return res;
    if(l==r)return res=0;
    int have=st.find(make_pair(l,r))!=st.end();
    res=have+dfs(l,r-1);
    for(int &x:seg[r]){
        if(x>l)res=max(res,have+dfs(l,x)+dfs(x,r));
    }
    return res;
}

void mian(){
    cin>>n;
    st.clear();
    //changin' into Codeforces Problem - 39C 
    map<int,int> dsc;
    m=0;
    for(int i=1;i<=n;i++){
        cin>>L[i]>>R[i];
        R[i]++;
        dsc[L[i]]=dsc[R[i]]=0;
    }
    for(pair<const int,int> &p:dsc){
        p.second=++m;
    }
    for(int i=1;i<=m;i++){
        memset(dp[i],-1,m+1<<2);
        seg[i].clear();
    }
    for(int i=1;i<=n;i++){
        L[i]=dsc[L[i]];
        R[i]=dsc[R[i]];
        seg[R[i]].emplace_back(L[i]);
        st.insert(make_pair(L[i],R[i]));
    }
    cout<<dfs(1,m)<<'\n';
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