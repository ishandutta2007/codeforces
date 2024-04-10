#include<bits/stdc++.h>
using namespace std;

int n,k,a[300005];
vector<int> ans;

bool sol(const vector<int> &lo,const vector<int> &hi,int h){
    if(lo.empty())return false;
    if(hi.empty())return false;
    if(!h){
        ans.emplace_back(lo.front());
        ans.emplace_back(hi.front());
        return true;
    }
    vector<int> ll[2],hh[2];
    for(int x:lo)ll[a[x]>>h-1&1].emplace_back(x);
    for(int x:hi)hh[a[x]>>h-1&1].emplace_back(x);
    if(k>>h-1&1){
        return sol(ll[0],hh[1],h-1)||sol(ll[1],hh[0],h-1);
    }else{
        if(!ll[0].empty()&&!hh[1].empty()){
            ans.emplace_back(ll[0].front());
            ans.emplace_back(hh[1].front());
            return true;
        }
        if(!ll[1].empty()&&!hh[0].empty()){
            ans.emplace_back(ll[1].front());
            ans.emplace_back(hh[0].front());
            return true;
        }
        return sol(lo,hi,h-1);
    }
}

void deal(const vector<int> &v,int h){
    if(v.empty())return;
    vector<int> lo,hi;
    for(int x:v)(a[x]>>h&1?hi:lo).emplace_back(x);
    if(k>>h&1){
        if(!sol(lo,hi,h)){
            if(!lo.empty())ans.emplace_back(lo.front());
            else if(!hi.empty())ans.emplace_back(hi.front());
        }
    }else{
        deal(lo,h-1);
        deal(hi,h-1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> d(n);
    iota(d.begin(),d.end(),1);
    if(k)deal(d,29);
    else ans=d;
    sort(ans.begin(),ans.end());
    if(ans.size()==1){
        cout<<-1;
        return 0;
    }
    cout<<ans.size()<<'\n';
    for(int x:ans)cout<<x<<' ';

    return 0;
}