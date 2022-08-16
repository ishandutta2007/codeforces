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
    char p[500];
    cin>>p;
    for(int i=0;i<strlen(p);i++){
        if((p[i]=='H')||(p[i]=='Q')||(p[i]=='9'))
        {
            cout<<"YES";return 0;
        }
    }
    cout<<"NO";
}