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
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int p=0,q=0,r=0;
    for(int i=0;i<n;i++){
        if(a[i]){
            p=i;
            break;
        }
    }
    q=a[p];
    for(int i=p+1;i<n;i++){
        r=a[i];
        a[i]-=q;
        q+=a[i];
    }
    r=0;
    for(int i=0;i<k;i++){
        if(r>=n)cout<<0<<"\n";
        else{
            if(a[r]==0){r++;i--;continue;}
            cout<<a[r]<<"\n";r++;
        }
    }
}