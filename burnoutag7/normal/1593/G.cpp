#include<bits/stdc++.h>
using namespace std;

void mian(){
    int n;
    string s;
    cin>>s;
    n=s.size();
    s='$'+s;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++){
        p[i]=p[i-1]+(s[i]=='['||s[i]==']')*(i&1?1:-1);
    }
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<abs(p[r]-p[l-1])<<'\n';
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