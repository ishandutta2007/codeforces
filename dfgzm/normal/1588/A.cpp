#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=410;
int i,j,k,n,m,T,a[maxn],b[maxn],w[maxn],w2[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		memset(w,0,sizeof(w));
		memset(w2,0,sizeof(w2));
		for(i=1;i<=n;i++)a[i]=read()+110,w[a[i]]++;
		for(i=1;i<=n;i++)b[i]=read()+110,w2[b[i]]++;
		bool flag=true;int last=0;
		for(i=1;i<=300;i++){
			if(w[i]+last<w2[i]){
				flag=false;
				break;
			}else{
				w2[i]=max(0,w2[i]-last);
				w[i]-=w2[i];last=w[i];
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
}