#include <bits/stdc++.h>
using namespace std;
vector<string> s;
vector<string> t;
int n,m,q;
int main(){
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        string temp;
        cin>>temp;
        s.push_back(temp);
    }
    for (int i=1;i<=m;i++){
        string temp;
        cin>>temp;
        t.push_back(temp);
    }
    cin>>q;
    while (q--){
        int x;
        cin>>x;
        x--;
        string ans = s[x % n] + t[x % m];
        cout<<ans<<endl;
    }

    return 0;
}