#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
template<typename T>
int sz(const T &a){return (int)a.size();}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const int MAXN=1e5+1;
int n,m,q;
int val[2*MAXN];
multiset<int> cycvals[MAXN];
struct node{
    int data,le,ri;
    struct node* left,*right;
    node(){
        data=0,le=0,ri=0;
        left=NULL,right=NULL;
    }
    int mid(){return(le+ri)/2;}
    void mt(int l, int r){
        le=l,ri=r;
        if(le!=ri){
            left=new node(),right=new node();
            left->mt(le,mid()),right->mt(mid()+1,ri);
        }
    }
    void update(int a, int am){
        if(a<le||a>ri)return;
        if(le==ri){
            data=am;
            return;
        }
        left->update(a,am),right->update(a,am);
        data=min(left->data,right->data);
    }
    int query(int l, int r){
        if(le>r||ri<l)return INT_MAX;
        if(le>=l&&ri<=r)return data;
        return min(left->query(l,r),right->query(l,r));
    }
};
vector<int> matrix[MAXN];
vector<int> fin[2*MAXN];
int ind[MAXN];
int low[MAXN];
int curind=1;
stack<int> st;
int cycleindex[MAXN];
vector<int> cyclerep;
vector<int> contains[MAXN];
int depth[2*MAXN];
int sts[2*MAXN];
int lift[2*MAXN][18];
int curcycle=1;
int cp[2*MAXN];
int cind[2*MAXN];
int chain[2*MAXN];
vector<node> hld;
void abcc(int loc, int parent){
    ind[loc]=curind;
    low[loc]=curind++;
    st.push(loc);
    for(int x:matrix[loc]){
        if(x!=parent) {
            if (!ind[x]) {
                abcc(x,loc);
                low[loc]=min(low[loc],low[x]);
                if(low[x]==ind[loc]){
                    contains[loc].push_back(curcycle);
                    cyclerep.push_back(loc);
                    while(1){
                        int cur=st.top();
                        st.pop();
                        cycleindex[cur]=curcycle;
                        if(cur==x)break;
                    }
                    curcycle++;
                }
            }
            else low[loc]=min(low[loc],ind[x]);
        }
    }
    if(low[loc]==ind[loc])st.pop();
}
int dfs(int loc, int parent, int dep){
    lift[loc][0]=parent;
    depth[loc]=dep;
    sts[loc]=1;
    for(int x:fin[loc])if(x!=parent)sts[loc]+=dfs(x,loc,dep+1);
    return sts[loc];
}
void ml(){
    rep(i,1,18){
        rep(j,1,n+curcycle){
            lift[j][i]=lift[lift[j][i-1]][i-1];
        }
    }
}
void makechains(int loc, int parent, int rep, int ind){
    if(ind==1){
        chain[loc]=sz(hld);
        hld.push_back(node());
    }
    cp[loc]=rep;
    cind[loc]=ind;
    chain[loc]=chain[rep];
    int ma=0;
    for(int x:fin[loc])if(x!=parent)ma=max(ma,sts[x]);
    for(int x:fin[loc]){
        if(x!=parent){
            if(sts[x]==ma)makechains(x,loc,rep,ind+1),ma=-1;
            else makechains(x,loc,x,1);
        }
    }
    if(ma==0)hld[chain[loc]].mt(1,ind);
    hld[chain[loc]].update(ind,val[loc]);
}
int getlca(int a, int b){
    if(depth[a]<depth[b])swap(a,b);
    int diff=depth[a]-depth[b];
    rep(i,0,18)if(diff&(1<<i))a=lift[a][i];
    if(a==b)return a;
    for(int i=17;i>=0;i--)if(lift[a][i]!=lift[b][i])a=lift[a][i],b=lift[b][i];
    return lift[a][0];
}
int query(int loc, int stop){
    int ans=INT_MAX;
    while(loc!=lift[stop][0]){
        if(depth[cp[loc]]>=depth[stop]){
            ans=min(ans,hld[chain[loc]].query(1,cind[loc]));
            loc=lift[cp[loc]][0];
        }
        else{
            ans=min(ans,hld[chain[loc]].query(cind[stop],cind[loc]));
            loc=lift[stop][0];
        }
    }
    return ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    sc(n,m,q);
    rep(i,1,n+1)sc(val[i]);
    int a,b;
    cyclerep.push_back(0);
    rep(i,0,m){
        sc(a,b);
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }
    abcc(1,0);
    rep(i,1,n+1){
        for(int x:matrix[i]){
            if((cycleindex[x]!=cycleindex[i])||cycleindex[i]==0){
                if(cyclerep[cycleindex[x]]!=i&&cyclerep[cycleindex[i]]!=x)fin[i].push_back(x);
            }
        }
        if(cycleindex[i]!=0){
            cycvals[cycleindex[i]].insert(val[i]);
            fin[i].push_back(n+cycleindex[i]);
            fin[n+cycleindex[i]].push_back(i);
        }
        for(int x:contains[i]){
            fin[i].push_back(n+x);
            fin[n+x].push_back(i);
        }
    }
    rep(i,1,curcycle){
        val[i+n]=*cycvals[i].begin();
    }
    dfs(1,0,0);
    ml();
    makechains(1,0,1,1);
    char c;
    while(q--){
        sc(c,a,b);
        if(c=='C'){
            if(cycleindex[a]){
                cycvals[cycleindex[a]].erase(cycvals[cycleindex[a]].find(val[a]));
                cycvals[cycleindex[a]].insert(b);
                hld[chain[n+cycleindex[a]]].update(cind[n+cycleindex[a]],*cycvals[cycleindex[a]].begin());
            }
            hld[chain[a]].update(cind[a],b);
            val[a]=b;
        }
        else{
            int lca=getlca(a,b);
            int ans=min(query(a,lca),query(b,lca));
            if(lca>n)ans=min(ans,val[cyclerep[lca-n]]);
            prl(ans);
        }
    }
    return 0;
}