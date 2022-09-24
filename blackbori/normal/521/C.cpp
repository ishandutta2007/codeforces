#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

#define X 1000000007

using namespace std;

int a[100004];
long long F[100004],I[100004],FI[100004];
long long S[100004],T[100004];

long long int C(int a,int b)
{
    if(a < b || a<0 || b<0) return 0;
    return ((F[a] * FI[a-b])%X * FI[b])%X;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    int n,k,i;

    scanf("%d %d",&n,&k);

    F[0] = 1; I[1] = 1; FI[0] = 1; S[0] = 0; T[0] = 1;
    for(i=2; i<=n; i++){
        I[i] = (X-X/i) * I[X%i] % X;
    }
    for(i=1; i<=n; i++){
        scanf("%1d",a+i);
        F[i] = (F[i-1] * i) % X;
        FI[i] = (FI[i-1] * I[i]) % X;
        S[i] = (S[i-1] + a[i]) % X;
        T[i] = (T[i-1] * 10) % X;
    }

    n--;
    long long sum = 0;
    for(i=1; i<=n; i++){
        sum+= ((C(n-i,k-1) * T[i-1]) % X ) * S[n-i+1];
        sum %= X;
    }



    for(i=1; i<=n+1; i++){
        sum += (((a[i] * C(i-1,k)) % X) * T[n-i+1]);
        sum %= X;
    }

    printf("%I64d\n",sum);

    return 0;
}