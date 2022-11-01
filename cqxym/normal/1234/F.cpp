#include<iostream>
using namespace std;
#define R register int
int f[2000011];
int Max(int x,int y){
	return x>y?x:y;
}
int main(){
    string s;
    cin>>s;
    s="."+s;
    int n=s.size()-1,M,K,l,ans=0;
    f[0]=0;
    for (R i=1;i<=n;i++){
        M=0;
		K=0;
        for (R j=i;j<=n;j++){
            l=s[j]-'a';
            if((M&(1<<l))>0){
            	break;
			}
            M^=1<<l;
            K++;
            f[M]=K;
        }
    }
    M=1<<20;
    for(R p=0;p<20;p++){
    	for(R i=0;i<M;i++){
    		if((i&(1<<p))==0){
    			f[i^(1<<p)]=Max(f[(i^(1<<p))],f[i]);
			}
		}
	}
    for(R i=0;i<M;i++){
    	ans=Max(ans,f[i]+f[M-i-1]);
	}
    cout<<ans;
}