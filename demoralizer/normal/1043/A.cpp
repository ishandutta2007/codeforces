#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
int main(){
    ios_base::sync_with_stdio(false);
    int n,s=0,m=-1,t;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t;
        if(m==-1||t>m)m=t;
        s+=t;
    }
    int k=2*s/n+1;
    if(m>k)k=m;
    cout<<k;
}