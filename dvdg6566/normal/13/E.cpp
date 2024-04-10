#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 100010;
const ll BSIZ= 800;
 

struct node{
    int prior,val,cnt=1,w,subw,cst,subcst;
    node *l, *r, *p;
    node(int val,int cw, int cst):val(val),prior(rand()),w(cw),cst(cst),subcst(0){
        l=r=p=nullptr;
    }
};

inline int cnt(node* t){
    if(!t)return 0;
    return t->cnt;
}

inline int subw(node* t){
    if(!t)return 0;
    return t->subw;
}

inline int subcst(node* t){
    if(!t)return 0;
    return t->subcst;
}

inline void upd(node* &t){
    if(!t)return;
    t->cnt=1+cnt(t->l)+cnt(t->r);
    t->subw=t->w+subw(t->l)+subw(t->r);
    t->subcst=t->cst+subcst(t->l)+subcst(t->r);
}

void merge(node* &t, node* &l, node* &r){
    if(!l)t=r;
    else if(!r)t=l;
    else if(l->prior > r->prior){
        // if(l->r)l->r->p=nullptr;
        merge(l->r,l->r,r);
        l->r->p=l;
        t=l;
    }else{
        // if(r->l)r->l->p=nullptr;
        merge(r->l,l,r->l);
        r->l->p=r;
        t=r;
    }
    upd(t);
}

void split(node* t, node* &l, node* &r, int key){
    if(!t){l=r=nullptr;return;}
    int k=cnt(t->l);
    if(k+1==key){
        r=t->r;
        if(r)r->p=nullptr;
        t->r=nullptr;
        l=t;
    }else if(k >= key){
        t->l->p=nullptr;
        split(t->l,l,t->l,key);
        if(t->l)t->l->p=t;
        r=t;
    }else{
        t->r->p=nullptr;
        split(t->r,t->r,r,key-1-k);
        if(t->r)t->r->p=t;
        l=t;
    }
    upd(l);upd(r);
}

int count_index(node* &t,int side=1){
    if(!t)return 0;
    int cur=0;
    if(side==1)cur+=cnt(t->l)+1;
    node* A=t->p;
    if(!A){
        return cur;
    }else if(A->l==t){
        return cur+count_index(A,0);
    }else{
        return cur+count_index(A,1);
    }
}

int get_height(node* &t, int side=1){
    if(!t)return 0;
    int cur=0;
    if(side==1)cur+=subw(t->l)+t->w;
    node* A=t->p;
    if(!A){
        return cur;
    }else if(A->l==t){
        return cur+get_height(A,0);
    }else{
        return cur+get_height(A,1);
    }
}

int N,Q,a,b,c;
int A[MAXN];
vi V[MAXN];
vi pred;
int B[MAXN];
int D[MAXN];
node* opens[MAXN];
node* closes[MAXN];
node* root;

void dfs(int x){
    pred.pb(x);
    for(auto v:V[x])dfs(v);
    pred.pb(x);
}

void reroot(int a,int b){
    int leftcut=count_index(opens[a])-1;
    int rightcut=count_index(closes[a]);
    node *A,*B,*C;
    split(root,root,C,rightcut);
    split(root,A,B,leftcut);
    merge(root,A,C);
    int ins=count_index(opens[b]);
    split(root,A,C,ins);
    merge(root,A,B);
    merge(root,root,C);
}

void update(node* &t){
    if(!t)return;
    upd(t);
    update(t->p);
}

int find_first(node* &t, int side=1){
    if(!t){assert(0);return 0;}
    if(side==2){
        assert(subcst(t));
        if(subcst(t->r))return find_first(t->r,2);
        else if(t->cst){
            return t->val;
        }
        else return find_first(t->l,2);
    }
    if(side==1&&t->cst)return t->val;
    if(side==1 && subcst(t->l))return find_first(t->l,2);
    node* A=t->p;
    assert(A);
    if(A->l==t){
        return find_first(A,0);
    }else return find_first(A,1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    root=nullptr;
    cin>>N>>Q;
    for(int i=1;i<=N;++i){
        cin>>A[i];
        int t=A[i]+i;
        t=min(N+1,t);
        D[i]=t;
        V[t].pb(i);
    }
    for(int i=1;i<=N+1;++i)B[i]=1;
    dfs(N+1);
    for(auto i:pred){
        int cst=0;
        if(A[i]+i>N&&B[i]==1)cst=1;
        node* A=new node(i,B[i],cst);
        if(B[i]==1)opens[i]=A;
        else closes[i]=A;
        B[i]=-1;
        merge(root,root,A);
    }
    while(Q--){
        cin>>a;
        if(a==1){
            // for(int i=1;i<=N;++i)if(opens[i]->cst||closes[i]->cst){
            //     cerr<<i<<' ';
            // }
            cin>>b;
            cout<<find_first(opens[b])<<' '<<get_height(opens[b])-1<<'\n';
        }else{
            cin>>b>>c;
            int nt=min(N+1,c+b);
            if(nt==N+1&&D[b]!=N+1){
                // assert(opens[b]->cst==0);
                opens[b]->cst=1;
                update(opens[b]);
            }else if(nt!=N+1&&D[b]==N+1){
                // assert(opens[b]->cst==1);
                opens[b]->cst=0;
                update(opens[b]);
            }
            D[b]=nt;
            reroot(b,nt);
        }
    }

}