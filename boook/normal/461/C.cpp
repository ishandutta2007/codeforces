#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
typedef long long LL;
typedef pair<int , int> PII;
#define REP(i,j)      for(int i=0;i<j;i++)
#define REPNM(i,j,k)  for(int i=j;i<k;i++)
#define RREP(i,j,k)   for(int i=j;i>=k;i--)
#define MEM(i,j)      memset(i,j,sizeof i)
#define DB() if(debug)
#define DBGG(a,b)      if(debug)cout<<a<<" = "<<b<<endl;
#define DB4(a,b,c,d)   if(debug)cout<<a<<" = "<<b<<"\t\t"<<c<<" = "<<d<<endl;
#define HERE()          if(debug)puts("Here");
#define RI(i)        scanf("%d",&i)
#define RII(i,j)     scanf("%d%d",&i,&j)
#define RIII(i,j,k)  scanf("%d%d%d",&i,&j,&k)
//#define RLL(i) scanf("%I64d",&i)
#define RLL(i) scanf("%I64d",&i)
#define ALL(i) i.begin(),i.end()
#define pb push_back
#define mp make_pair
#define A  first
#define B  second

//  / ----------- default code ----------------
#define MAX   100900
#define INF   0x3f3f3f3f
#define debug 1
#define MOD 1000000007
unsigned myran(){
    static int _ = 87878787;
    return _ * 0xdefaced + 1;
}
class N{
public:

    int pri , siz;
    int v , tag , sum;
    N *l , *r;
    N(int V){
        l = r = NULL;
        pri = rand() , siz = 1;
        v = sum = V;
        tag = 0;
    }
};
int SIZ(N *now){
    return now ? now->siz : 0;
}
int SUM(N *now){
    return now ? now->sum : 0;
}
void push(N *now){
    if(!now)return;
    if(now->tag){
        swap(now->l , now->r);
        if(now->l)now->l->tag = 1 - now->l->tag;
        if(now->r)now->r->tag = 1 - now->r->tag;
        now->tag = 0;
    }
}
void pull(N *now){
    if(!now)return;
    now->siz = 1 + SIZ(now->l) + SIZ(now->r);
    now->sum = now->v + SUM(now->l) + SUM(now->r);
}
N *Merge(N *a , N *b){
    if(!a || !b)return a ? a : b;
    if(a->pri > b->pri){
        push(a);
        a->r = Merge(a->r , b);
        pull(a);
        return a;
    }
    else {
        push(b);
        b->l = Merge(a , b->l);
        pull(b);
        return b;
    }
}
void Split(N *&t , int k , N *&a , N *&b){
    if(!t){a = b = NULL; return;}
    push(t);
    if(SIZ(t->l) + 1 <= k){
        a = t;
        Split(t->r , k - SIZ(t->l) -1 , a->r , b);
        pull(a);
    }
    else {
        b = t;
        Split(t->l , k , a , b->l);
        pull(b);
    }
}
void put(N *now){
    if(!now)return ;
    push(now);
    if(now->l)put(now->l);
    printf("%d ",now->v);
    if(now->r)put(now->r);
}
void ADD(N *&root , int val , int from){
//    DBGG("" , "AADD start");
//    printf("root ->> =") , put(root) , puts("");
    N *left , *mid , *right , *tmp;
    Split(root , from , tmp , right);
    Split(tmp  , from-1 , left , mid);

//    printf("mid  ->> =") , put(mid) , puts("");
//    printf("left ->> =") , put(left) , puts("");
//    printf("right->> =") , put(right) , puts("");
//    if(!mid)puts(">>>>");
    mid->sum += val;
    mid->v   += val;
    root = Merge(left , Merge(mid , right));
//    DBGG("" , "AADD end");
}
int Find(N *&root , int ql , int qr){
//    put(root) , puts("  inside");
    N *left , *mid , *right , *tmp;
    Split(root , qr , tmp , right);
    Split(tmp  , ql ,left , mid);
//    if(!mid)puts("FKKKK");
    int ans = mid->sum;
    root = Merge(left , Merge(mid , right));
//    put(root) , puts("  outside");
    return ans;
}
N* qry(N *&root , int y){
    N *left , *right;
    Split(root , y , left , right);
    if(left->siz <= right->siz){
        int po = 1 , len = left->siz , lpo = left->siz;
        REP(i,len){
//            cout<<"-------------------"<<endl;
//            cout<<"\t\t\t";put(left) ,puts("");
//            cout<<"\t\t\t";put(right) ,puts("");
            int val = Find(left , lpo-1 , lpo);
//            cout<<"\t\t\t";put(left) ,puts("");
//            cout<<"\t\t\t";put(right) ,puts("");
            ADD(right , val , po);
            po++ , lpo--;
//            cout<<"*******************"<<endl;
        }
        return right;
    }
    else{
        int po = left->siz , rpo = 1;
        int len = right->siz;
        REP(i,len){
            int val = Find(right , rpo-1 , rpo);
            ADD(left , val , po);
            po-- , rpo++;
        }
        left->tag = 1 - left->tag;
        return left;
    }
}
int main(){
    srand(time(NULL));
    N *root = NULL;
    int n , m;
    RII(n,m);
    REP(i,n) root = Merge(root , new N(1));

    int pa , pb , pc;
    REP(i,m){
        RI(pa);
        if(pa == 1){
            RI(pb);
            root = qry(root , pb);
//            put(root) , puts("");
        }
        else if(pa == 2){
            RII(pb , pc);
            int ans = Find(root , pb , pc);
            printf("%d\n",ans);
        }
    }
    return 0;
}