#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=110;
int i,j,k,n,m,T;
ll p[maxn],now,ans;
int main(){
	cin>>T;
	while(T--){
		ans=now=0;
		n=read();k=read();
		now=p[1]=read();
		for(i=2;i<=n;i++){
			p[i]=read();
			ll need=p[i]*100/k+(p[i]*100%k!=0);
//			cout<<"need="<<need<<endl;
			if(now<=need)ans+=need-now,now=need;
			now+=p[i];
		}printf("%lld\n",ans);
	}
	return 0;
}