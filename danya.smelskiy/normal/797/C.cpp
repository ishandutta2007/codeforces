#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;

string ans;
string s;
int sz;
pair<int,int> t2[500005];
int t[500005];
inline void update1(int x){
    t2[x]=make_pair(inf,x);
    x/=2;
    while (x){
        t2[x].first=min(t2[x+x].first,t2[x+x+1].first);
        if (t2[x+x].first==t2[x].first) t2[x].second=t2[x+x].second;
        else t2[x].second=t2[x+x+1].second;
        x/=2;
    }
}
inline void update2(int x){
    t[x]=0;
    x/=2;
    while (x) {
        t[x]=t[x+x]+t[x+x+1];
        x/=2;
    }
}
int get2(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)/2;
    return get2(l,mid,ll,rr,x+x)+get2(mid+1,r,ll,rr,x+x+1);
}
pair<int,int> get1(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return make_pair(inf,1);
    if (l>=ll && r<=rr) return t2[x];
    int mid=(l+r)/2;
    pair<int,int> xx,yy;
    xx=get1(l,mid,ll,rr,x+x);
    yy=get1(mid+1,r,ll,rr,x+x+1);
    if (xx.first<=yy.first) return xx;
    else return yy;
}
int get3(int l,int r,int x,int y){
    if (l==r) return x;
    int mid=(l+r)/2;
    if (t[x+x]>=y) return get3(l,mid,x+x,y);
    else return get3(mid+1,r,x+x+1,y-t[x+x]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    sz=1;
    while (sz<(int)s.size()) sz+=sz;
    for (int i=sz;i<=sz+sz;++i)
        t2[i]=make_pair(inf,i);
    for (int i=1;i<=s.size();++i){
        int x=s[i-1];
        t2[sz+i-1]=make_pair(x,sz+i-1);
    }
    for (int i=sz-1;i>0;--i){
        t2[i].first=min(t2[i+i].first,t2[i+i+1].first);
        if (t2[i+i].first==t2[i].first) t2[i].second=t2[i+i].second;
        else t2[i].second=t2[i+i+1].second;
    }
    for (int i=sz;i<=sz+sz;++i)
        t[i]=1;
    for (int i=sz-1;i>0;--i)
        t[i]=t[i+i]+t[i+i+1];
    int last=0;

    for (int i=1;i<=s.size();++i){
        pair<int,int> z=get1(1,sz,last+1,s.size(),1);
        int o=get2(1,sz,1,last-1,1);
        if (o!=0) {
        o=get3(1,sz,1,o);
        if (t2[o].first<=z.first) z=t2[o];
        }
        ans+=char(z.first);
        update1(z.second);
        update2(z.second);
        last=z.second-sz+1;
    }
    cout<<ans;
}