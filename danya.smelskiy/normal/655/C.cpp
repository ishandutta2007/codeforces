#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
vector<int> q;
int last;

inline int chek(int x){
    int res=q[q.size()-1]-q[x-1];
    res=max(res,q[x-1]-q[q.size()-m]);
    return res;
}

inline void update(){
    while (last<q.size()) {
        if (chek(last)<chek(last+1)) return;
        else ++last;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    ++m;
    cin>>s;
    int ans=1e9;
    for (int i=1;i<=s.size();++i) {
        if (s[i-1]=='1') continue;
        q.push_back(i);
        if (q.size()>=m) {
            last=max(last,(int)q.size()-m+1);
            update();
            ans=min(ans,max(q[last-1]-q[q.size()-m],q[q.size()-1]-q[last-1]));
        }
    }
    cout<<ans;
}