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
const ll MAXN = 200010;
const ll BSIZ= 800;

int A[MAXN];
int N,Q,U,a,b,c,d;
vi ans;

struct node{
    int prior,cnt=0,value,flip;
    node *l,*r;
    node(int _value):value(_value),prior(rand()),l(NULL),r(NULL),flip(0){}
};

inline int cnt(node* &t){
    if(!t)return 0;
    return t->cnt;
}

inline void upd(node* &t){
    if(!t)return;
    t->cnt=1+cnt(t->l)+cnt(t->r);
}

void prop(node* &t){
    if(!t)return;
    if(!t->flip)return;
    if(t->l)t->l->flip^=1;
    if(t->r)t->r->flip^=1;
    t->flip=0;
    swap(t->l,t->r);
}

void merge(node* &t, node* &l, node* &r){
    prop(l);prop(r);
    if(!l)t=r;
    else if(!r)t=l;
    else if(l->prior>r->prior){
        merge(l->r,l->r,r);
        t=l;
    }else{
        merge(r->l,l,r->l);
        t=r;
    }
    upd(t);
}

void split(node* t,node* &l,node* &r,int key){
    prop(t);
    if(!t){l=r=NULL;return;}
    int k=cnt(t->l);
    // cerr<<"Split "<<cnt(t)<<' '<<k<<' '<<key<<'\n';
    if(key<=k){
        split(t->l,l,t->l,key);
        r=t;
    }else if(key==k+1){
        r=t->r;
        t->r=NULL;
        l=t;
    }else{
        split(t->r,t->r,r,key-1-k);
        l=t;
    }
    upd(l);upd(r);
}

void db(node* &t){
    if(!t)return;
    prop(t);
    db(t->l);
    ans.pb(t->value);
    db(t->r);
}

int main(){
    cin>>N>>Q>>U;
    node* root=NULL;

    for(int i=1;i<=N;++i){
        cin>>A[i];
        node* B=new node(A[i]);
        merge(root,root,B);
    }

    for(int i=0;i<Q;++i){
        cin>>a>>b>>c;
        if(a==2){
            c=c-b+1;
            node *B,*C,*D;
            B=C=D=NULL;
            split(root,B,C,b-1);
            split(C,C,D,c);
            C->flip=1;
            // prop(C);
            // cerr<<"B ";db(B);cerr<<'\n';
            // cerr<<"C ";db(C);cerr<<'\n';
            // cerr<<"D ";db(D);cerr<<'\n';
            merge(root,B,C);
            merge(root,root,D);
        }else if(a==1){
            c=c-b+1;
            node *B,*C,*D,*E;
            B=C=D=NULL;
            split(root,B,C,b-1);
            split(C,C,D,c);
            // cerr<<cnt(B)<<' '<<cnt(C)<<' '<<cnt(D)<<'\n';

            split(C,C,E,cnt(C)-1);
            merge(C,E,C);

            merge(root,B,C);
            merge(root,root,D);
        }
    }
    db(root);
    for(int i=0;i<U;++i){
        cin>>a;
        cout<<ans[a-1]<<' ';
    }
}