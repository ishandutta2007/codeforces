#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int hcf(int a,int b){
    if(a==0)return b;
    if(b==0)return a;
    return hcf(b%a,a);
}
int pw(int a,int b){
    int r=1;
    for(int i=0;i<b;i++)r*=a;
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    char c[100005];
    cin>>c;
    ll l=strlen(c);
    ll z=-1,a=1,k=0;
    for(ll i=0;i<l-1;i++){
        if((c[i]-'0'+c[i+1]-'0')==9){
            if(z==-1){z=i;k=1;}
            else if(z==i-1){k++;z=i;}
            else {if(k%2==0)a*=1+k/2;k=1;z=i;}
        }
    }
    if(k!=0&&k%2==0)a*=1+k/2;
    cout<<a;
}