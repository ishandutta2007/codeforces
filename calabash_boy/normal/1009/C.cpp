
//
// Created by calabash_boy on 18-7-6.
//
#include<bits/stdc++.h>
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cout<<"[debug] "<<#x<<":"<<x<<endl;
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int MOD = -1;
const int maxn = 1e5+100;
typedef double db;
int a[maxn];
int m,n;
int main(){
    scanf("%d%d",&n,&m);
    LL sum =0;
    while (m--){
        int x,d;
        scanf("%d%d",&x,&d);
        sum+= 1LL*x*n;
        if (d>=0){
            sum+=1LL*n*(n-1)/2*d;
        }else{
            if (n&1){
                sum+= 1LL*(n/2)*(n/2+1)*d;
            }else{
                sum+=1LL*((n-1)/2)*((n-1)/2+1)*d+1LL*n/2*d;
            }
        }
    }
    db ans = 1.0*sum/n;
    printf("%.9lf\n",ans);
    return 0;
}