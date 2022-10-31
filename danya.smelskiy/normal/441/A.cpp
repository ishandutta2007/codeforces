#include <bits/stdc++.h>
using namespace std;
int n,x,ans,y,m;
vector<int > v;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;++i){
        cin>>x;
        bool t=false;
        for (int j=1;j<=x;++j){
            cin>>y;
            if (y<m) ++ans;
            if (y<m) t=true;
        }
        if (t==true) v.push_back(i);
    }
    cout<<v.size()<<endl;
    for (int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
}