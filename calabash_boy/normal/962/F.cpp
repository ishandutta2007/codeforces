    #include<bits/stdc++.h>
    using namespace std;
    const int maxn = 1e5+100;
    int first[maxn],des[maxn*2],nxt[maxn*2],tot;
    int cnt_n[maxn],cnt_e[maxn],bcc_no[maxn],bcc_cnt;
    int dfn[maxn],low[maxn],dfs_clock;
    int st[maxn*2],top;
    vector<int> ans;
    vector<int> temp;
    int m,n;
    inline void addEdge(int x,int y){
        tot++;
        des[tot] = y;
        nxt[tot] = first[x];
        first[x] = tot;
    }
    void input(){
        cin>>n>>m;
        for (int i=0;i<m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
    }
    void dfs(int u,int fa,int Eid){
  //   cout<<"dfs: "<<u<<","<<fa<<endl;
        dfn[u] = low[u] = ++dfs_clock;
        for (int t = first[u];t;t=nxt[t]){
            int v = des[t];
            if (v==fa)continue;
            if (!dfn[v]){
                st[top++] = t;
                dfs(v,u,t);
                low[u] = min(low[u],low[v]);
                if (low[v]==dfn[u]){
 //                 cout<<"find bcc "<<"dfs "<<u<<","<<v<<endl;
                    bool ok= true;
                    bcc_cnt++;
                    temp.clear();
                    while (true){
                        int tt = st[--top];
    //                  cout<<tt<<endl;
                        temp.push_back((tt+1)/2);
                        if (bcc_no[des[tt]]!=bcc_cnt){
                            bcc_no[des[tt]] = bcc_cnt;
                        }else{
                            ok= false;
                        }
                        if (tt==t){
                            break;
                        }
                    }
                    if (ok){
                        for (int i=0;i<temp.size();i++){
                            ans.push_back(temp[i]);
                        }
                    }
                }
            }else if (dfn[v]<dfn[u]){
                st[top++] = t;
                low[u] = min(low[u],dfn[v]);
            }
        }
        if (st[top-1]==Eid)top--;
    }
    void solve(){
        for (int i=1;i<=n;i++){
            if (!dfn[i])dfs(i,-1,-1);
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for (int i=0;i<ans.size();i++){
            printf("%d ",ans[i]);
        }
    }
    int main(){
        input();
        solve();
        return 0;
    }