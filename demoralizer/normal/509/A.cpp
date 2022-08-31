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
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int dp[20][20];
int a(int i,int j){
    if(i==1||j==1)return 1;
    int &ans=dp[i][j];
    ans=a(i-1,j)+a(i,j-1);
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    memset(dp,-1,sizeof(dp));
    int n;
    cin>>n;
    cout<<a(n,n);
}