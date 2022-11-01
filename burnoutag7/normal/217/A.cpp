#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[100005];
vector<int> g[100005];
int f[100005];
set<int> t;

int find(int x){
    if(f[x]==x)return x;
    else return f[x]=find(f[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    f[x]=y;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)f[i]=i;
    for(int i=1;i<=n;i++){
        cin>>a[i].first>>a[i].second;
        for(int j=1;j<i;j++){
            if(a[j].first==a[i].first||a[j].second==a[i].second){
                g[i].push_back(j);
                g[j].push_back(i);
                unite(i,j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        t.insert(find(i));
    }
    cout<<t.size()-1<<endl;

    return 0;
}//