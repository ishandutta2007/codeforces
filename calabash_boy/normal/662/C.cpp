//
// Created by calabash_boy on 18-8-17.
//

//UOJ 310
#include<bits/stdc++.h>
using namespace std;
#define int LL
typedef long long LL;
const int N = 1<<20;
int A[N];
int B[N];
int C[N];
char a[20][100005];
int n,m;
//xor fwt : A[i] = \sigma{-1^([i&j])*a[j]}   [x]:count of 1-bit
void FWT(int *a,int n,int r){
    for (int i=1;i<n;i<<=1){
        for (int j=0;j<n;j+=(i<<1)){
            for (int k =0;k<i;k++){
                int x = a[j+k];
                int y = a[j+k+i];
                if (r){
                    a[j+k] = (x+y);
                    a[j+k+i] = (x-y);
                }else{
                    a[j+k] = 1LL*(x+y)/2;
                    a[j+k+i] = 1LL*(x-y)/2;
                }
            }
        }
    }
}
void workB(){
    for (int i=0;i<(1<<n);i++){
        B[i] = __builtin_popcount(i);
        B[i] = min(B[i],n-B[i]);
       // cout<<B[i]<<endl;
    }
}
signed main(){

    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){
        scanf("%s",&a[i][0]);
    }
    for (int i=0;i<m;i++){
        int mask =0;
        for (int j=0;j<n;j++){
            if (a[j][i] == '1'){
                mask += (1<<j);
            }
        }
        A[mask]++;
    }
    FWT(A,(1<<n),1);
    workB();
    FWT(B,(1<<n),1);
    for (int i=0;i<(1<<n);i++){
        C[i] = A[i] * B[i];
    }
    FWT(C,(1<<n),0);
    int ans = n*m;
    for (int i=0;i<(1<<n);i++){
        ans = min(ans,C[i]);
    }
    cout<<ans<<endl;
    return 0;
}