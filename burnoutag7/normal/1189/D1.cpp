#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100005];
int deg[100005];
int root;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;

    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++;deg[b]++;
    }

    if(n==2){
        cout<<"yEs"<<endl;
        return 0;
    }
    if(n==3){
        cout<<"nO"<<endl;
        return 0;
    }

    bool f=true;
    for(int i=1;i<=n;i++){
        if(deg[i]==2){
            f=false;
        }
    }
    if(f){
        cout<<"yEs"<<endl;
    }else{
        cout<<"nO"<<endl;
    }

    return 0;
}