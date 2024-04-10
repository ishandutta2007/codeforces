#include <bits/stdc++.h>
using namespace std;


int qu;
string tp[100005];
string a[100005];
int newval[100005];
int t_kol[10000000];
int t_val[10000000];
int sz,sz2;
int leftson_val[10000000];
int leftson_kol[10000000];
int rightson_kol[10000000];
int rightson_val[10000000];
int all1,all2;
map<string,int> pac;
int root_val[100005];
int allnames;
int root_kol[100005];

inline int vcopy_val(int x) {
    ++all1;
    t_val[all1]=t_val[x];
    leftson_val[all1]=leftson_val[x];
    rightson_val[all1]=rightson_val[x];
    return all1;
}
inline int vcopy_kol(int x) {
    ++all2;
    t_kol[all2]=t_kol[x];
    leftson_kol[all2]=leftson_kol[x];
    rightson_kol[all2]=rightson_kol[x];
    return all2;
}

int get_val(int l,int r,int ll,int x) {
    if (!x) return 0;
    if (l==r) return t_val[x];
    int mid=(l+r)>>1;
    if (ll<=mid) return get_val(l,mid,ll,leftson_val[x]);
    else return get_val(mid+1,r,ll,rightson_val[x]);
}

void update_val(int l,int r,int ll,int x,int y) {
    if (l==r) {
        t_val[x]=y;
        return;
    }
    int mid=(l+r)>>1;
    if (ll<=mid) {
        if (!leftson_val[x]) leftson_val[x]=++all1;
        else leftson_val[x]=vcopy_val(leftson_val[x]);
        update_val(l,mid,ll,leftson_val[x],y);
    } else {
        if (!rightson_val[x]) rightson_val[x]=++all1;
        else rightson_val[x]=vcopy_val(rightson_val[x]);
        update_val(mid+1,r,ll,rightson_val[x],y);
    }
}

int get_kol(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr || x==0) return 0;
    if (l>=ll && r<=rr) return t_kol[x];
    int mid=(l+r)>>1;
    return get_kol(l,mid,ll,rr,leftson_kol[x])+get_kol(mid+1,r,ll,rr,rightson_kol[x]);
}

int pacan(string s) {
    int res=pac[s];
    if (!res) return pac[s]=++allnames;
    else return res;
}

void update_kol(int l,int r,int ll,int x,int y) {
    if (l==r) {
        t_kol[x]+=y;
        return;
    }
    int mid=(l+r)>>1;
    if (ll<=mid) {
        if (!leftson_kol[x]) leftson_kol[x]=++all2;
        else leftson_kol[x]=vcopy_kol(leftson_kol[x]);
        update_kol(l,mid,ll,leftson_kol[x],y);
    } else {
        if (!rightson_kol[x]) rightson_kol[x]=++all2;
        else rightson_kol[x]=vcopy_kol(rightson_kol[x]);
        update_kol(mid+1,r,ll,rightson_kol[x],y);
    }
    t_kol[x]+=y;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>qu;
    sz=1;
    while (sz<1e9) sz+=sz;
    sz2=1;
    while (sz2<qu)sz2+=sz2;
    root_val[0]=1;
    root_kol[0]=1;
    all1=1;
    all2=1;
    for (int i=1;i<=qu;++i) {
        cin>>tp[i];
        if (tp[i]!="undo") cin>>a[i];
        if (tp[i]=="set" || tp[i]=="undo") cin>>newval[i];
        if (tp[i]=="set") {
            root_val[i]=vcopy_val(root_val[i-1]);
            root_kol[i]=vcopy_kol(root_kol[i-1]);
            int xx=pacan(a[i]);
            int lastval=get_val(1,sz2,xx,root_val[i]);
            if (lastval!=0) {
                update_kol(1,sz,lastval,root_kol[i],-1);
            }
            update_kol(1,sz,newval[i],root_kol[i],1);
            update_val(1,sz2,xx,root_val[i],newval[i]);
            continue;
        } else if (tp[i]=="remove") {
            root_val[i]=vcopy_val(root_val[i-1]);
            root_kol[i]=vcopy_kol(root_kol[i-1]);
            int xx=pacan(a[i]);
            int lastval=get_val(1,sz2,xx,root_val[i]);
            if (lastval==0) continue;
            update_kol(1,sz,lastval,root_kol[i],-1);
            update_val(1,sz2,xx,root_val[i],0);
            continue;
        } else if (tp[i]=="query") {
            root_val[i]=vcopy_val(root_val[i-1]);
            root_kol[i]=vcopy_kol(root_kol[i-1]);
            int xx=pacan(a[i]);
            int lastval=get_val(1,sz2,xx,root_val[i]);
            if (!lastval) cout<<"-1"<<endl;
            else cout<<get_kol(1,sz,1,lastval-1,root_kol[i])<<endl;
            continue;
        } else {
            root_val[i]=vcopy_val(root_val[i-newval[i]-1]);
            root_kol[i]=vcopy_kol(root_kol[i-newval[i]-1]);
        }
    }
}