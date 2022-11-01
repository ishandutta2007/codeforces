#include<bits/stdc++.h>
using namespace std;

const int bound=1e6+1;

int bit[bound+5];

int sum(int pos){
    int res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos&-pos;
    }
    return res;
}

void add(int pos,int val){
    while(pos<=bound){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

int n,m;
long long ans=1;
vector<pair<int,int>> qs[bound+5];
vector<int> seg[bound+5];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int y,l,r;
        cin>>y>>l>>r;
        y++;l++;r++;
        qs[y].emplace_back(l,r);
        ans+=l==1&&r==bound;
    }
    for(int i=1;i<=m;i++){
        int x,d,u;
        cin>>x>>d>>u;
        x++;d++;u++;
        seg[d].emplace_back(x);
        seg[u+1].emplace_back(-x);
        ans+=d==1&&u==bound;
    }
    for(int y=1;y<=bound;y++){
        for(int &x:seg[y])add(abs(x),x/abs(x));
        for(pair<int,int> &p:qs[y])ans+=sum(p.second)-sum(p.first-1);
    }
    cout<<ans<<endl;

    return 0;
}