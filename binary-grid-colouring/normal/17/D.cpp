#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000100;
char b[N],n[N];
int phi(int x)
{
    int res=x;
    for(int i=2;i*i<=x;i++)if(x%i==0)
    {
        res=res/i*(i-1);
        while(x%i==0)x/=i;
    }
    if(x>1)res=res/x*(x-1);
    return res;
}
int q_pow(int a,int k,int mod)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%mod;
        a=1LL*a*a%mod;
        k>>=1;
    }
    return res%mod;
}
int cal(char *str,int mod)
{
    int res=0;
    for(int i=0;str[i];i++)
    {
    	res=(10LL*res + str[i]-'0') % mod;
	}   
    return res;
}
int main()
{
    int c;
    scanf("%s%s%d",b,n,&c);
    if(c==1)
    {
    	cout<<1<<endl;
    	exit(0);
	}
    int B=cal(b,c);
	int res=(B + c - 1) % c;
    int Phi=phi(c);
	int t=0;
    for(int i=0;n[i];i++)
    {
    	t = min(1000000000LL,10LL * t + n[i]-'0');
	}
        
    if(t - 1 < Phi)
	{
		res = 1LL * res * q_pow(B,t-1,c)%c;
	}
    else 
	{
		res = 1LL * res * q_pow(B,cal(n,Phi) + Phi - 1,c)%c;
	}
	printf("%d\n",(res+c-1)%c+1);
    return 0;
}