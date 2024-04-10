#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,m;
    cin>>n>>m;
    pair<pair<int,int>,pair<int,int>> p,r;
    bool mid=false;
    for(int i=0;i<n;i++){
        cin>>p.first.first>>p.first.second>>p.second.first>>p.second.second;
        r=p;
        swap(r.first.second,r.second.first);
        if(p==r)mid=true;
    }
    cout<<(mid&&(m&1^1)?"YES\n":"NO\n");
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