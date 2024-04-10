#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 5e5 + 10;

int n;
pair<int,int> A[N];
int main(){
    fast_io;
    cin >> n;
    for(int i=0; i<n; i++) cin >> A[i].S >> A[i].F;
    int ls=-1,ans=0;
    sort(A,A+n);
    for(int i=0; i<n; i++){
        if(A[i].S>ls) ls=A[i].F,ans++;
    }
    cout << ans;
    return 0;
}