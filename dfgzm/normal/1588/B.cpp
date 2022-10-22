#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,n,m,T;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		ll Sum=0,wl=0,wl2=0;
		int llen=0,rlen=0;
		cin>>n;
		cout<<"? "<<1<<' '<<n<<endl;
		cin>>Sum;
		int L=1,R=n,Mid=-1;
		while(L<=R){
			Mid=(L+R)>>1;
			cout<<"? "<<1<<' '<<Mid<<endl;
			cin>>wl;
			if(!wl)L=Mid+1;
			else if(wl==Sum)R=Mid-1;
			else break;
		}
		cout<<"? "<<1<<' '<<Mid+1<<endl;
		cin>>wl2;
//		cout<<"now,Mid="<<Mid<<' '<<wl<<' '<<wl2<<endl;
		if(wl2==wl){
			llen=sqrt(2*wl2)+1;
			rlen=sqrt(2*(Sum-wl2))+1;
			cout<<"! "<<Mid-llen+1<<' '<<Mid+1<<' '<<Mid+rlen<<endl;
		}else{
			ll w1,w2,mk;
			int I=Mid-(wl2-wl)+1;
			int MaxR=I+sqrt(2*Sum);
//			cout<<"I="<<I<<' '<<MaxR<<endl;
			cout<<"? "<<1<<' '<<I<<endl;
			cin>>mk;
			if(!mk){
				cout<<"? "<<1<<' '<<MaxR<<endl;
				cin>>w1;
				cout<<"? "<<1<<' '<<MaxR+1<<endl;
				cin>>w2;
				int tMid=MaxR-(w2-w1);
				rlen=sqrt(2*(Sum-(tMid-I+1)*(tMid-I)/2))+1;
				int tR=tMid+rlen;
				cout<<"! "<<I<<' '<<tMid+1<<' '<<tR<<endl;
			}else{
				I--;
				llen=sqrt(2*mk)+1;
				rlen=sqrt(2*(Sum-mk))+1;
				cout<<"! "<<I-llen+1<<' '<<I+1<<' '<<I+rlen<<endl;
			}
		}
	}
}