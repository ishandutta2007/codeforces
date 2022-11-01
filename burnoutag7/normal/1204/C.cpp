#include<bits/stdc++.h>
using namespace std;

int n,m;
int p[1000005];
int d[105][105];
vector<int> v;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='1'){
                d[i][j]=1;
            }else{
                d[i][j]=1e9;
            }
            if(i==j){
                d[i][j]=0;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    cin>>m;
    int l=1;
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    v.push_back(p[1]);
    for(int i=2;i<=m;i++){
        if(d[p[l]][p[i]]!=d[p[l]][p[i-1]]+1){
            v.push_back(p[i-1]);
            l=i-1;
        }
    }
    v.push_back(p[m]);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<endl;

    return 0;
}