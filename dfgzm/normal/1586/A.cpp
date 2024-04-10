#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=1000010;
int i,j,k,n,m,T,a[maxn];
bool check(int x){
	for(int i=2;i<=sqrt(x);i++)if(x%i==0)return false;return true;
}
string S;
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		n=read();
		int Sum=0;
		for(i=1;i<=n;i++)a[i]=read(),Sum+=a[i];
		if(!check(Sum)){
			printf("%d\n",n);
			for(i=1;i<=n;i++)printf("%d ",i);
			puts("");
		}else{
			for(i=1;i<=n;i++){
				if(!check(Sum-a[i])){
					printf("%d\n",n-1);
					for(j=1;j<=n;j++)if(i!=j)printf("%d ",j);
					puts("");
					break;
				}
			}
		}
	}
}