#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    vc <int> v,u;
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        if(c=='S')
            v.pb(i);
    }
    if(v.size()==0){cout<<n;return 0;}
    if(v.size()==1){cout<<(n-1);return 0;}
    if(v.size()==n){cout<<0;return 0;}
    if(v.size()==(n-1)){cout<<1;return 0;}
    u.pb(v[0]);
    for(int i=1;i<v.size();i++){
        u.pb(v[i]-v[i-1]-1);
    }
    u.pb(n-v[v.size()-1]-1);
    int s=v.size(),g=n-s;
    int m=0;
    for(int i=1;i<u.size();i++){
        int t=u[i]+u[i-1];
        if(t>m)m=t;
    }
    if(g>m)m++;
    if(2>m)m=2;
    cout<<m;
}