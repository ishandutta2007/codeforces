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
long long m;
void print(long long x){
    long long A[60][2][2],a[60][2];
    if(x<=2){
        cout<<1%m<<endl;
        return;
    }
    int i,j,k;
    memset(A,0,sizeof(A));
    memset(a,0,sizeof(a));
    A[0][0][1]=A[0][1][0]=A[0][1][1]=1;
    a[0][0]=a[0][1]=1;
    x-=2;
    int now=0;
    while(x){
        if(x&1){
            for(i=0;i<2;i++)
                for(j=0;j<2;j++){
                    a[now+1][i]+=A[now][i][j]*a[now][j];
                    a[now+1][i]%=m;
                }
        }
        else for(i=0;i<2;i++)a[now+1][i]=a[now][i];
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                for(k=0;k<2;k++){
                    A[now+1][i][k]+=A[now][i][j]*A[now][j][k];
                    A[now+1][i][k]%=m;
                }
        now++;
        x>>=1;
    }
    cout<<a[now][1]%m<<endl;
}
int main(){
    long long l,r,k;
    int i;
    cin>>m>>l>>r>>k;
    l--;
    if(r/k<=1000000){
        for(i=r/k;;i--)
            if(r/i-l/i>=k)break;
        print(i);
    }
    else{
        long long tt=(r-l-1)/(k-1);
        if(tt==1){
            print(1);
            return 0;
        }
        long long tmp=r/tt;
        while(1){
            if(tmp<k){
                tmp++;
                continue;
            }
            if(tmp==k){
                long long l1=r/(tmp+1)+1,r1=r/tmp;
                if(l<r1){
                    print(r1);
                    return 0;
                }
            }
            else{
                long long l1=r/(tmp+1)+1,r1=r/tmp;
                long long l2=l/(tmp+1-k)+1,r2=l/(tmp-k);
                if(l1<=r2&&l2<=r1){
                    print(min(r1,r2));
                    return 0;
                }
            }
            tmp++;
        }
    }
    return 0;
}