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
    int t;cin>>t;
    while(t--){
        int a;
        cin>>a;
        a*=2;
        for(int i=3;i<=720;i++){
            for(int j=1;j<i-1;j++){
                if(360*j==a*i){cout<<i<<"\n";goto agla;}
            }
        }
        agla:;
    }
}