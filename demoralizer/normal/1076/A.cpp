#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int d[100005];
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,m=0;
    cin>>n;
    char c[n+5];
    cin>>c;
    for(int i=0;i<n-1;i++){
        if(c[i]>c[i+1]&&m==0){m++;continue;}
        cout<<c[i];
    }
    if(m!=0)cout<<c[n-1];
}