#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>g(n+5);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a]++;
        g[b]++;
    }
    vector<vector<int>>cine(n+5);
    for(int i=1;i<=n;i++){
        cine[g[i]].push_back(i);
    }
    if(cine[1].size()==2 && cine[2].size()==n-2){
        cout<<"Yes\n";
        cout<<"1\n";
        cout<<cine[1][0]<<" "<<cine[1][1]<<"\n";
        return 0;
    }
    int who=-1,cnt=0;
    for(int i=1;i<=n;i++){
        if(g[i]>2){
            cnt++;
            who=i;
        }
    }
    if(cnt>1){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    cout<<cine[1].size()<<"\n";
    for(int i=0;i<cine[1].size();i++){
        cout<<who<<" "<<cine[1][i]<<"\n";
    }
    return 0;
}