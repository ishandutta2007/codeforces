#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void mian(){
    int n,k,ans=1;
    cin>>n>>k;
    set<int> s;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        for(int j=2;j*j<=a;j++){
            while(a%(j*j)==0)a/=j*j;
        }
        if(s.find(a)!=s.end()){
            s.clear();
            ans++;
        }
        s.emplace(a);
    }
    cout<<ans<<'\n';
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