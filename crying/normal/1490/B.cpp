#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
using namespace std;
const int MAXN=3e4+10,INF=1e9;
int T,n,A[MAXN],ans,a,b,c,t;
int main(){
	cin>>T;
	while(T--){
		cin>>n;t=n/3;
		a=b=c=0;ans=INF;
		rep(i,1,n){
			cin>>A[i];
			if(A[i]%3==0)a++;
			else if(A[i]%3==1)b++;
			else c++;
		} 
		rep(i,0,n){
			int cost=0;
			int x=a,y=b,z=c;
			//ab i  
			y+=i;x-=i;cost+=i;
			//bc (b-t)
			if(y<t)continue;
			cost+=(y-t);z+=(y-t);y=t;
			//ca (c-t)
			if(z<t)continue;
			cost+=(z-t);x+=(z-t);z=t;
			if(x==t)ans=min(ans,cost);
		}
		cout<<ans<<endl;
	}
	return 0;
}