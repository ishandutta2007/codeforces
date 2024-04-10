#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n,m,p=0;
    cin>>n;
    m=n;
    int d=0;
    while(m!=0)d++,m/=10;
    int k[d];m=n;
    p=d-1;
    while(m!=0)k[p]=m%10,p--,m/=10;
    if(d%2){
        out:
        d++;
        for(int i=0;i<d/2;i++)cout<<4;
        for(int i=0;i<d/2;i++)cout<<7;
        return 0;
    }
    else{
        ll r=0;
        for(int i=0;i<d/2;i++)r=r*10+7;
        for(int i=0;i<d/2;i++)r=r*10+4;
        if(n>r){d++;goto out;}
        r=0;
        for(int i=0;i<d/2;i++)r=r*10+4;
        for(int i=0;i<d/2;i++)r=r*10+7;
        if(n<r){cout<<r;return 0;}
        int u,v,c;
        again:;
        u=v=c=0;
        for(int i=0;i<d;i++){
        if(c){
        if(u<d/2){u++;k[i]=4;}
        else {v++;k[i]=7;}
        continue;
        }
        if(k[i]==4&&u<d/2){u++;continue;}
        if(k[i]==7&&v<d/2){v++;continue;}
        if(k[i]<4){
        if(u<d/2){u++;k[i]=4;}
        else {v++;k[i]=7;}
        c=1;
        }
        else if(k[i]<7&&v<d/2){
        v++;
        k[i]=7;
        c=1;
        }
        else{
        k[i-1]++;
        goto again;
        }
        }
        for(int i=0;i<d;i++)cout<<k[i];
    }
}