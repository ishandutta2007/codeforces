#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
struct ACAM{
    vector<string>S;vector<int>V;
    vector<int>fail,tag;
    vector<vector<int> >e,ch;
    int tot;
    queue<int>q;
    void clear(){
        tot=0;fail.clear();ch.clear();tag.clear();e.clear();
        ch.push_back({});ch[tot].resize(26);fill(ch[tot].begin(),ch[tot].end(),0);
        fail.push_back(0);
        tag.push_back(0);
        e.push_back({});
    }
    int newnode(){
        tot++;
        ch.push_back({});ch[tot].resize(26);fill(ch[tot].begin(),ch[tot].end(),0);
        fail.push_back(0);
        tag.push_back(0);
        e.push_back({});
        return tot;
    }
    void insert(string s,int v){
        int n=s.length(),u=0;
        rep(i,0,n-1){
            int c=s[i]-'a';
            if(!ch[u][c])ch[u][c]=newnode();
            u=ch[u][c];
        }
        tag[u]+=v;
    }
    void dfs(int u){for(auto v:e[u])tag[v]+=tag[u],dfs(v);}
    void build(){
        rep(i,0,25)if(ch[0][i])q.push(ch[0][i]);
        while(q.size()){
            int u=q.front();q.pop();
            rep(i,0,25){
                if(ch[u][i]){
                    fail[ch[u][i]]=ch[fail[u]][i];
                    q.push(ch[u][i]);
                }else ch[u][i]=ch[fail[u]][i];
            }
        }
        rep(i,1,tot)e[fail[i]].push_back(i);
        dfs(0);
    }
    void merge(ACAM& nxt){
        clear();
        for(auto u:nxt.S)S.push_back(u);
        for(auto v:nxt.V)V.push_back(v);
        int sz=S.size();
        rep(i,0,sz-1)insert(S[i],V[i]);
        build();
    }
    ll qry(string s){
        ll ret=0,n=s.length(),u=0;
        rep(i,0,n-1){
            int c=s[i]-'a';u=ch[u][c];
            ret+=tag[u];
        }
        return ret;
    }
};
const int MAXN=3e5+10;
ACAM acam[MAXN];
int cur;
void Add(string s,int v){
    cur++;acam[cur].clear();acam[cur].S.clear();acam[cur].V.clear();
    acam[cur].S.push_back(s);acam[cur].V.push_back(v);acam[cur].insert(s,v);acam[cur].build();
    while(cur>=2 && acam[cur-1].S.size()==acam[cur].S.size()){
        acam[cur-1].merge(acam[cur]);
        cur--;
    }
}
int m,op;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>m;
    rep(i,1,m){
        cin>>op>>s;
        if(op==1)Add(s,1);
        if(op==2)Add(s,-1);
        if(op==3){
            ll ret=0;
            rep(i,1,cur)ret+=acam[i].qry(s);
            cout<<ret<<endl;
        }
    }
    return 0;
}