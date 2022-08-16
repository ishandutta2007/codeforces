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
    int x[n],h[n];
    for(int i=0;i<n;i++)cin>>x[i]>>h[i];
    if(n<3){cout<<n;return 0;}
    int l=x[0],r=x[2];
    int c=2;
    for(int i=1;i<n-1;i++){
        if(l<x[i]-h[i]){
            c++;l=x[i];
        }
        else{
            if(x[i]+h[i]<r){c++;l=x[i]+h[i];}
            else{l=x[i];}
        }
        r=x[i+2];
    }
    cout<<c;
}