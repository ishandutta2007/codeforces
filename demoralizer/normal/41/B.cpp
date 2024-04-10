#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
#define r0 return 0
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,b,t;
    cin>>n>>b;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    t=b;
    for(int i=0;i<n;i++){
        int c=b/a[i],d=b%a[i];
        for(int j=i;j<n;j++){
            t=max(t,d+c*a[j]);
        }
    }
    cout<<t;
}