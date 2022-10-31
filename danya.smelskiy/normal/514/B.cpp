#include <bits/stdc++.h>
using namespace std;
int n,x,y;
bool used[10005];
pair<int,int> a[10005];
int ans;
bool t;
int main(){
    cin>>n>>x>>y;
    for (int i=1;i<=n;++i)
        cin>>a[i].first>>a[i].second;
    for (int i=1;i<=n;++i){
        bool t=false;
        for (int j=1;j<=n;++j){
            if (used[j]==false){
                t=true;
                ++ans;
                used[j]=true;
                for (int k=1;k<=n;++k)
                if (used[k]==false){
                    if ((x-a[j].first)*(a[k].second-a[j].second)==(a[k].first-a[j].first)*(y-a[j].second)){
                        used[k]=true;
                    }
                }
            }
        }
        if (t==false) break;
    }
    cout<<ans;
}