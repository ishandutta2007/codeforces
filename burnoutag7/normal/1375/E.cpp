#include<bits/stdc++.h>
using namespace std;

int n,a[1005],cnt,pos[1005];
vector<pair<int,int>> dsc;
vector<pair<int,int>> res;

void do_swap(int x,int y){
    res.emplace_back(x+1,y+1);
    pos[a[x]]=y;
    pos[a[y]]=x;
    swap(a[x],a[y]);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        dsc.emplace_back(a[i],i);
    }
    sort(dsc.begin(),dsc.end());
    for(int i=0;i<n;i++){
        a[dsc[i].second]=i;
        pos[i]=dsc[i].second;
    }
    for(int i=n;i--;){
        for(int j=a[i];++j<=i;){
            do_swap(pos[j],i);
        }
    }
    cout<<res.size()<<'\n';
    for(pair<int,int> &p:res)cout<<p.first<<' '<<p.second<<'\n';

    return 0;
}