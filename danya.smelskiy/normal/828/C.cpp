#include <bits/stdc++.h>
using namespace std;


int n;
set<pair<int,int> > s;
string ss[100005];
int m,x;
vector<pair<int,int> > v[3000001],vv[3000001];
int r;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>ss[i];
        cin>>m;
        for (int j=1;j<=m;++j) {
            cin>>x;
            if (x+(int)ss[i].size()-1>r) r=x+(int)ss[i].size()-1;
            v[x].push_back(make_pair(x,i));
            vv[x+ss[i].size()].push_back(make_pair(x,i));
        }
    }
    for (int i=1;i<=r;++i) {
        for (int j=0;j<vv[i].size();++j) {
            pair<int,int> x=vv[i][j];
            s.erase(x);
        }
        for (int j=0;j<v[i].size();++j) {
            pair<int,int> x=v[i][j];
            s.insert(x);
        }
        if (s.empty()) {
            cout<<"a";
            continue;
        }
        int x=s.begin()->first;
        int y=s.begin()->second;
        cout<<ss[y][i-x];
        if (i==r) break;
    }

}