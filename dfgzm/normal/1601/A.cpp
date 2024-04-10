#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=2000010;
int i,j,k,n,m,T,a[maxn];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		n=read();
		for(i=1;i<=n;i++)a[i]=read();
		int d=-1;
		for(i=0;i<=29;i++){
			int num=0;
			for(j=1;j<=n;j++)if(a[j]&(1<<i))++num;
			if(d<0)d=num;else d=__gcd(d,num);
		}
	//	cout<<"d="<<d<<endl;
		for(i=1;i<=n;i++)
			if(d==0 || (d%i==0))printf("%d ",i);puts("");
	}
}