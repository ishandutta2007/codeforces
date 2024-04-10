#include <bits/stdc++.h>
using namespace std;
int x,y,a,b;
vector<pair<int,int> > ans;
int main(){
    cin>>x>>y>>a>>b;
    int res1=a,res2=b;
    x-=a;
    y-=b;
    for (int i=0;i<=x;++i)
        for (int j=0;j<=y ;++j)
        if (res1+i>res2+j) ans.push_back(make_pair(res1+i,res2+j));
        cout<<ans.size()<<'\n';
        for (int i=0;i<ans.size();++i)
            cout<<ans[i].first<<" "<<ans[i].second<<'\n';
}