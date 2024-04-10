#include <bits/stdc++.h>

using namespace std;

int D[601][601],K[601][601],T[601][601];

int N,M,B,Mod;
int P[601];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d %d %d %d",&N,&M,&B,&Mod);

    int i,j,k,l,c;
    for(i=0; i<N; i++) scanf("%d",P+i);

    D[0][0] = 1;

    for(i=0; i<N; i++){
        for(j=0; j<=M; j++){
            for(k=0; k<=B; k++){
                if(j>=1 && k-P[i]>=0) D[j][k]=(D[j][k]+D[j-1][k-P[i]])%Mod;
            }
        }
    }

    int sum=0;
    for(i=0; i<=B; i++){
        sum = (sum+D[M][i])%Mod;
    }

    printf("%d\n",sum);

    return 0;
}