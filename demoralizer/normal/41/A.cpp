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
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char s[200],t[200];
    cin>>s>>t;
    int n=strlen(s);
    if(n!=strlen(t)){
        no: cout<<"NO";
        return 0;
    }
    for(int i=0;i<n;i++){
        if(s[i]!=t[n-1-i]){
            goto no;
        }
    }
    cout<<"YES";
}