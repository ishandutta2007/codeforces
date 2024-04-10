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
    int n,t,s=0;
    cin>>n;
    int a[10]={0,0,0,0,0,0,0,0,0,0};
    for(int i=0;i<n;i++){
        cin>>t;
        a[t]++;
        s+=t;
    }
    if(a[0]==0){cout<<-1;r0;}
    int k=s%3;
    if(k){
        for(int i=k;i<10;i+=3)
            if(a[i]){k=0;a[i]--;goto out;}
        for(int i=3-k;i<10;i+=3)
            if(a[i]){a[i]--;break;}
        for(int i=3-k;i<10;i+=3)
            if(a[i]){a[i]--;break;}
    }
    out:;
    int c=1;
    for(int i=9;i>=0;i--){
        for(int j=0;j<a[i];j++){
            cout<<i;
            if(i==0&&c)r0;
            c=0;
        }
    }
}