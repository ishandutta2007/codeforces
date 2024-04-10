#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int hcf(int a,int b){
    if(a==0)return b;
    if(b==0)return a;
    return hcf(b%a,a);
}//hdj
int pw(int a,int b){
    int r=1;
    for(int i=0;i<b;i++)r*=a;
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    set<pair<int,pair<int,int> > >s[n+1];
    for(int i=0;i<m;i++){
        int l,r,t,c;
        cin>>l>>r>>t>>c;
        for(int j=l;j<=r;j++){
            s[j].insert({t,{i,c}});
        }
    }
    int a=0;
    for(int i=1;i<=n;i++){
        if(s[i].size())a+=(*s[i].begin()).sc.sc;
    }
    cout<<a;
}