#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int a[100005];
int main(){
    ios_base::sync_with_stdio(false);
    int n,k,t,m;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>t;
        a[(i%k)]+=t;
    }
    for(int i=0;i<k;i++){
        if(i==0||a[i]<a[m])m=i;
    }
    cout<<(m+1);
}