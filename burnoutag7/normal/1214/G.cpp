#include<bits/stdc++.h>
using namespace std;

int n,m,q,cnt[2005];
bitset<2005> a1[2005],a[2005],tmp;
set<pair<int,int>> s,ans;
set<int> g[2005];

void add(int x,int y){
    tmp=a[x]&a[y];
    if(a[x]!=tmp){
        g[x].emplace(y);
        g[y].emplace(x);
        ans.emplace(x<y?x:y,x<y?y:x);
    }
}

void update(int cur,int l,int r){
    {//remove answer contribution
        for(int x:g[cur]){
            g[x].erase(cur);
            ans.erase({x<cur?x:cur,x<cur?cur:x});
        }
        g[cur].clear();
        a[cur]^=a1[r];
        a[cur]^=a1[l-1];
    }
    {//add contribution from prev & next, remove current from S
        auto it=s.find({cnt[cur],cur});
        int prv=-1,nxt=-1;
        if(it!=s.begin())prv=(--it)->second,++it;
        ++it;
        if(it!=s.end())nxt=it->second;
        if(prv!=-1&&nxt!=-1)add(prv,nxt);
        s.erase({cnt[cur],cur});
    }
    {//add current to S and answer contribution
        cnt[cur]=a[cur].count();
        auto it=s.emplace(cnt[cur],cur).first;
        int prv=-1,nxt=-1;
        if(it!=s.begin())prv=(--it)->second,++it;
        ++it;
        if(it!=s.end())nxt=it->second;
        if(prv!=-1)add(prv,cur);
        if(nxt!=-1)add(cur,nxt);
    }
}

void answer(){
    if(ans.empty()){
        cout<<"-1\n";
        return;
    }
    int x1=ans.begin()->first,x2=ans.begin()->second;
    tmp=a[x1]&a[x2];
    int y1=(a[x1]^tmp)._Find_first(),y2=(a[x2]^tmp)._Find_first();
    if(y1>y2)swap(y1,y2);
    cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    for(int i=1;i<=m;i++){
        a1[i]=a1[i-1];
        a1[i][i]=1;
    }
    for(int i=1;i<=n;i++)s.emplace(0,i);
    while(q--){
        int cur,l,r;
        cin>>cur>>l>>r;
        update(cur,l,r);
        answer();
    }

    return 0;
}