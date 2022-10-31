#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 100;
const int mod = 1e9 + 7;
struct Trie{
    int nxt[maxn][11];
    int fa[maxn];
    int dep[maxn];
    int ch_fa[maxn];
    int last = 1;
    int root = 1;
    int insert(int p,char *s,int len){
        for (int i=0;i<len;i++){
            int ch = s[i] - '0';
            if (!nxt[p][ch]){
                nxt[p][ch] = ++last;
                fa[last] = p;
                ch_fa[last] = ch;
                dep[last] = dep[p] + 1;
                st[last][0] = fa[last];
                for (int step=1;step<20;step++){
                    st[last][step] = st[st[last][step-1]][step-1];
                    if (!st[last][step])break;
                }
            }
            p = nxt[p][ch];

        }
        return p;
    }
    int st[maxn][20];

    tuple<int,int,int> lca(int x,int y){
        if (x == y)return make_tuple(x,0,0);
        bool rev = false;
        if (dep[x] < dep[y]){
            swap(x,y);
            rev = true;
        }
        for (int i=19;i>=0;i--){
            if (dep[st[x][i]] >= dep[y]){
             //   cerr<<"debug "<<i<<" "<<x<<" "<<st[x][i]<<" "<<dep[st[x][i]]<<" "<<dep[y]<<endl;
                x = st[x][i];
            }
        }
        if (x == y){
            if (!rev)return make_tuple(x,10,0);
            else return make_tuple(x,0,10);
        }
        for (int i=19;i>=0;i--){
            if (st[x][i] != st[y][i]){
                x = st[x][i];
                y = st[y][i];
            }
        }
        if (!rev)return make_tuple(st[x][0],ch_fa[x],ch_fa[y]);
        else return make_tuple(st[x][0],ch_fa[y],ch_fa[x]);
    }
}trie;
int n,m;
vector<pair<int,int> > E[maxn];
int dis[maxn];
bool used[maxn];
bool small(int posy,int yx,int posx,int x){
    if (posx == 2 && posy != 2)return true;
    if (posy == 2 && posx != 2)return false;
    if (posx == 2 && posy == 2)return false;
    if (trie.dep[posx] != trie.dep[posy])return trie.dep[posy] < trie.dep[posx];
   // cerr<<"lca: "<<posy<<" "<<posx<<endl;
    auto tp = trie.lca(posx,posy);
    int lca,chx,chy;
    tie(lca,chx,chy) = tp;
   // cerr<<"lca: "<<lca<<" "<<chy<<" "<<chx<<endl;
    if (chx == chy)return yx < x;
    return chy < chx;
}
struct Node{
    int x;
    int pos;
    Node(int x_,int pos_){
        x = x_;
        pos = pos_;
    }
    bool operator < (const Node & other)const{
        int posx = pos;
        int posy = other.pos;
        return small(posy,other.x,posx,x);
    }
};
int pos[maxn];
int main(){
    trie.dep[0] = -1;
    trie.last = 2;
    trie.nxt[0][10] = 2;
    trie.fa[2] = 1;
    trie.ch_fa[2] = 10;
    trie.st[2][0] = 1;
    trie.dep[2] = 1;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        E[u].push_back(make_pair(v,i));
        E[v].push_back(make_pair(u,i));
    }
    priority_queue<Node> pq;
    for (int i=2;i<=n;i++){
        pos[i] = 2;
        pq.push(Node(i,2));
    }
    pos[1] = 1;
    pq.push(Node(1,1));
    while (!pq.empty()){
        auto node = pq.top();
       // cerr<<"pq:"<<node.x<<" "<<node.pos<<endl;
        pq.pop();
        if (used[node.x])continue;
        used[node.x] = 1;
        for (auto e : E[node.x]){
            int v,cost;
            tie(v,cost) = e;
            static char s[100];
            int len = 0;
            int cc = cost;
            while (cost){
                s[len++] = cost % 10 + '0';
                cost /= 10;
            }
            reverse(s,s+len);
           // cerr<<"edge:"<<v<<" "<<s<<endl;
            int temp_pos = trie.insert(node.pos,s,len);
          //  cerr<<"trie "<<temp_pos<<endl;
            if (small(temp_pos,v,pos[v],v)){
                //update
                dis[v] = dis[node.x];
                pos[v] = temp_pos;
                for (int i=0;i<len;i++){
                    dis[v] = 1ll *dis[v] * 10 % mod;
                }
                dis[v] += cc;
             //   cerr<<"optimize "<<v<<" "<<dis[v]<<endl;
                dis[v] %= mod;
                pq.push(Node(v,temp_pos));
            }
        }
    }
    for (int i=2;i<=n;i++){
        printf("%d\n",dis[i]);
    }
    return 0;
}