#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[55][55];
int b[55][55];
vector<pair<int,int> > v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(a[i][j]&&a[i+1][j]&&a[i][j+1]&&a[i+1][j+1]){
                b[i][j]=b[i+1][j]=b[i][j+1]=b[i+1][j+1]=1;
                v.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]!=b[i][j]){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<' '<<v[i].second<<endl;
    }

    return 0;
}