#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,sz;

ll dat[400005];
ll laz[400005];

void upd(int bk,int l,int r,int ql,int qr,ll val){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        laz[bk]+=val;
        dat[bk]+=val*(r-l+1);
        return;
    }
    laz[bk<<1]+=laz[bk];
    dat[bk<<1]+=laz[bk]*((r-l+1)>>1);
    laz[bk<<1|1]+=laz[bk];
    dat[bk<<1|1]+=laz[bk]*((r-l+1)>>1);
    laz[bk]=0;
    upd(bk<<1,l,(l+r)>>1,ql,qr,val);
    upd(bk<<1|1,((l+r)>>1)+1,r,ql,qr,val);
    dat[bk]=dat[bk<<1]+dat[bk<<1|1];
}

ll qry(int bk,int l,int r,int ql,int qr){
    if(qr<l||r<ql)return 0;
    if(ql<=l&&r<=qr){
        return dat[bk];
    }
    laz[bk<<1]+=laz[bk];
    dat[bk<<1]+=laz[bk]*((r-l+1)>>1);
    laz[bk<<1|1]+=laz[bk];
    dat[bk<<1|1]+=laz[bk]*((r-l+1)>>1);
    laz[bk]=0;
    return qry(bk<<1,l,(l+r)>>1,ql,qr)+qry(bk<<1|1,((l+r)>>1)+1,r,ql,qr);
}

struct Node_t {
  int l, r;
  mutable int v;
  Node_t(const int &il, const int &ir, const int &iv) : l(il), r(ir), v(iv) {}
  inline bool operator<(const Node_t &o) const { return l < o.l; }
};

set<Node_t> odt;

auto split(int x) {
  if (x > n) return odt.end();
  auto it = --odt.upper_bound((Node_t){x, 0, 0});
  if (it->l == x) return it;
  int l = it->l, r = it->r, v = it->v;
  odt.erase(it);
  odt.insert(Node_t(l, x - 1, v));
  return odt.insert(Node_t(x, r, v)).first;
}

void assign(int l, int r, int v) {
  auto itr = split(r + 1), itl = split(l);
  for(auto it=itl;it!=itr;it++)upd(1,1,sz,it->l,it->r,abs(v-it->v));
  odt.erase(itl, itr);
  odt.insert(Node_t(l, r, v));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    sz=1;
    while(sz<n)sz<<=1;
    for(int i=1;i<=n;i++)odt.insert(Node_t(i,i,i));
    while(m--){
        int typ,l,r,x;
        cin>>typ>>l>>r;
        if(typ==1){
            cin>>x;
            assign(l,r,x);
        }else{
            cout<<qry(1,1,sz,l,r)<<endl;
        }
    }

    return 0;
}