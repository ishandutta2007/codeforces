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
    int m,s,t;
    cin>>m>>s;
    int a[m];t=s-1;
    if(s==0){
        if(m==1)cout<<"0 0";
        else cout<<"-1 -1";
        return 0;
    }
    for(int i=0;i<m;i++)a[i]=0;
    for(int i=m-1;i>=0;i--){
        if(t>9){a[i]=9;t-=9;}
        else{a[i]=t;t=0;break;}
    }
    if(a[0]==9){
        cout<<"-1 -1";return 0;
    }
    a[0]++;
    for(int i=0;i<m;i++){
        cout<<a[i];
    }
    t=s;
    for(int i=0;i<m;i++)a[i]=0;
    for(int i=0;i<m;i++){
        if(t>9){a[i]=9;t-=9;}
        else{a[i]=t;t=0;break;}
    }
    cout<<" ";
    for(int i=0;i<m;i++){
        cout<<a[i];
    }
}