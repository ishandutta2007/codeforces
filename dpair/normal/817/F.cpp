#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define putlen putchar('\n')

//
inline ll read(){
    ll X=0; bool flag=1; char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
    while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
    if(flag) return X;
    return ~(X-1);
}
//
inline void print(ll x){
    if(x<0){putchar('-');x=-x;}
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

struct node{
    ll l,r;
    mutable int val;
    bool operator<(const node &a)const {return l<a.l;}
    node(ll L,ll R,int Val):l(L),r(R),val(Val){}
    node(ll L):l(L){}
};

set<node> s;
using si = set<node>::iterator;

inline si split(ll pos){
    si it = s.lower_bound(node(pos));
    if(it != s.end() && it->l==pos) return it;
    --it;
    ll l=it->l,r=it->r;
    int val = it->val;
    s.erase(it);
    s.insert(node(l,pos-1,val));
    return s.insert(node(pos,r,val)).first;
}

inline void assign(ll l,ll r,int val){
    si itr=split(r+1),itl=split(l);
    s.erase(itl,itr);
    s.insert(node(l,r,val));
}
//0110
inline void rever(ll l,ll r){
    si itr=split(r+1),itl=split(l);
    for(si it=itl;it!=itr;++it)
        it->val=!it->val;
}

int n;

int main(){
    n=read();
    s.insert(node(1,1e19,0));
    while(n--){
        ll flag=read(),l=read(),r=read();
        if(flag == 1)      assign(l,r,1);
        else if(flag == 2) assign(l,r,0);
        else if(flag == 3) rever(l,r);
		//
        for(si it=s.begin();it!=s.end();++it)
            if(!it->val){
                print(it->l),putlen;
                break;
            }
    }
    return 0;
}