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
#define msi map<string,int>
#define mii map<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,t,c=1,f=0;
    cin>>n>>t;
    for(int i=1;i<n;i++){
        int z;cin>>z;
        if(c==i)c=z+i;
        if(c==t)f=1;
    }
    cout<<((f)?"YES":"NO");
}