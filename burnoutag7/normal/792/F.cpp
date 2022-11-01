#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int q;
ll m;
set<pair<int,int>> s;

int cmp(int x1,int y1,int x2,int y2,int x,int y){
    x2-=x1;y2-=y1;
    x-=x1;y-=y1;
    ll diff=(ll)y*x2-(ll)y2*x;
    return diff>0?1:diff<0?-1:0;
}

void add(int x,int y){
    auto it=s.lower_bound(make_pair(x,0));
    if(it!=s.end()&&it->first==x){
        if(it->second<=y)return;
        s.erase(it);
    }
    auto nxt=s.lower_bound(make_pair(x,0));
    if(nxt==s.end())s.emplace(x,y);
    else{
        auto prv=nxt;prv--;
        if(cmp(prv->first,prv->second,nxt->first,nxt->second,x,y)<0)s.emplace(x,y);
        else return;
    }
    while(true){
        auto cur=s.lower_bound(make_pair(x,y));
        if(cur==s.begin())break;
        auto p1=cur;p1--;
        if(p1==s.begin())break;
        auto p2=p1;p2--;
        if(cmp(p2->first,p2->second,cur->first,cur->second,p1->first,p1->second)<0)break;
        s.erase(p1);
    }
    while(true){
        auto cur=s.lower_bound(make_pair(x,y));
        auto p1=cur;p1++;
        if(p1==s.end())break;
        auto p2=p1;p2++;
        if(p2==s.end())break;
        if(cmp(cur->first,cur->second,p2->first,p2->second,p1->first,p1->second)<0)break;
        s.erase(p1);
    }
}

typedef long double ld;

int cmpld(ld x1,ld y1,ld x2,ld y2,ld x,ld y){
    x2-=x1;y2-=y1;
    x-=x1;y-=y1;
    ld diff=y*x2-y2*x;
    return diff>0?1:diff<0?-1:0;
}

bool qry(ld x,ld y){//x+, y-
    auto nxt=s.lower_bound(make_pair(ceil(x),0));
    if(nxt==s.end())return false;
    if(nxt->first==x)return nxt->second<=y;
    auto prv=nxt;prv--;
    return cmpld(prv->first,prv->second,nxt->first,nxt->second,x,y)>=0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    s.emplace(0,0);
    cin>>q>>m;
    for(int i=1,las=0;i<=q;i++){
        int typ,x,y;
        cin>>typ>>x>>y;
        x=(x+las)%1000000+1;
        y=(y+las)%1000000+1;
        if(typ==1){
            add(x,y);
        }else{
            bool ans=qry((ld)y/x,(ld)m/x);
            if(ans){
                cout<<"YES\n";
                las=i;
            }else{
                cout<<"NO\n";
            }
        }
    }

    return 0;
}