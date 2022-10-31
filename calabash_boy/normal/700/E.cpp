#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
char s[maxn];int n;
struct Node{int L,R,val;}Tree[maxn*40];
struct Chairman_Tree{
    int cnt = 0;
    int root[maxn*2];
    void init(){
        memset(root,0,sizeof root);
        cnt =0;
    }
    /* T0 */
    int buildT0(int l, int r){
        int k = cnt++;
        Tree[k].val =0;
        if (l==r) return k;
        int mid = l+r >>1;
        Tree[k].L = buildT0(l, mid);Tree[k].R = buildT0(mid + 1, r);
        return k;
    }
    /* Pppos+=del */
    int update (int P,int l,int r,int ppos,int del){
        assert(cnt < maxn*50);
        int k = cnt++;
        Tree[k].val = Tree[P].val +del;
        if (l==r) return k;
        int mid = l+r >>1;
        if (ppos<=mid){
            Tree[k].L = update(Tree[P].L,l,mid,ppos,del);
            Tree[k].R = Tree[P].R;
        }else{
            Tree[k].L = Tree[P].L;
            Tree[k].R = update(Tree[P].R,mid+1,r,ppos,del);
        }
        return k;
    }
    int query(int PL,int PR,int l,int r,int L,int R){
        if (l>R || L>r)return 0;
        if (L <= l && r <= R)return Tree[PR].val - Tree[PL].val;
        int mid = l + r >> 1;
        return query(Tree[PL].L,Tree[PR].L,l,mid,L,R) + query(Tree[PL].R,Tree[PR].R,mid+1,r,L,R);
    }
}tree;
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    int end_pos[maxn*2];
    int POS[maxn*2];
    vector<int> E[maxn*2];
    int dfsl[maxn*2],dfsr[maxn*2],dfn;
    int pos[maxn*2];
    int dp[maxn*2];
    int cntA[maxn*2];
    int st[maxn*2][20];
    int A[maxn*2];
    Suffix_Automaton(){ clear(); }
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while (*s){
            add(*s-'a');s++;
        }
    }
    void add(int c){
        int p = last;
        int np = ++cnt;
        memset(nxt[cnt],0,sizeof nxt[cnt]);
        l[np] = l[p]+1;last = np;
        while (p&&!nxt[p][c])nxt[p][c] = np,p = fa[p];
        if (!p)fa[np]=1;
        else{
            int q = nxt[p][c];
            if (l[q]==l[p]+1)fa[np] =q;
            else{
                int nq = ++ cnt;
                l[nq] = l[p]+1;
                memcpy(nxt[nq],nxt[q],sizeof (nxt[q]));
                fa[nq] =fa[q];fa[np] = fa[q] =nq;
                while (nxt[p][c]==q)nxt[p][c] =nq,p = fa[p];
            }
        }
    }
    void build(){
        for (int i=1;i<=cnt;i++){
            end_pos[i] = -1;
            POS[i] = -1;
        }
        int temp = 1;
        for (int i=0;i<n;i++){
            temp = nxt[temp][s[i] - 'a'];
            end_pos[temp] = i;
            //POS[temp] = i;
            int t = temp;
            while (t != 1 && POS[t] == -1){
                POS[t] = i;
                t = fa[t];
            }
        }
        for (int i=2;i<=cnt;i++){
            E[fa[i]].push_back(i);
        }
    }
    void dfs(int u){
        dfsl[u] = ++ dfn;
        pos[dfn] = u;
        for (int v : E[u]){
            dfs(v);
        }
        dfsr[u] = dfn;
    }
    void main(){
        dfn = 0;
        dfs(1);
        tree.root[0] = tree.buildT0(1,n);
        for (int i=1;i<=cnt;i++){
            int u = pos[i];
            if (end_pos[u]!= -1){
                int idx = end_pos[u] + 1;
                tree.root[i] = tree.update(tree.root[i-1],1,n,idx,1);
            }else{
                tree.root[i] = tree.root[i-1];
            }
        }
    }
    void work(){
        int ans = 1;
        memset(cntA,0,sizeof cntA);
        for (int i=1;i<=cnt;i++){
            st[i][0] = fa[i];
        }
        for (int k=1;k<20;k++){
            for (int i=1;i<=cnt;i++){
                st[i][k] = st[st[i][k-1]][k-1];
            }
        }
        //for (int i=1;i<=cnt;i++){
        //    printf("len[%d]=%d Pos =%d, fa = %d\n",i,l[i],POS[i],fa[i]);
        //}
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=cnt;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        for (int i=2;i<=cnt;i++){
            int x = A[i];
            int temp = x;
            int Pos = POS[temp]+1;
            int Len = l[temp];
            for (int k=19;k>=0;k--){
                int nxt = st[temp][k];
                if (nxt <= 1)continue;
                int cnt = tree.query(tree.root[dfsl[nxt]-1],tree.root[dfsr[nxt]],1,n,Pos - Len + l[nxt],Pos-1);
                if (!cnt)temp = st[temp][k];
            }
            //printf("x=%d temp = %d,Pos = %d,Len = %d\n",x,temp,Pos,Len);
            //cout<<x<<" "<<temp<<" "<<Pos<<" "<<Len<<endl;
            //cout<<x<<" "<<temp<<endl;
            temp = fa[temp];
            dp[x] = dp[temp] + 1;
            ans = max(ans,dp[x]);
        }
        cout<<ans<<endl;
    }
}sam;
int main(){
    scanf("%d%s",&n,s);
    sam.init(s);
    sam.build();
    sam.main();
    sam.work();
    return 0;
}