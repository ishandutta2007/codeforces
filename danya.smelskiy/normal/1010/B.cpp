#include <bits/stdc++.h>
using namespace std;



int n,m;
vector<int> v;
int last;

inline bool f(int x) {
    cout<<x<<endl;
    int res;
    cin>>res;
    if (res<-1 || res>1 || res==0) exit(0);
    return (bool)(res==-1);
}


inline bool f2(int x) {
    ++last;
    if (last==m) last=0;
    bool t=f(x);
    if (v[last]==0) t^=1;
    return t;
}

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        bool t=f(1);
        if (t==false) v.push_back(1);
        else v.push_back(0);
    }
    last=-1;
    int l=1;
    int r=n;
    while (l<r) {
        int mid=(l+r)>>1;
        if (f2(mid)) r=mid-1;
        else l=mid+1;
    }
    f(l);
}