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
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< (a[i][j]+a[j][i])/2.0 <<" ";
        }
        cout<<"\n";
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<< (a[i][j]-a[j][i])/2.0 <<" ";
        }
        cout<<"\n";
    }
}