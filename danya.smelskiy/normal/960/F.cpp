#include <bits/stdc++.h>
using namespace std;


struct node {
    int val,prior,cnt;
    int val2;
    int mx;
    node *l,*r;
    node (int _val,int _val2) {
        val=_val;
        val2=_val2;
        mx=_val2;
        prior=(rand()^(rand()<<15));
        l=NULL;
        r=NULL;
    }
};

typedef node* NODE;

int n,m;
pair<pair<int,int>,pair<int,int> > v[100005];
int ans;
int ans1[100005];
int ans2[100005];

node* root[100005];

int get_cnt(node *T){
    if (!T) return 0;
    return T->mx;
}

void cnt(node *&T) {
    if (!T) return;
    T->mx=max(T->val2,max(get_cnt(T->l),get_cnt(T->r)));
}

void mrg(NODE &T,NODE l,NODE r) {
    if (!l || !r) {
        if (!l) T=r;
        else T=l;
        return;
    }
    if (l->prior>r->prior) {
        mrg(l->r,l->r,r);
        T=l;
    } else {
        mrg(r->l,l,r->l);
        T=r;
    }
    cnt(T);
}

void split(NODE T,int key,NODE &l,NODE &r) {
    if (!T) {
        l=r=NULL;
        return;
    }
    if (T->val<=key) {
        split(T->r,key,T->r,r);
        l=T;
        cnt(l);
    } else {
        split(T->l,key,l,T->l);
        r=T;
        cnt(r);
    }
}


inline int solve(int x,int y) {
    NODE l,r;
    split(root[x],y,l,r);
    int res=1;
    if (l) res=max(res,l->mx+1);
    mrg(root[x],l,r);
    return res;
}

inline void ins(int x,int y,int z) {
    NODE w = new node(y,z);
    NODE l,r;
    split(root[x],y,l,r);
    mrg(root[x],l,w);
    mrg(root[x],root[x],r);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>v[i].second.first>>v[i].second.second;
        cin>>v[i].first.first;
        v[i].first.second=i;
    }
    sort(v+1,v+m+1);
    int x,y;
    int z,zz;
    int i=1;
    int j;
    while (i<=m) {
        j=i;
        while (j<=m && v[j].first.first==v[i].first.first) {
            ++j;
        }
        for (int k=i;k<j;++k) {
            x=v[k].second.first;
            y=v[k].second.second;
            z=v[k].first.second;
            ans1[k]=solve(x,z);
            if (ans1[k]>ans) ans=ans1[k];

        }
        for (int k=i;k<j;++k) {
            x=v[k].second.first;
            y=v[k].second.second;
            ins(y,v[k].first.second,ans1[k]);
        }
        i=j;
    }
    cout<<ans;
}