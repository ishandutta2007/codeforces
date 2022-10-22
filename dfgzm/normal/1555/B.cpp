#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T,w,h,wn,hn;
int main(){
	int x1,x2,y1,y2;
	cin>>T;
	while(T--){
		w=read();h=read();
		x1=read();y1=read();
		x2=read();y2=read();
		wn=read();hn=read();
		int ans=1e9;
		if((x2-x1)+wn<=w){
			int len=w-wn-(x2-x1);
			if(x1<=len)ans=0;
			else if(x2>=w-len)ans=0;
			else ans=min(ans,min(x1-len,w-len-x2));
		}
		if((y2-y1)+hn<=h){
			int len=h-hn-(y2-y1);
			if(y1<=len)ans=0;
			else if(y2>=h-len)ans=0;
			else ans=min(ans,min(y1-len,h-len-y2));
		}
		if(ans==1000000000)puts("-1");
		else printf("%d.00000000\n",ans);
	}
}