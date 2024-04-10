#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

map<int,int>mp;
set<int>s;

inline void add(int x) {
    if(mp[x]==0) {
        s.insert(x);
    }
    if(mp[x]==1) {
        s.erase(x);
    }
    mp[x]++;
}

inline void del(int x) {
    if(mp[x]==1) {
        s.erase(x);
    }
    if(mp[x]==2) {
        s.insert(x);
    }
    mp[x]--;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        add(-v[i]);
        if(i>=k) {
            if(s.size()==0) {
                cout<<"Nothing\n";
            }
            else {
                cout<<-*s.begin()<<"\n";
            }
            del(-v[i-k+1]);
        }
    }
    return 0;
}
/**


**/