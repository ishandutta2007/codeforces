#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

long long a[maxn],q[maxn],k;
int n;
long long mi=10000000,xi=0;;

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mi=min(mi,a[i]);
        xi=max(xi,a[i]);
        q[a[i]]++;
    }
    long long cv=0,ct=0;
    int ans=0;
    for(int i=xi;i>mi;i--){
        if(cv+ct+q[i]>k){
            ans++;
            cv=0;
        }
        ct+=q[i];
        cv=cv+ct;
    }
    if(cv)ans++;
    cout<<ans;
    return 0;
}