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
int a[1005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,x,l,r;
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>l>>r;
        if(r<l){
            r=r+l;
            l=r-l;
            r=r-l;
        }
        for(int i=l;i<=r;i++)a[i]++;
    }
    int m=-1;
    for(int i=0;i<1003;i++){
        if(a[i]==n){
            if(abs(x-i)<m||m==-1)m=abs(x-i);
        }
    }
    cout<<m;
}