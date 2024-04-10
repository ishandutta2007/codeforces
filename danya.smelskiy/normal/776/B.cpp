#include <bits/stdc++.h>
using namespace std;

int n;
int color[200005];
bool used[200005];
int ans;
vector<int> v;
int main(){
    cin>>n;
    ++n;
    for (int i=2;i<=n;++i){
        if (used[i]==true) continue;
        v.push_back(i);
        for (int j=2;i*j<=n;++j)
            used[i*j]=true;
    }
    for (int i=0;i<v.size();++i){
        color[v[i]]=1;
    }
    if (v.size()==n-1) cout<<1<<'\n';
    else cout<<2<<'\n';
    for (int i=2;i<=n;++i)
        if (color[i]==0) cout<<"2 ";
        else
        cout<<color[i]<<" ";
}