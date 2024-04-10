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
    int n,k;
    cin>>n>>k;
    int a[k+1];
    for(int i=1;i<=k;i++)a[i]=0;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        a[t]++;
    }
    int s=0;
    while(a[k]<n){
        for(int i=k-1;i>0;i--){
            if(a[i]){
                a[i]--;
                a[i+1]++;
            }
        }
        s++;
    }
    cout<<s;
}