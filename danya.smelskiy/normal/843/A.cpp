#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
bool used[100005];
vector<vector<int> > ans;
map<int,int> mt;
vector<int> q;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        q.push_back(a[i]);
    }
    sort(q.begin(),q.end());
    for (int i=0;i<q.size();++i)
        mt[q[i]]=i+1;
    for (int i=1;i<=n;++i)
        a[i]=mt[a[i]];
    for (int i=1;i<=n;++i)
    if (used[i]==false) {
        vector<int> v;
        int j=i;
        while (used[j]==false) {
            used[j]=true;
            v.push_back(j);
            j=a[j];
        }
        ans.push_back(v);
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i){
        cout<<ans[i].size()<<" ";
        for (int j=0;j<ans[i].size();++j)
            cout<<ans[i][j]<<" ";
        cout<<'\n';
    }
}