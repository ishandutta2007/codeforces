#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
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

void solve(){
    int n,m,k,x=1,y=1,z=1;
    cin>>n>>m>>k;
    for(int i=1;i<k;i++){
        cout<<"2 "<<x<<" "<<y<<" ";
        if(((z==1)&&(x<n))||((z==-1)&&(x>1))){x+=z;}
        else{y++;z*=-1;}
        cout<<x<<" "<<y<<"\n";
        if(((z==1)&&(x<n))||((z==-1)&&(x>1))){x+=z;}
        else{y++;z*=-1;}
    }
    int t=n*m-2*(k-1);
    cout<<t<<" ";
    while(t--){
        cout<<x<<" "<<y<<" ";
        if(((z==1)&&(x<n))||((z==-1)&&(x>1))){x+=z;}
        else{y++;z*=-1;}
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}