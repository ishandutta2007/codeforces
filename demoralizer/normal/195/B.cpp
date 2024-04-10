#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m;
    cin>>n>>m;
    int k[m];
    k[0]=(m+1)/2;
    for(int i=1;i<m;i++){
        k[i]=k[i-1]+i*(((i%2)^(m%2==0))?-1:1);
    }
    for(int i=0;i<n;i++){
        cout<<k[i%m]<<"\n";
    }
}