#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

vector<pair<int,int>> si={{0,0},{-1,0},{-2,0},{-2,-1},{-2,-2},{-1,-2},{0,-2},{0,-1}};

vector<pair<int,int>> ans;


void out(vector<pair<int,int> > vec,int xd){
    for(int i=0;i<vec.size();i++){
        ans.push_back({vec[i].first+xd,vec[i].second+xd});
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<=n;i++){
        int f=i*2;
        out(si,f);
    }
    sort(ans.begin(),ans.end());
    ans.resize(unique(ans.begin(),ans.end())-ans.begin());
    cout<<ans.size()<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<' '<<ans[i].second<<'\n';
    }
    return 0;
}