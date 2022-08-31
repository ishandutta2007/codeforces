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
    int n,a,b,c;
    cin>>n>>a;
    c=a;
    for(int i=1;i<n;i++){
        cin>>b;
        c=min(c,max(a,b));
        a=b;
    }
    c=min(c,a);
    cout<<c;
}