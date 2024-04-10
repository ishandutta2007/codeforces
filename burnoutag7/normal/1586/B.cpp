#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n,m;
    cin>>n>>m;
    set<int> s;
    for(int i=1;i<=n;i++){
        s.emplace(i);
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        s.erase(b);
    }
    int r=*s.begin();
    for(int i=1;i<=n;i++)if(i!=r){
        cout<<r<<' '<<i<<'\n';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}