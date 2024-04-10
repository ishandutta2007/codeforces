#include <bits/stdc++.h>
using namespace std;




int n,m;
int x[100005];
int y[100005];
int p[100005];
vector<int> res;
vector<int> q1,q2;

inline void no(){
    cout<<"-1";
    exit(0);
}
int get(int x){
    if (x==p[x]) return x;
    return p[x]=get(p[x]);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>x[i]>>y[i];
        char z;
        cin>>z;
        if (z=='S') q1.push_back(i);
        else q2.push_back(i);
    }
    if (n%2==0) no();
    for (int i=1;i<=n;++i)
        p[i]=i;
    int kol=n;
    for (int i=0;i<q1.size();++i) {
        int xx=x[q1[i]];
        int yy=y[q1[i]];
        xx=get(xx);
        yy=get(yy);
        if (xx==yy) continue;
        p[xx]=yy;
        --kol;
    }
    if (kol-1>(n/2)) no();
    int kol2=0;
    for (int i=0;i<q2.size();++i) {
        int xx=x[q2[i]];
        int yy=y[q2[i]];
        xx=get(xx);
        yy=get(yy);
        if (xx==yy) continue;
        p[xx]=yy;
        --kol;
        res.push_back(q2[i]);
    }
    if (kol>1) no();
    for (int i=1;i<=n;++i)
        p[i]=i;
    for (int i=0;i<res.size();++i) {
        int xx=x[res[i]];
        int yy=y[res[i]];
        xx=get(xx);
        yy=get(yy);
        if (xx!=yy) p[xx]=yy;
    }
    for (int i=0;i<q2.size() && res.size()<n/2;++i) {
        int xx=x[q2[i]];
        int yy=y[q2[i]];
        xx=get(xx);
        yy=get(yy);
        if (xx!=yy) {
            p[xx]=yy;
            res.push_back(q2[i]);
        }
    }
    if (res.size()!=n/2) no();
    for (int i=0;i<q1.size();++i) {
        int xx=x[q1[i]];
        int yy=y[q1[i]];
        xx=get(xx);
        yy=get(yy);
        if (xx!=yy) {
            p[xx]=yy;
            res.push_back(q1[i]);
        }
    }
    kol=0;
    for (int i=1;i<=n;++i)
        if (p[i]==i) ++kol;
    if (kol>1) no();
    cout<<res.size()<<'\n';
    for (int i=0;i<res.size();++i)
        cout<<res[i]<<" ";
}