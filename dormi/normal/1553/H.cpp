#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
struct trie{
    struct node{
        int ans,mival,maval,left,right;
        node(){
            left=-1,right=-1;
            ans=INT_MAX,mival=INT_MAX,maval=INT_MAX;
        }
    };
    vector<node> t;
    int newnode(){
       t.push_back(node());
       return sz(t)-1;
    }
    int mt(int ind, int level){//smallest level that they are all same on
        if(ind==-1)ind=newnode();
        if(level==0)return ind;
        int te=mt(-1,level-1);t[ind].left=te;
        te=mt(-1,level-1);t[ind].right=te;
        return ind;
    }
    void calc(int ind, int level){
        t[ind].mival=(t[t[ind].left].mival==INT_MAX?t[t[ind].right].mival+(t[t[ind].right].mival==INT_MAX?0:(1<<(level-1))):t[t[ind].left].mival);
        t[ind].maval=(t[t[ind].right].maval==INT_MAX?t[t[ind].left].maval:t[t[ind].right].maval+(1<<(level-1)));
        t[ind].ans=min({t[t[ind].left].ans,t[t[ind].right].ans,(t[t[ind].left].maval==INT_MAX||t[t[ind].right].mival==INT_MAX?INT_MAX:t[t[ind].right].mival+(1<<(level-1))-t[t[ind].left].maval)});
    }
    void insert(int ind, int level, int val){
        if(level==0){
            if(t[ind].mival==INT_MAX)t[ind].mival=t[ind].maval=0;
            else t[ind].ans=0;
            return;
        }
        if(val&(1<<(level-1)))insert(t[ind].right,level-1,val);
        else insert(t[ind].left,level-1,val);
        calc(ind,level);
    }
    void xored(int ind, int level, int xorlevel){
        if(level-1==xorlevel){
            swap(t[ind].left,t[ind].right);
            calc(ind,level);
            return;
        }
        xored(t[ind].left,level-1,xorlevel);
        xored(t[ind].right,level-1,xorlevel);
        calc(ind,level);
    }
}solver;
int ans[(1<<19)];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k,a;
    cin>>n>>k;
    solver.mt(-1,k);
    for(int i=0;i<n;i++){
        cin>>a;
        solver.insert(0,k,a);
    }
    for(int i=0;i<(1<<k);i++){
        if(i)for(int j=0;j<k;j++){
            if((i&(1<<j))!=((i-1)&(1<<j))){
                solver.xored(0,k,k-j-1);
            }
        }
        int val=0;
        for(int j=0;j<k;j++){
            if(i&(1<<j))val+=(1<<(k-j-1));
        }
        ans[val]=solver.t[0].ans;
    }
    for(int i=0;i<(1<<k);i++)printf("%d%c",ans[i]," \n"[i==(1<<k)-1]);
    return 0;
}