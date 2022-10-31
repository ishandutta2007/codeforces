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
const int maxn = -1;
const int MOD = -1;
int n,k;

int main() {
    scanf("%d",&n);
    k=sqrt(n);
    int lim=(n/k)+1;
    for(int i=lim;i;--i) {
        for(int j=(i-1)*k+1;j<=min(n,i*k);++j)
            printf("%d ",j);
    }
    return 0;
}