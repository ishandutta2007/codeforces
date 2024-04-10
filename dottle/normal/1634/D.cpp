#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void ask(int x,int y,int z){cout<<"? "<<x<<' '<<y<<' '<<z<<endl; }
void res(int x,int y){cout<<"! "<<x<<' '<<y<<endl; }

void solve(){
	int n,mx=-1,id=0,f2=0;cin>>n;
	for(int i=3;i<=n;i++){
		cout<<"? 1 2 "<<i<<'\n';
	}
	cout<<endl;
	for(int i=3;i<=n;i++){
		int x;cin>>x;
		if(mx!=-1&&x!=mx)f2=1;
		if(x>mx)id=i,mx=x;
	}
	if(!f2){
		for(int i=1,t,p;i<=n;i=p+1){
			t=i;if(t==id)t++;
			p=t+1;if(p==id)p++;
			if(p>n)break;
			ask(t,p,id);
			int x;cin>>x;
			if(x>mx){
				int q=1;while(q==t||q==id)q++;
				ask(q,t,id);
				int y;cin>>y;
				if(y==x)return res(t,id);
				else return res(p,id);
			}
		}
		int p=n,q=1;while(p==id)p--;while(q==id)q++;
		if(p!=q){
			ask(p,q,id);
			int x;cin>>x;
			if(x>mx)return res(p,id);
		}
		res(1,2);
	}else{
		int id0=0,id1=0,mx1=0;
		for(int i=1,t,p;i<=n;i=p+1){
			t=i;if(t==id)t++;
			p=t+1;if(p==id)p++;
			if(p>n)break;
			ask(t,p,id);
			int x;cin>>x;
			if(x>mx1)mx1=x,id0=t,id1=p;
		}
		int p=n,q=1;while(p==id)p--;while(q==id)q++;
		if(p!=q){
			ask(p,q,id);
			int x;cin>>x;
			if(x>mx1)mx1=x,id0=p,id1=q;
		}
		q=1;while(q==id0||q==id||q==id1)q++;
		ask(q,id0,id);
		int x;cin>>x;
		if(x==mx1)res(id0,id);
		else res(id1,id);
	}
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}