#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,A,B,f[1000005];
char s[1000005],a[1000005],b[1000005];
int za[1000005],zb[1000005];
int N,z[2000005];
char S[2000005];
void Z(){
    int l=0,r=0;
    for(int i=1;i<N;i++){
        if(i>r){l=i,r=i;while(r<N&&S[r-l]==S[r])r++;z[i]=r-l,r--;}
		else{
        	int k=i-l;if(z[k]<r-i+1)z[i]=z[k];
            else{l=i;while(r<N&&S[r-l]==S[r])r++;z[i]=r-l,r--;}
        }
    }
}
int main(){
	scanf("%s%s%s",s+1,a+1,b+1);
	n=strlen(s+1),A=strlen(a+1),B=strlen(b+1);
	N=0;for(int i=1;i<=A;i++)S[N++]=a[i];
	S[N++]='$';for(int i=1;i<=n;i++)S[N++]=s[i];
	Z();for(int i=1;i<=n;i++)za[i]=z[A+i];
	N=0;for(int i=1;i<=B;i++)S[N++]=b[i];
	S[N++]='$';for(int i=1;i<=n;i++)S[N++]=s[i];
	Z();for(int i=1;i<=n;i++)zb[i]=z[B+i];
	f[0]=1,f[1]=M-1;
	for(int i=0;i<=n;i++){
		if(i>0)(f[i]+=f[i-1])%=M;
		int x=f[i];
		if(i+A>n)continue;
		if(s[i+1]=='0'){
			if(A==1&&a[1]=='0')(f[i+1]+=x)%=M,(f[i+2]+=M-x)%=M;
			continue;
		}
		int p=za[i+1],q=zb[i+1];
		bool fa=(p>=A||s[i+p+1]>a[p+1]);
		bool fb=(i+B<=n&&(q>=B||s[i+q+1]<b[q+1]));
		if(A==B){
			if(fa&&fb)(f[i+A]+=x)%=M,(f[i+A+1]+=M-x)%=M;
		}else{
			if(fa)(f[i+A]+=x)%=M,(f[i+A+1]+=M-x)%=M;
			int L=i+A+1,R=min(n+1,i+B);
			if(L<R)(f[L]+=x)%=M,(f[R]+=M-x)%=M;
			if(fb)(f[i+B]+=x)%=M,(f[i+B+1]+=M-x)%=M;
		}
	}
	printf("%d",f[n]);
}