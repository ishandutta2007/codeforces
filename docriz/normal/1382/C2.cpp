#include <bits/stdc++.h>
#define maxn 400005
using namespace std;
typedef pair<int,int> pii;
char ch;
int n,root;
bool ok;
void read(int &x){
    for (ok=0,ch=getchar();!isdigit(ch);ch=getchar()) if (ch=='-') ok=1;
    for (x=0;isdigit(ch);x=x*10+ch-'0',ch=getchar());
    if (ok) x=-x;
}
int random(int mod){return rand()*rand()%mod+1;}
struct fhq_treap{
    int son[maxn][2],add[maxn],rev[maxn],max_val[maxn],val[maxn],siz[maxn];
    void init(){
      memset(siz, 0, (n + 1) * sizeof(int));
      memset(son, 0, 2 * (n + 1) * sizeof(int));
      memset(add, 0, (n + 1) * sizeof(int));
      memset(rev, 0, (n + 1) * sizeof(int));
      memset(max_val, 0, (n + 1) * sizeof(int));
      memset(val, 0, (n + 1) * sizeof(int));
      for (int i = 1; i <= n; i++) siz[i] = 1;
    }
    void Rev(int a){rev[a]^=1;}
    void inc(int a,int v){add[a]+=v,max_val[a]+=v,val[a]+=v;}
    void pushdown(int a){
        if (rev[a]) Rev(son[a][0]),Rev(son[a][1]),rev[a]=0,swap(son[a][0],son[a][1]);
        if (add[a])    inc(son[a][0],add[a]),inc(son[a][1],add[a]),add[a]=0;
    }
    void update(int a){
        siz[a]=1,max_val[a]=val[a];
        if (son[a][0]) siz[a]+=siz[son[a][0]],max_val[a]=max(max_val[a],max_val[son[a][0]]);
        if (son[a][1]) siz[a]+=siz[son[a][1]],max_val[a]=max(max_val[a],max_val[son[a][1]]);
    }
    int merge(int a,int b){
        if (!a||!b) return a+b;
        if (random(siz[a]+siz[b])<=siz[a]){
            pushdown(a),son[a][1]=merge(son[a][1],b),update(a);
            return a;
        }
        else{
            pushdown(b),son[b][0]=merge(a,son[b][0]),update(b);
            return b;
        }
    }
    pii split(int a,int k){
        if (!k) return make_pair(0,a);
        if (siz[a]==k) return make_pair(a,0);
        pushdown(a);
        if (siz[son[a][0]]>=k){
            pii tmp=split(son[a][0],k);
            son[a][0]=tmp.second,update(a);
            return make_pair(tmp.first,a);
        }
        else{
            pii tmp=split(son[a][1],k-siz[son[a][0]]-1);
            son[a][1]=tmp.first,update(a);
            return make_pair(a,tmp.second);
        }
    }
}T;
void add(int l,int r,int x){
    pii t;
    int a,b,c;
    t=T.split(root,r);
    c=t.second;
    t=T.split(t.first,l-1);
    a=t.first,b=t.second;
    T.inc(b,x);
    root=T.merge(a,b),root=T.merge(root,c);
}
void rev(int l,int r){
    pii t;
    int a,b,c;
    t=T.split(root,r);
    c=t.second;
    t=T.split(t.first,l-1);
    a=t.first,b=t.second;
    T.Rev(b);
    root=T.merge(a,b),root=T.merge(root,c);
}
int query(int l,int r){
    pii t;
    int a,b,c;
    t=T.split(root,r);
    c=t.second;
    t=T.split(t.first,l-1);
    a=t.first,b=t.second;
    int ret = T.max_val[b];
    // printf("%d\n",T.max_val[b]);
    root=T.merge(a,b),root=T.merge(root,c);
    return ret;
}
/*
int main(){
    srand('f'+'u'+'c'+'k'+'w'+'m'+'j');
    read(n),read(m),T.init(),root=1;
    for (int i=2;i<=n;i++) root=T.merge(root,i);
    while (m--){
        read(op),read(l),read(r);
        if (op==1) read(x),add(l,r,x);
        else if (op==2) rev(l,r);
        else query(l,r);
    }
    return 0;
}
*/
int main() {
  int TT;
  read(TT);
  while (TT--) {
    read(n);
    T.init();
    root = 1;
    for (int i = 2; i <= n; i++) root = T.merge(root, i);
    string sa, sb;
    cin >> sa;
    cin >> sb;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) {
      a[i] = sa[i - 1] - '0';
      b[i] = sb[i - 1] - '0';
      add(i, i, a[i]);
    }
    vector<int> ans;
    auto go = [&](int p) -> void {
      ans.push_back(p);
      add(1, p, 1);
      rev(1, p);
    };
    for (int i = n; i >= 1; i--) {
      if (query(i, i) % 2 == b[i]) continue;
      if (query(1, 1) % 2 == b[i]) go(1);
      go(i);
    }
    cout << ans.size();
    for (auto v: ans) {
      cout << " " << v;
    }
    cout << "\n";
  }
  return 0;
}