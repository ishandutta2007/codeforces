#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> pos[205];
vector<pair<vector<int>,int > > q;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    if (n==2) {
        int m;
        cin>>m;
        cout<<m-1<<" ";
        for (int i=1;i<=m-1;++i){
            int x;
            cin>>x;
            cout<<x<<" ";
        }
        cout<<'\n';
        cout<<1<<" ";
        int x;
        cin>>x;
        cout<<x;
        return 0;
    }
    for (int i=1;i<=(n*(n-1))/2;++i) {
        int m;
        cin>>m;
        for (int j=1;j<=m;++j) {
            int x;
            cin>>x;
            pos[x].push_back(i);
        }
    }
    for (int i=1;i<=200;++i) if (pos[i].size()) {
        sort(pos[i].begin(),pos[i].end());
        q.push_back(make_pair(pos[i],i));
    }
    sort(q.begin(),q.end());
    int i=0;
    while (i<q.size()) {
        int j=i;
        while (j<q.size() && q[j].first==q[i].first) ++j;
        --j;
        cout<<j-i+1<<" ";
        for (int k=i;k<=j;++k)
            cout<<q[k].second<<" ";
        cout<<'\n';
        i=j+1;
    }
}