// Created by calabash_boy on 18-6-4.
//SPOJ substring
// calc ans_i==i
#include<bits/stdc++.h>
#define RIGHT
//RIGHT: parentdfsRight
using namespace std;
const int maxn = 2e5+100;
struct Node{int L,R,val;}Tree[maxn*50];
#ifdef RIGHT
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
#endif
char s[maxn];int n,ans[maxn];
/*lparent*/
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
#ifdef RIGHT
    vector<int> E[maxn*2];
    int dfsl[maxn*2],dfsr[maxn*2],dfn;
    int pos[maxn*2];
    int end_pos[maxn*2];//1
#endif
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
#ifdef RIGHT
    void dfs(int u){
        dfsl[u] = ++ dfn;
        pos[dfn] = u;
        for (int v : E[u]){
            dfs(v);
        }
        dfsr[u] = dfn;
    }
    void extract_right(){
        int temp = 1;
        for (int i=0;i<n;i++){
            temp = nxt[temp][s[i] - 'a'];
            end_pos[temp] = i+1;
        }
        for (int i=2;i<=cnt;i++){
            E[fa[i]].push_back(i);
        }
        dfn = 0;
        dfs(1);
        tree.root[0] = tree.buildT0(1,n);
        for (int i=1;i<=cnt;i++){
            int u = pos[i];
            if (end_pos[u]){
                int idx = end_pos[u];
                tree.root[i] = tree.update(tree.root[i-1],1,n,idx,1);
            }else{
                tree.root[i] = tree.root[i-1];
            }
        }
    }
#endif
    void query(int L,int R,char *t,int n){
        stack<int> stk;
        while (!stk.empty())stk.pop();
        int temp = 1;
        for (int i=0;i<n;i++){
            int ch = t[i] - 'a';
            if (!nxt[temp][ch])break;
            temp = nxt[temp][ch];
            int len = i + 1;
            int cnt = tree.query(tree.root[dfsl[temp]-1],tree.root[dfsr[temp]],1,::n,L+len-1,R);
            if (cnt<0)while(1);
            //cout<<dfsl[temp]-1<<" "<<dfsr[temp]<<" "<<1<<" "<<n<<" "<<L+len-1<<" "<<R<<endl;
            //cout<<len<<" "<<temp<<" "<<L+len-1<<" "<<R<<" "<<cnt<<endl;
            //cout<<dfsl[temp]-1<<" "<<dfsr[temp]<<endl;
            if (!cnt)break;
            stk.push(temp);
        }
        while (1){
            int cp_len = stk.size();
            int u = stk.empty()?1:stk.top();
            int least_ch = cp_len == n?0:t[cp_len]-'a'+1;
            for (int nxt_ch = least_ch;nxt_ch < 26;nxt_ch ++){
                if (!nxt[u][nxt_ch])continue;
                int nxt_u = nxt[u][nxt_ch];
                int len = cp_len + 1;
                int cnt = tree.query(tree.root[dfsl[nxt_u] - 1],tree.root[dfsr[nxt_u]],1,::n,L+len-1,R);
                if (!cnt)continue;
                t[cp_len] = 'a' + nxt_ch;
                t[cp_len+1] = '\0';
                puts(t);
                return;
            }
            if (!cp_len){
                puts("-1");
                return;
            }
            stk.pop();
        }
    }
    void debug(){
        for (int i=1;i<=cnt;i++){
            for (int j=0;j<26;j++){
                if (nxt[i][j]){
                    printf("%d -> %d ch = %c\n",i,nxt[i][j],'a'+j);
                }
            }
        }
        for (int i=2;i<=cnt;i++){
            printf("fa[%d]=%d\n",i,fa[i]);
        }

    }
}sam;
char t[maxn];
int main(){
    scanf("%s",s);
    /* calc n must before sam.init()*/
    n = strlen(s);
    sam.init(s);
    //sam.debug();
    sam.extract_right();
    //printf("debug:%d\n",tree.query(tree.root[sam.dfsl[3]-1],tree.root[sam.dfsr[3]],1,n,2,2));
    int q;
    scanf("%d",&q);
    while (q--){
        int L,R;
        scanf("%d%d%s",&L,&R,t);
        int len = strlen(t);
        sam.query(L,R,t,len);
    }
    return 0;
}