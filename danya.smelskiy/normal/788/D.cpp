#include <bits/stdc++.h>
using namespace std;





vector<int> v1,v2,vv;
map<int,bool> used1;


inline int get_dist(int x,int y) {
    cout<<"0 "<<x<<" "<<y<<endl;
    int res;
    cin>>res;
    return res;
}

inline void add(int x) {
    if (!used1.count(x) && get_dist(x,x)==0) {
        used1[x]=true;
        vv.push_back(x);
    }
}

void solve(int l,int r) {
    if (l+1>=r) return;
    int mid=(l+r)/2;
    add(mid);
    int d=get_dist(mid,mid);
    if (mid-d>l) add(mid-d);
    if (mid+d<r) add(mid+d);
    solve(l,mid-d);
    solve(mid+d,r);
}

inline void solve_h(int x) {
    if (get_dist(x,228228)==0) {
        v1.push_back(x);
    }
}

inline void solve_v(int x) {
    if (get_dist(228228,x)==0) {
        v2.push_back(x);
    }
}

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    add(-1e8);
    add(1e8);
    solve(-1e8,1e8);
    int x;
    sort(vv.begin(),vv.end());
    for (int i=0;i<vv.size();++i) {
        x=vv[i];
        solve_h(x);
        solve_v(x);
    }
    cout<<1<<" "<<v1.size()<<" "<<v2.size()<<endl;
    for (int i=0;i<v1.size();++i)
        cout<<v1[i]<<" ";
    cout<<endl;
    for (int i=0;i<v2.size();++i)
        cout<<v2[i]<<" ";
}