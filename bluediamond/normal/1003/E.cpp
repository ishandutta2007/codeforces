#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=400000;
int n,d,k;
int deg[N+5];
vector< pair<int,int> >sl;
set< pair<int,int> >s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>d>>k;
    if(d>=n) {
        cout<<"NO\n";
        return 0;
    }
    for(int i=1;i<=d;i++) {
        deg[i]++;
        deg[i+1]++;
        if(deg[i]>k || deg[i+1]>k) {
            cout<<"NO\n";
            return 0;
        }
        sl.push_back(make_pair(i,i+1));
    }
    for(int i=2;i<=d;i++) {
        s.insert(make_pair(max(i-1,d+1-i),i));
    }
    for(int i=d+2;i<=n;i++) {
        while(!s.empty() && deg[s.begin()->second]==k)
            s.erase(s.begin());
        if(s.empty() || s.begin()->first==d) {
            cout<<"NO\n";
            return 0;
        }
        deg[s.begin()->second]++;
        deg[i]++;
        sl.push_back(make_pair(s.begin()->second,i));
        s.insert(make_pair(s.begin()->first+1,i));
    }
    cout<<"YES\n";
    for(auto itr:sl) {
        cout<<itr.first<<" "<<itr.second<<"\n";
    }
    return 0;
}
/**

n-(d+2)+1 = n-d-1

**/