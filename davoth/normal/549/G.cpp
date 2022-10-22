#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 1e2 + 10;

int n;
int main(){
    fast_io;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]+=i;
    }
    sort(a,a+n);
    for(int i=0; i<n-1; i++) if(a[i]>a[i+1]-1) return cout<<":(",0;
    for(int i=0; i<n; i++) cout << a[i]-i << ' ';
    return 0;
}