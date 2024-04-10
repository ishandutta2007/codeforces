#include <bits/stdc++.h>
using namespace std;
int n,x,y;
struct st{
    int x,y,z;
};
st t;
vector<st> v;
vector<int> ans;
bool used[2005];
inline bool cmp(st a,st b){
    if (a.x!=b.x) return a.x<b.x;
    else return a.y<b.y;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x>>y;
        if (x>y) swap(x,y);
        t.x=x;
        t.y=0;
        t.z=i;
        v.push_back(t);
        t.x=y;
        t.y=1;
        v.push_back(t);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i=0;i<v.size();++i) {
        if (v[i].y==0) {
            used[v[i].z]=true;
        } else {
            if (used[v[i].z]==false) continue;
            ans.push_back(v[i].x);
            for (int i=1;i<=n;++i)
                used[i]=false;
        }
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
    cout<<ans[i]<<" ";
}