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
    int n;
    cin>>n;
    int s,t,k=1,m=1;cin>>s;
    for(int i=1;i<n;i++){
        cin>>t;
        if(t>=s)k++;
        else{
            k=1;
        }
        if(k>m)m=k;
        s=t;
    }
    cout<<m;
}