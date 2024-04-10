#include <bits/stdc++.h>

#define ll long long
const ll MAX_N = 1e5 + 1, MOD = 1e9 + 7;
using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll n,cnt=0;
    cin >> n;
    ll a[n],s[n],z=0,s2[n];
    cin >> a[0];
    s2[0]=0;
    if(a[0]<0) s[0]=1;
    else{
        s[0]=0;
        if(a[0]==0) z++;
        else s2[0]=1;
    }
    for(int i=1; i<n; i++){
        cin >> a[i];
        s2[i]=s2[i-1];
        if(a[i]<0) s[i]=s[i-1]+1;
        else{
            s[i]=s[i-1];
            if(a[i]==0) z++;
            else s2[i]++;
        }
    }
    cnt=INT_MAX;
    for(int i=0; i<n-1; i++){
        cnt=min(cnt,s[n-1]-s[i]+s2[i]+z);
    }
    cout << cnt;
    return 0;
}