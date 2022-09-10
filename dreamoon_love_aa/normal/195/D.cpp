#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 100010
const double eps=1e-18;
int k[SIZE],b[SIZE];
struct data{
    long long p,q,k;
    data(long _p=0,long long _q=0,int _k=0){
        p=_p;q=_q;k=_k;
        if(q<0)p=-p,q=-q;
    }
    bool operator<(const data& b)const{return p*b.q<q*b.p;}
    bool operator==(const data& b)const{return p*b.q==q*b.p;}
};
vector<data>qq;
int main(){
    int i,j,n;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>k[i]>>b[i];
        if(k[i]==0)continue;
        if(k[i]>0)qq.pb(data(-b[i],k[i],k[i]));
        else qq.pb(data(-b[i],k[i],-k[i]));
    }
    sort(qq.begin(),qq.end());
    int an=0;
    for(i=0;i<qq.size();i=j){
        long long now=0;
        for(j=i;j<qq.size()&&qq[j]==qq[i];j++)now+=qq[j].k;
        if(now)an++;
    }
    printf("%d\n",an);
    return 0;
}