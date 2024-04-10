#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        vector<int> s(4),t(4);
        for(int &x:s)cin>>x;
        t=s;
        sort(t.begin(),t.end());
        cout<<(t[2]==min(max(s[0],s[1]),max(s[2],s[3]))&&t[3]==max(max(s[0],s[1]),max(s[2],s[3]))?"YES\n":"NO\n");
    }

    return 0;
}