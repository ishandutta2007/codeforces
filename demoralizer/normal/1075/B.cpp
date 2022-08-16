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
    int n,m,x=0,y=0,t;
    cin>>n>>m;
    int a[n+m],b[n],c[m];
    for(int i=0;i<n+m;i++){
        cin>>a[i];
    }
    for(int i=0;i<n+m;i++){
        cin>>t;
        if(t){c[y]=a[i];y++;}
        else {b[x]=a[i];x++;}
    }
    y=0;
    for(int i=0;i<n;i++){
        if(y==m-1){d[y]++;continue;}
        while(b[i]>c[y]&&y<m-1)y++;
        if(y==0){d[y]++;continue;}
        int p=c[y]-b[i],q=b[i]-c[y-1];
        if(p<q)d[y]++;
        else {d[y-1]++;y--;}
    }
    for(int i=0;i<m;i++){
        cout<<d[i]<<" ";
    }
}