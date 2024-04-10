#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e3 + 10;

int n;
int A[N];
int main(){
    fast_io;
    cin >> n;
    int ans=0;
    for(int i=0; i<n; i++) cin >> A[i],A[i]=abs(A[i]);
    for(int i=0; i<n-1; i++){
        int a=0,b=0;
        for(int j=0; j<i; j++) if(A[i]<A[j]) a++;
        for(int j=i+1; j<n; j++) if(A[i]>A[j]) a++;
        A[i]*=-1;
        for(int j=0; j<i; j++) if(A[i]<A[j]) b++;
        for(int j=i+1; j<n; j++) if(A[i]>A[j]) b++;
        if(a<b) A[i]*=-1;
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++) if(A[i]>A[j]) ans++;
    }
    cout << ans;
    return 0;
}