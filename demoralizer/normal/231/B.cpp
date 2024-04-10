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
    int n,d,l,z=-1;
    cin>>n>>d>>l;
    int a[n],x=d;
    for(int i=0;i<n;i++){
        if(i%2){
            if(d<-l){d+=l;a[i]=l;}
            else if(d>-1){d+=1;a[i]=1;}
            else {a[i]=-d;d=0;z=i;}
        }
        else{
            if(d>l){d-=l;a[i]=l;}
            else if(d<1){d-=1;a[i]=1;}
            else {a[i]=d;d=0;z=i;}
        }
    }
    if(d!=0){
        if(l==1||z==-1)goto fail;
        if(a[z]<l)a[z]++;
        else if(z+2<n)a[z+2]++;
        else goto fail;
    }
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    r0;
    fail: cout<<-1;
}