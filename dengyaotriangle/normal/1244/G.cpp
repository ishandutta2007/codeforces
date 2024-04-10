#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=1000005;

long long n;
long long k;
int p[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    long long d=k-(1+n)*n/2;
    if(d<0){
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++)p[i]=i;
    long long cans=(1+n)*n/2;
    for(int i=1;i<=n/2;i++){
        int cl=i,cr=n-i+1,cd=cr-cl;
        if(d==0)break;
        if(d<=cd){
            swap(p[cl],p[cl+d]);
            cans+=d;
            d=0;
        }else{
            swap(p[cl],p[cr]);
            d-=cd;
            cans+=cd;
        }
    }
    cout<<cans<<'\n';
    for(int i=1;i<=n;i++)cout<<p[i]<<' ';
    cout<<'\n';
    for(int i=1;i<=n;i++)cout<<i<<' ';
    return 0;
}