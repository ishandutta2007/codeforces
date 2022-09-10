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
#define MOD 1000000007
using namespace std;
#define SIZE 1000100
long long two[SIZE],wb[3][SIZE],bb[SIZE],ww[SIZE],rr[SIZE];
char s[SIZE];
int get(char c,int ll,int rr){
    if(c=='W')return wb[0][rr]-wb[0][ll-1];
    else if(c=='B')return wb[1][rr]-wb[1][ll-1];
    else return wb[2][rr]-wb[2][ll-1];
}
int main(){
    int i,j,k,n;
    long long an=0;
    cin>>n>>k;
    two[0]=1;
    for(i=1;i<SIZE;i++)two[i]=two[i-1]*2%MOD;
    if(k*2>n){
        puts("0");
        return 0;
    }
    scanf("%s",s+1);
    for(i=1;i<=n;i++){
        wb[0][i]=wb[0][i-1]+(s[i]=='W');
        wb[1][i]=wb[1][i-1]+(s[i]=='B');
        wb[2][i]=wb[2][i-1]+(s[i]=='X');
    }
    long long cal=0;
    for(i=1;i<=n-2*k+1;i++){
        if(get('W',i,i+k-1)==0){
            bb[i]=two[wb[2][i-1]];
            bb[i]-=cal;
            bb[i]-=bb[i-1]-bb[max(i-k,0)];
            bb[i]%=MOD;
            if(bb[i]<0)bb[i]+=MOD;
        }
        if(s[i]=='X')cal=cal*2%MOD;
        bb[i]+=bb[i-1];
        if(i>=k){
            cal+=bb[i-k+1]-bb[i-k];
            cal%=MOD;
        }
    }
    cal=0;
    for(i=k;i<=n-k;i++){
        if(s[i]=='X')cal=cal*2%MOD;
        cal+=bb[i-k+1]-bb[i-k];
        cal%=MOD;
        rr[i]=cal;
    }
    cal=0;
    for(i=n;i>=2*k;i--){
        if(get('B',i-k+1,i)==0){
            ww[i]=two[get('X',i+1,n)];
            ww[i]-=cal;
            ww[i]-=ww[i+1]-ww[min(i+k,n+1)];
            ww[i]%=MOD;
            if(ww[i]<0)ww[i]+=MOD;
        }
        if(s[i]=='X')cal=cal*2%MOD;
        an+=ww[i]*rr[i-k]%MOD;
        an%=MOD;
        ww[i]+=ww[i+1];
        if(i<=n-k+1){
            cal+=ww[i+k-1]-ww[i+k];
            cal%=MOD;
        }
    }
    if(an<0)an+=MOD;
    cout<<an<<endl;
    return 0;
}