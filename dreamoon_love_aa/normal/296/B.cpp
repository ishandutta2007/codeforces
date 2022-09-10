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
#define MOD 1000000007
char s1[SIZE],s2[SIZE];
int d[SIZE][3];
int main(){
    int i,j,k,n,big=1;
    long long all=1;
    cin>>n;
    scanf("%s%s",s1,s2);
    for(i=0;i<n;i++){
        if(s1[i]=='?')all*=10;
        if(s2[i]=='?')all*=10;
        all%=MOD;
        if(s1[i]=='?'&&s2[i]=='?'){
            d[i][1]=10;
            d[i][2]=45;
            d[i][0]=45;
        }
        else if(s1[i]=='?'){
            d[i][1]=1;
            d[i][0]=s2[i]-'0';
            d[i][2]='9'-s2[i];
        }
        else if(s2[i]=='?'){
            d[i][1]=1;
            d[i][0]='9'-s1[i];
            d[i][2]=s1[i]-'0';
        }
        else{
            if(s1[i]==s2[i])d[i][1]=1;
            else if(s1[i]<s2[i])d[i][0]=1;
            else d[i][2]=1;
        }
    }
    long long tmp=1,an=0;
    for(i=0;i<n;i++){
        tmp=tmp*(d[i][0]+d[i][1])%MOD;
    }
    an+=tmp;
    tmp=1;
    for(i=0;i<n;i++){
        tmp=tmp*(d[i][2]+d[i][1])%MOD;
    }
    an+=tmp;
    tmp=1;
    for(i=0;i<n;i++){
        tmp=tmp*d[i][1]%MOD;
    }
    an-=tmp;
    an=all-an;
    an%=MOD;
    if(an<0)an+=MOD;
    cout<<an<<endl;
    
    return 0;
}