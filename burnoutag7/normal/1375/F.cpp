#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll a[3];
int v[3];

void solve(){
    iota(v,v+3,0);
    sort(v,v+3,[](const int &i,const int &j){
        return a[i]<a[j];
    });
    cout<<a[v[2]]*2-a[v[1]]-a[v[0]]<<endl;
    int x;
    cin>>x;
    x--;
    if(x==v[0]){
        cout<<a[v[2]]-a[v[1]]<<endl;
        exit(0);
    }
    if(x==v[1]){
        cout<<a[v[2]]-a[v[0]]<<endl;
        exit(0);
    }
    a[v[2]]+=a[v[2]]*2-a[v[1]]-a[v[0]];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<3;i++)cin>>a[i];
    cout<<"First"<<endl;
    while(true){
        solve();
    }

    return 0;
}