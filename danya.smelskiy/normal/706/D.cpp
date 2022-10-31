#include <bits/stdc++.h>
using namespace std;



long long sz;
struct st{
    long long a[3];
};
long long n,x;
long long kol[3000001];
long long ans[3000001];
bool t;
long long res,last;
st q[3000001];
inline int b(){
    ++sz;
    q[sz].a[0]=-1;
    q[sz].a[1]=-1;
    return sz;
}
void add(long long x,long long y,long long r){
    if (y==-1) return;
    bool z=(r&(1<<y));
    if (q[x].a[z]==-1) q[x].a[z]=b();
    ++kol[q[x].a[z]];
    add(q[x].a[z],y-1,r);
}
void del(long long x,long long y,long long r){
    if (y==-1) return;
    bool z=(r&(1<<y));
    --kol[q[x].a[z]];
    del(q[x].a[z],y-1,r);
}
void get(long long x,long long y,long long r){
    if (y==-1) return;
    bool z=(r&(1<<y));
    long long p=(z^1);
    if (q[x].a[p]!=-1 && kol[q[x].a[p]]>0) {
        ans[y]=1;
        get(q[x].a[p],y-1,r);
    } else {
        ans[y]=0;
        get(q[x].a[z],y-1,r);
    }
}
void f(long long x,long long y,long long z){
    if (y==-1) return;
    bool k=z&(1<<y);
    if (q[x].a[k]==-1 || kol[q[x].a[k]]==0) t=true;
    else f(q[x].a[k],y-1,z);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    b();
    add(1,31,0);
    for (int i=1;i<=n;++i) {
        char c;
        cin>>c>>x;
        if (c=='+') add(1,31,x);
        else if (c=='-') del(1,31,x);
        else if (c=='?') {
            res=0;
            last=0;
            get(1,31,x);
            long long p=1;
            for (int j=0;j<=31;++j){
                res=res+p*ans[j];
                p+=p;
            }
            cout<<res<<'\n';
        }
    }
}