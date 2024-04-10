#include <bits/stdc++.h>
using namespace std;



int n,m,pos;
string s,ss;
int l[500005];
int r[500005];
int q[500005];
int sz;
int p[500005];
inline void del(int ll,int rr){
    l[r[rr]]=l[ll];
    r[l[ll]]=r[rr];
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>pos;
    cin>>s;
    cin>>ss;
    r[0]=1;
    l[n+1]=n;
    for (int i=1;i<=n;++i) {
        l[i]=i-1;
        r[i]=i+1;
        if (s[i-1]=='(') q[++sz]=i;
        else {
            p[q[sz]]=i;
            p[i]=q[sz];
            --sz;
        }
    }
    for (int i=1;i<=ss.size();++i) {
        if (ss[i-1]=='L') pos=l[pos];
        else if (ss[i-1]=='R') pos=r[pos];
        else {
            int ll=pos;
            int rr=p[ll];
            if (ll>rr) swap(ll,rr);
            if (r[rr]>n) pos=l[ll];
            else pos=r[rr];
            del(ll,rr);
        }
    }
    pos=0;
    while (pos<=n) {
        if (pos) cout<<s[pos-1];
        pos=r[pos];
    }
}