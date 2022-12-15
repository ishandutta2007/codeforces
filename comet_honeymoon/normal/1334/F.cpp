#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
 
il char gc(){
    static char now[1<<20],*S,*T;
    if (T==S)
    {
        T=(S=now)+fread(now,1,1<<20,stdin);
        if (T==S) return EOF;
    }
    return *S++;
}//getchar
  
il int read(){
    int res=0,sign=1;
    char c;
    while ((c=gc())<'0'||c>'9') if (c=='-') sign=-1;
    res=(c^48);
    while ((c=gc())>='0'&&c<='9') res=(res<<3)+(res<<1)+(c^48);
    return res*sign;
}//read a signed interger
 
int N;
int A[5000005],P[5000005],hid[5000005],hid0[5000005];
int B[5000005],M;bool flg[5000005];ll F[5000005];
ll C[5000005];
 
int main(){
    N=read();
    for(int i=1;i<=N;i++) A[i]=read();
    for(int i=1;i<=N;i++) P[i]=read();
    M=read();
    for(int i=1;i<=M;i++) B[i]=read(),hid[B[i]]=i;
    for(int i=1;i<=N;i++) hid0[i]=(hid[i-1]?hid[i-1]:hid0[i-1]);
    flg[0]=1;F[0]=0;
    for(int i=1;i<=N;i++){
        if(hid[A[i]]){
            int hai=hid[A[i]];
            if(flg[hai-1])
                if(!flg[hai]) flg[hai]=1,F[hai]=F[hai-1]+C[hai-1]-(P[i]<=0?P[i]:0);
                else F[hai]=min(F[hai],F[hai-1]+C[hai-1]-(P[i]<=0?P[i]:0));
        }
        if(P[i]>=0) C[hid0[A[i]]]+=P[i];
        else C[M]+=P[i];
    }
    if(!flg[M]) printf("NO\n");
    else printf("YES\n%lld\n",F[M]+C[M]);
     
    return 0;
}