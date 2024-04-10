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
char s[111];
long long C[3000][3000];
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=0;i<3000;i++){
        C[i][0]=1;
        for(j=1;j<=i;j++){
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=MOD)C[i][j]-=MOD;
        }
    }
    while(n--){
        long long an=0;
        scanf("%s",s);
        k=0;
        for(i=0;s[i];i++)k+=s[i]-'a';
        j=i;
        int tmp=1;
        for(i=0;i<=j&&k>=i*26;i++){
            an+=tmp*C[j][i]*C[k-i*26+j-1][j-1];
            tmp=-tmp;
            an%=MOD;
        }
        an--;
        if(an<0)an+=MOD;
        cout<<an<<endl;
    }
    return 0;
}