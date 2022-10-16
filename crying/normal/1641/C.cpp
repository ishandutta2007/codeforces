#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int n,q;
set<int>rest;
set<int>s[MAXN];
int fa[MAXN];
vector<int>tmp;
int Find(int x){
    if(fa[x]==x)return x;
    return fa[x]=Find(fa[x]);
}
void Merge(int x,int y){
    int p=Find(x),q=Find(y);
    if(p==q)return;
    int szp=s[p].size(),szq=s[q].size();
    if(szp<szq)swap(p,q);
    fa[q]=p;
    for(auto u:s[q])s[p].insert(u);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>q;
    rep(i,1,n)rest.insert(i),fa[i]=i;
    rep(i,1,q){
        int op;
        cin>>op;
        if(op==0){
            int l,r,x;cin>>l>>r>>x;
            if(x==0){
                if(rest.size()){
                    tmp.clear();
                    auto it=rest.lower_bound(l);
                    while(it!=rest.end()){
                        int pos=*it;if(pos>r)break;
                        tmp.push_back(pos);
                        //modify pos
                        it++;
                    }
                    for(auto u:tmp)rest.erase(u);
                    for(auto u:tmp){
                        int pos=u;
                        if(pos-1>=1 && rest.find(pos-1)==rest.end())Merge(pos,pos-1);
                        if(pos+1<=n && rest.find(pos+1)==rest.end())Merge(pos,pos+1);
                    }
                }
            }else{
                s[Find(l)].insert(r);
            }
        }else{
            int x;cin>>x;
            if(rest.find(x)==rest.end()){
                cout<<"NO"<<endl;
            }else{
                int nxt=n+1,v=n+1;
                if(x-1>=1&&rest.find(x-1)==rest.end()){
                    set<int>& tmp=s[Find(x-1)];
                    auto it=tmp.lower_bound(x);
                    if(it!=tmp.end())v=*it;
                }
                auto it2=rest.upper_bound(x);
                if(it2!=rest.end())nxt=*it2;
                auto it=s[x].lower_bound(x);
                if(it!=s[x].end())v=min(v,*it);
                if(v>=x&&v<nxt){
                    cout<<"YES"<<endl;
                }else{
                    cout<<"N/A"<<endl;
                }
            }
        }
    }

    return 0;
}