#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int a[3],b[3];
void solve(){
    int n;string s;
    cin>>n>>s;
    for(char c:s){
        a[c-'0']++;
    }
    for(int i=0;i<3;i++){
        b[i]=n/3-a[i];
        a[i]=n/3;
    }
    for(char c:s){
        if((c=='0')&&(a[0]<=0)){
            if(b[1]>0){cout<<1;a[1]--;b[1]--;}
            else {cout<<2;a[2]--;b[2]--;}
            b[0]++;
        }
        else if((c=='1')&&(a[1]<=0)){
            if(b[0]>0){cout<<0;a[0]--;b[0]--;}
            else {cout<<2;a[2]--;b[2]--;}
            b[1]++;
        }
        else if((c=='1')&&(b[1]<0)&&(b[0]>0)){
            cout<<0;a[0]--;b[0]--;
            b[1]++;
        }
        else if((c=='2')&&(b[2]<0)){
            if(b[0]>0){cout<<0;a[0]--;b[0]--;}
            else {cout<<1;b[1]--;a[1]--;}
            b[2]++;
        }
        else {cout<<c;a[c-'0']--;}
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