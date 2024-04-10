#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define psi pair<string,int>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    pii z[n];
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        z[i]={a,b};
    }
    sort(z,z+n);
    int d=z[0].sc;
    for(int i=1;i<n;i++){
        if(d>z[i].sc)d=z[i].fr;
        else d=z[i].sc;
    }
    cout<<d;
}