#include<bits/stdc++.h>
using namespace std;

struct Trie{
    struct node{
        node *nxt[2];
        int sz,cnt;
        node(){
            sz=cnt=0;
            memset(nxt,0,sizeof(nxt));
        }
    };

    int poolsz;
    node *pool,*root;
    node* getnode(){
        if(!poolsz){
            pool=new node[poolsz=114514];
        }
        poolsz--;
        return pool++;
    }

    Trie(){
        poolsz=0;
        root=getnode();
    }

    void insert(int s){
        node *p=root;
        for(int i=18;i>=0;i--){
            if(p->nxt[s>>i&1]==nullptr)p->nxt[s>>i&1]=getnode();
            p->sz++;
            p=p->nxt[s>>i&1];
        }
        p->sz++;
    }

    int find(int s){
        node *p=root;
        int res=0;
        for(int i=18;i>=0;i--){
            if(p->nxt[s>>i&1]==nullptr){
                return res;
            }else if(p->nxt[s>>i&1]->sz<1<<i){
                p=p->nxt[s>>i&1];
            }else if(p->nxt[s>>i&1^1]==nullptr){
                return res|1<<i;
            }else{
                p=p->nxt[s>>i&1^1];
                res|=1<<i;
            }
        }
        return res;
    }
};

int n,q;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    Trie t;
    set<int> ps;
    for(int i=0;i<n;i++){
        int s;
        cin>>s;
        if(!ps.count(s)){
            t.insert(s);
            ps.insert(s);
        }
    }
    int x=0;
    while(q--){
        int y;
        cin>>y;
        x^=y;
        cout<<t.find(x)<<'\n';
    }

    return 0;
}