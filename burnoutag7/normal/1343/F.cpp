#include<bits/stdc++.h>
using namespace std;

int n,a[205];
vector<int> occ[205];
set<int> seg[205];

bool put(int pos,int val){
    a[pos]=val;
    if(pos==n)return true;
    for(int i:occ[val]){
        seg[i].erase(val);
    }
    bool res=1;
    int nxt=-1;
    for(int i=1;i<n;i++)if(seg[i].size()==1){
        if(nxt!=-1)res=0;
        else nxt=*seg[i].begin();
    }
    res&=nxt!=-1;
    if(res)res&=put(pos+1,nxt);
    for(int i:occ[val]){
        seg[i].emplace(val);
    }
    return res;
}

bool check(){
    set<set<int>> s;
    for(int i=1;i<n;i++)s.emplace(seg[i]);
    for(int i=2;i<=n;i++){
        set<int> t;
        bool fnd=0;
        for(int j=i;j>=1;j--){
            t.emplace(a[j]);
            auto it=s.find(t);
            if(it!=s.end()){
                fnd=1;
                s.erase(it);
                break;
            }
        }
        if(!fnd)return 0;
    }
    return s.empty();
}

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++)occ[i].clear();
    for(int i=1;i<n;i++){
        int k;
        cin>>k;
        seg[i].clear();
        while(k--){
            int x;
            cin>>x;
            seg[i].emplace(x);
            occ[x].emplace_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(put(1,i)){
            if(check()){
                for(int i=1;i<=n;i++)cout<<a[i]<<' ';
                cout<<'\n';
                return;
            }
        }
    }
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