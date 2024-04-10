#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int> > g[200005];
int lr[200005];//1-2 if left-to-right edge 0 unused

void dfs(int x,int io){
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i].first,z=g[x][i].second;
        if(lr[abs(z)]>0){
            if(z>0){
                if(lr[z]!=io+1){
                    cout<<"NO"<<endl;
                    exit(0);
                }
            }else{
                if(lr[-z]!=(io^1)+1){
                    cout<<"NO"<<endl;
                    exit(0);
                }
            }
            continue;
        }
        if(z>0){
            lr[z]=io+1;
        }else{
            lr[-z]=(io^1)+1;
        }
        dfs(y,io^1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(make_pair(b,i));
        g[b].push_back(make_pair(a,-i));
    }
    dfs(1,1);
    cout<<"YES"<<endl;
    for(int i=1;i<=m;i++){
        cout<<lr[i]-1;
    }

    return 0;
}