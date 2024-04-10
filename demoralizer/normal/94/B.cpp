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
    int m,s,t;
    cin>>m;
    int a[6]={0,0,0,0,0,0};
    for(int i=0;i<m;i++){
        cin>>s>>t;
        a[s]++;a[t]++;
    }
    for(int i=1;i<6;i++)if(a[i]!=2){cout<<"WIN";r0;}
    cout<<"FAIL";
}