#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+100;
int n;
vector<int> fac[maxn];
bool vis[maxn];
struct Trie_Node{
    static int cnt;
    int nxt[2];
    int minn;
    Trie_Node(){
        minn=INF;
        memset(nxt,0,sizeof nxt);
    }
    static int newnode(){
        return ++cnt;
    }
}Node_Pool[(int)2e7];
int Trie_Node::cnt=0;
struct Trie{
    int root;
    void insert(int Val){
        int now = root;
        for (int i=17;i>=0;i--){
            bool d = (Val&(1<<i));
            if (!Node_Pool[now].nxt[d]){
                Node_Pool[now].nxt[d] = Trie_Node::newnode();
            }
            now = Node_Pool[now].nxt[d];
            Node_Pool[now].minn = min(Node_Pool[now].minn,Val);
        }
    }
    int query(int Val,int limit){
        int now = root;
        for (int i=17;i>=0;i--){
            bool d = (Val&(1<<i));
            if (Node_Pool[now].nxt[d^1]&&Node_Pool[Node_Pool[now].nxt[d^1]].minn+Val<=limit){
                now = Node_Pool[now].nxt[d^1];
            }else if (Node_Pool[now].nxt[d]&&Node_Pool[Node_Pool[now].nxt[d]].minn+Val<=limit){
                now = Node_Pool[now].nxt[d];
            }else return -1;
        }
        return Node_Pool[now].minn;
    }
}trie[101];
void init(){
    for (int i=1;i<=1e5;i++){
        for (int j=i;j<=1e5;j+=i){
            fac[j].push_back(i);
        }
    }
    for (int i=1;i<=100;i++){
        trie[i].root = Trie_Node::newnode();
    }
}
int baoli(int k,int x,int s){
    int ret =-1;
    for (int f=k;f+x<=s;f+=k){
        if (vis[f]){
            ret = max(ret,x^f);
        }
    }
    if (ret!=-1)ret^=x;
    return ret;
}
int main(){
    init();
    scanf("%d",&n);
    while (n--){
        int opt;
        scanf("%d",&opt);
        if (opt==1){
            int x;
            scanf("%d",&x);
            vis[x]=1;
            for (int f:fac[x]){
                if (f<=100)trie[f].insert(x);
            }
        }else{
            int x,k,s;
            scanf("%d%d%d",&x,&k,&s);
            if (x%k!=0){
                puts("-1");
                continue;
            }
            if (k<=100){
                printf("%d\n",trie[k].query(x,s));
            }else{
                printf("%d\n",baoli(k,x,s));
            }
        }
    }
    return 0;
}