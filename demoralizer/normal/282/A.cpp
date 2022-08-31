#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<ll,ll>
#define msi map<string,ll>
#define mii map<ll,ll>
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,x=0;
    cin>>n;
    char c[10];
    for(int i=0;i<n;i++){
        cin>>c;
        if(c[1]=='+')x++;else x--;
    }
    cout<<x;
}