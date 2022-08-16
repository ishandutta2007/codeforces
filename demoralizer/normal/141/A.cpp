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
int c[26],d[26];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char x[200],y[200],z[200];
    cin>>x>>y>>z;
    for(int i=0;i<strlen(x);i++){
        c[x[i]-'A']++;
    }
    for(int i=0;i<strlen(y);i++){
        c[y[i]-'A']++;
    }
    for(int i=0;i<strlen(z);i++){
        d[z[i]-'A']++;
    }
    for(int i=0;i<26;i++)if(c[i]!=d[i]){cout<<"NO";return 0;}
    cout<<"YES";
}