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
#define MOD 1000000007
long long A[2][52][52],a[2][52];
int to(char c){
    if(c>='a'&&c<='z')return c-'a';
    return c-'A'+26;
}
int main(){
    int i,j,k,m;
    long long n;
    scanf("%I64d%d%d",&n,&m,&k);
    for(i=0;i<m;i++)
        for(j=0;j<m;j++)A[0][i][j]=1;
    for(i=0;i<k;i++){
        char s[4];
        scanf("%s",s);
        A[0][to(s[0])][to(s[1])]=0;
    }
    for(i=0;i<m;i++)a[0][i]=1;
    n--;
    int now=0;
    while(n){
        if(n&1){
            for(i=0;i<m;i++)a[now^1][i]=0;
            for(i=0;i<m;i++)
                for(j=0;j<m;j++){
                    a[now^1][i]+=A[now][i][j]*a[now][j];
                    a[now^1][i]%=MOD;
                }
        }
        else for(i=0;i<m;i++)a[now^1][i]=a[now][i];
        for(i=0;i<m;i++)
                for(j=0;j<m;j++)A[now^1][i][j]=0;
        for(i=0;i<m;i++)
            for(j=0;j<m;j++)
                for(k=0;k<m;k++){
                    A[now^1][i][k]+=A[now][i][j]*A[now][j][k];
                    A[now^1][i][k]%=MOD;
                }
        now^=1;
        n>>=1;
    }
    long long an=0;
    for(i=0;i<m;i++){
        an+=a[now][i];
    }
    an%=MOD;
    cout<<an<<endl;
    return 0;
}