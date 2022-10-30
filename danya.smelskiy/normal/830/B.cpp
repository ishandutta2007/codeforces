#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[100005];
long long ans;
int f[100005];


inline void update(int x,int y) {
    for (int i=x;i<=n;i=(i|(i+1)))
        f[i]+=y;
}

int get(int x) {
    int res=0;
    while (x>=0) {
        res+=f[x];
        x=(x&(x+1))-1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    for (int i=1;i<=n;++i)
        update(i,1);
    int last=0;
    for (int i=1;i<=100000;++i)
    if (v[i].size()) {
        int pos=0;
        while (pos<v[i].size() && v[i][pos]<last) ++pos;
        if (pos==v[i].size()) {
            ans+=get(n)-get(last);
            last=0;
            pos=0;
        }
        for (int j=0;j<v[i].size();++j) {
            int x=v[i][pos++];
            if (pos==v[i].size()) pos=0;
            if (x>=last) ans+=get(x)-get(last);
            else ans+=get(n)-get(last)+get(x);
            update(x,-1);
            last=x;
        }
    }
    cout<<ans;
}