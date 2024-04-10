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
    int k,l,m,n,d;
    cin>>k>>l>>m>>n>>d;
    int c=d;
    for(int i=1;i<=d;i++){
        if((i%k)&&(i%m)&&(i%l)&&(i%n))c--;
    }
    cout<<c;
}