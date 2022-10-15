#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

struct info {
    int i;
    int x;
    int l;
};

bool operator < (info a,info b) {
    if(a.l==b.l) {
        return a.i<b.i;
    }
    return a.l>b.l;
}

const int N=200000+5;

int sz,n;
info v[N];

int st[N];
int dr[N];

set<info>s;

void sterge(int i) {
    s.erase(v[i]);
    dr[st[i]]=dr[i];
    st[dr[i]]=st[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>sz;
    n=1;
    v[1].i=1;
    cin>>v[1].x;
    v[1].l=1;
    for(int i=2;i<=sz;i++) {
        int x;
        cin>>x;
        if(x!=v[n].x) {
            n++;
            v[n].i=n;
            v[n].x=x;
        }
        v[n].l++;
    }
    for(int i=1;i<=n;i++) {
        st[i]=i-1;
        dr[i]=i+1;
        s.insert(v[i]);
    }
    int answer=0;
    while(!s.empty()) {
        answer++;
        info val=*s.begin();
        sterge(val.i);
        int p1=st[val.i];
        int p2=dr[val.i];
        if(1<=p1 && p1<=p2 && p2<=n) {
            if(v[p1].x!=v[p2].x) {
                continue;
            }
            sterge(p2);
            s.erase(v[p1]);
            v[p1].l+=v[p2].l;
            s.insert(v[p1]);
        }
    }
    cout<<answer<<"\n";
    return 0;
}
/**

**/