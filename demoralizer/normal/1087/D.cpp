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
int x[100005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,s;
    cin>>n>>s;
    for(int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        x[a]++;x[b]++;
    }
    int c=0;
    for(int i=1;i<=n;i++)if(x[i]==1)c++;
    double ans=2.0*s/c;
    cout<<setprecision(8)<<ans;
}