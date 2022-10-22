#include<bits/stdc++.h>
using namespace std;
typedef double db;
int T,n,L;
db flg[100004];
db spd1,spd2,ans;
void solve(){
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++)scanf("%lf",&flg[i]);
	ans=0.0,spd1=1.0,spd2=1.0;
	int l=0,r=n+1;
	flg[r]=(db)L;
	db cur1=0.0,cur2=flg[r];
	while(1){
		db A1=1e10,A2=1e10,A3=1e10;
		A1=(flg[l+1]-cur1)/spd1;
		A2=(cur2-flg[r-1])/spd2;
		A3=(cur2-cur1)/(spd1+spd2);
//		cout<<l<<" "<<r<<" "<<A1<<" "<<A2<<" "<<A3<<"\n";
//		cout<<cur1<<" "<<cur2<<" "<<spd1<<" "<<spd2<<"\n";
		if(A3<A1&&A3<A2){
			printf("%.9lf\n",ans+A3);
			return;
		}
		if(A1>A2){
			cur1+=A2*spd1;
			cur2=flg[--r];
			spd2+=1.0;
			ans+=A2;
		}else{
			cur2-=A1*spd2;
			cur1=flg[++l];
			spd1+=1.0;
			ans+=A1;
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
}