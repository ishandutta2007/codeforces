#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int>v[5][5];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<int>p(n);
    vector<int>a(n);
    for(int i=0;i<n;i++) {
        cin>>p[i];
    }
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        int b;
        cin>>b;
        v[min(a[i],b)][max(a[i],b)].push_back(p[i]);
    }
    for(int i=1;i<=3;i++) {
        for(int j=1;j<=3;j++) {
            sort(v[i][j].rbegin(),v[i][j].rend());
        }
    }
    int q;
    cin>>q;
    while(q--) {
        int col;
        cin>>col;
        int mi=(1<<30);
        for(int i=1;i<=3;i++) {
            int x=min(col,i);
            int y=max(col,i);
            if(v[x][y].size()) {
                mi=min(mi,v[x][y].back());
            }
        }
        if(mi==(1<<30)) {
            cout<<"-1 ";
            continue;
        }
        for(int i=1;i<=3;i++) {
            int x=min(col,i);
            int y=max(col,i);
            if(v[x][y].size()) {
                if(mi==v[x][y].back()) {
                    cout<<mi<<" ";
                    v[x][y].pop_back();
                    break;
                }
            }
        }
    }
    cout<<"\n";
    return 0;
}
/**

**/