#include<bits/stdc++.h>
using namespace std;

int n,m,dfn[100005],low[100005],dfncnt,bcccnt;
vector<pair<int,int>> g[100005];
stack<int> st;
set<int> vertex[100005],edge[100005];
bool use[100005];

void getbcc(int x){
    dfn[x]=low[x]=++dfncnt;//cerr<<"START: "<<x<<endl;
    for(pair<int,int> &e:g[x])if(!dfn[e.first]){
        st.push(e.first);
        st.push(e.second);
        use[e.second]=1;
        getbcc(e.first);
        low[x]=min(low[x],low[e.first]);
        if(dfn[x]<=low[e.first]){//cerr<<"BCC: "<<x<<endl;cerr<<st.size()<<endl;
            bcccnt++;
            int tmp;
            vertex[bcccnt].insert(x);
            do{
                edge[bcccnt].insert(tmp=st.top());
                st.pop();
                vertex[bcccnt].insert(st.top());//cerr<<st.top()<<endl;
                st.pop();
            }while(tmp!=e.second);//cerr<<st.size()<<endl;
        }
    }else if(!use[e.second]){
        use[e.second]=1;
        st.push(e.first);
        st.push(e.second);
        low[x]=min(low[x],dfn[e.first]);
    }//cerr<<"END: "<<x<<endl;
}

set<int> ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].emplace_back(b,i);
        g[b].emplace_back(a,i);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])getbcc(i);
    for(int i=1;i<=bcccnt;i++){
        if(edge[i].size()==vertex[i].size()){
            for(const int &x:edge[i])ans.insert(x);
        }
    }
    cout<<ans.size()<<endl;
    for(const int &x:ans)cout<<x<<' ';
    cout<<endl;

    return 0;
}