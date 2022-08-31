#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m,z;
    cin>>n>>m;
    set<int> s[n+1];
    vc<int> u;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        s[a].insert(a);
        s[b].insert(b);
        s[a].insert(b);
        s[b].insert(a);
    }
    for(z=0;;z++){
        for(int i=1;i<=n;i++)
            if(s[i].size()==2&&s[i].find(i)!=s[i].end())u.pb(i);
        if(u.size()==0)break;
        for(int i=0;i<u.size();i++){
            for(int j=1;j<=n;j++){
                s[j].erase(u[i]);
            }
        }
        u.clear();
    }
    cout<<z;
}