#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=25;
int i,j,k,n,m,T;
ll ans[maxn];
int main(){
	ans[0]=1;
	for(i=1;i<maxn;i++)ans[i]=ans[i-1]*i;
	cin>>n;
	ll Ans=ans[n-1]*2/n;
	cout<<(ll)Ans<<endl;
	return 0;
}