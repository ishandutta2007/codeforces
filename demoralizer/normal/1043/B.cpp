#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=n-1;i>0;i--){
        a[i]-=a[i-1];
    }
    vector<int> v;
    for(int k=1;k<=n;k++){
        int z=1;
        for(int i=0;i+k<n;i++){
            if(a[i+k]!=a[i]){z=0;break;}
        }
        if(z)v.pb(k);
    }
    cout<<v.size()<<"\n";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}