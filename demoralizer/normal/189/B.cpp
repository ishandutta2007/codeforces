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
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll w,h,a=0,b=0;
    cin>>w>>h;
    for(int i=2;;i+=2){
        if(i>w&&i>h)break;
        if(i<=w){a+=w-i+1;}
        if(i<=h){b+=h-i+1;}
    }
    cout<<(a*b);
}