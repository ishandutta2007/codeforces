#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cassert>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <queue>
#include <numeric>
#include <iomanip>
#define ll long long
using namespace std;
// for(long long p=Set;p;p=(p-1)&Set)  
//cout<<fixed<<setprecision(11)<<(double)m/z<<"\n";
long long n,x[100010],y[100010],a[6],b[6],c[6],p,q,l[100010],num;

long long r(long long D){
    if(D<0) return -D;
    else    return D;
}

long long gcd(long long n1,long long n2){
    if(n2==0)  return n1;
    else return gcd(n2,n1%n2);
}

void getg(long long A,long long B,long long C[]){
    long long d,e,g1,g2;
    C[1]=x[A]-x[B];
    C[2]=y[A]-y[B];
    if(C[1]<0){
        C[1]=-C[1];
        C[2]=-C[2];
    }
    g1=r(C[1]);
    g2=r(C[2]);
    d=gcd(g1,g2);
    C[1]/=d;
    C[2]/=d;
    
    C[3]=C[1];
    C[4]=C[1]*y[A]-C[2]*x[A];
    if(C[1]==0){
        C[2]=1;
        C[4]=1;
    }
    g1=r(C[3]);
    g2=r(C[4]);
    e=gcd(g1,g2);
    C[3]/=e;
    C[4]/=e;
    
}


long long comp(long long a[],long long b[],long long c[]){
    long long f=5;
    if(a[1]==b[1]&&b[1]==c[1]){
        f--;
    }
    if(a[2]==b[2]&&b[2]==c[2]){
        f--;
    }
    if(a[3]==b[3]&&b[3]==c[3]){
        f--;
    }
    if(a[4]==b[4]&&b[4]==c[4]){
        f--;
    }
    return f;
}

int main(){
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld %lld",&x[i],&y[i]);
    }
    if(n<=4){
        printf("YES\n");
        return 0;
    }
    for(long long i=1;i<=3;i++){
        for(long long j=i+1;j<=4;j++){
            for(long long k=j+1;k<=5;k++){
                getg(i,j,a);
                getg(j,k,b);
                getg(i,k,c);
                
                if(comp(a,b,c)==1){
                    p=i;
                    q=j;
                }
            }
        }
    }
    if(p==0&&q==0){
        printf("NO");
        return 0;
    }
    for(long long i=1;i<=n;i++){
        if(i==p || i==q)    continue;
        getg(p,q,a);
        getg(q,i,b);
        getg(i,p,c);
        
        if(comp(a,b,c)!=1){
            l[++num]=i;
        }
    }
    if(num<=2){
        printf("YES");
        return 0;
    }
    p=l[1];
    q=l[2];
    for(long long i=3;i<=num;i++){
        getg(p,q,a);
        getg(q,l[i],b);
        getg(l[i],p,c);
        
        if(comp(a,b,c)!=1){
            printf("NO");
            return 0;
        }
    }
    printf("YES");
}