/*
 * @Author: BilyHurington
 * @Date: 2021-08-09 20:25:24
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-08-09 20:47:29
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
long long n,mod;
long long mul(long long x,long long y){
    long long ans=0;
    while(y){
        if(y&1) ans=(ans+x)%mod;
        x=(x+x)%mod;y>>=1;
    }
    return ans;
}
struct Matrix{
    long long mat[2][2];
    Matrix(){memset(mat,0,sizeof(mat));}
    Matrix operator * (const Matrix &M) const& {
        Matrix Ans;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    Ans.mat[i][j]+=mul(mat[i][k],M.mat[k][j]);
                    Ans.mat[i][j]%=mod;
                }
            }
        }
        return Ans;
    }
}sg;
Matrix fast_pow(Matrix M,long long k){
    Matrix Ans=M;k--;
    while(k){
        if(k&1) Ans=Ans*M;
        M=M*M;k>>=1;
    }
    return Ans;
}
long long get_fib(long long x){x++;return fast_pow(sg,x).mat[0][0];}
long long x;
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    sg.mat[0][1]=sg.mat[1][0]=sg.mat[1][1]=1;
    scanf("%lld",&x);vector<long long> vec;mod=10000;
    for(int i=0;i<15000;i++) if(get_fib(i)%10000==x%10000) vec.push_back(i);
    for(long long j=10000,len=15000;j<10000000000000ll;j*=10,len*=10){
        vector<long long> v2;mod=j*10;
        for(auto p:vec){
            for(int j=0;j<10;j++){
                long long L=p+j*len;
                if(get_fib(L)%mod==x%mod) v2.push_back(L);
            }
        }
        vec=v2;
    }
    if(!vec.size()) puts("-1");
    else{
        long long x=1e18;
        for(auto y:vec) x=min(x,y);
        printf("%lld",x);
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}