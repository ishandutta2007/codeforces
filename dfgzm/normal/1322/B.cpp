#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=400010;
int i,j,k,n,m,T,a[maxn];
int St[2][maxn];
int top[2];
ll ans;
int main(){
	cin>>n;
	int x0=0,x1=0;
	for(i=1;i<=n;i++)a[i]=read(),x0+=a[i]&1,x1+=1-(a[i]&1);
	for(i=1;i<16777216;i*=2){
		top[0]=top[1]=0;
		int cnt=0,sum2=0,x0=0,x1=0;
		ll sum=0;
		for(j=1;j<=n;j++){
			if(a[j]&(i*2))x0++;
			else x1++;
			if(a[j]&i)St[1][++top[1]]=a[j];
			else St[0][++top[0]]=a[j];
		}sum=2ll*(x0)*(x1);
		for(j=1;j<=top[0];j++)a[++cnt]=St[0][j],St[0][j]%=(2*i);
		for(j=1;j<=top[1];j++)a[++cnt]=St[1][j],St[1][j]%=(2*i);
		//cout<<sum<<endl;
		for(j=1;j<=top[0];j++){
			sum+=top[0]-(lower_bound(St[0]+1,St[0]+1+top[0],2*i-St[0][j])-St[0])+1,
			sum+=top[1]-(lower_bound(St[1]+1,St[1]+1+top[1],2*i-St[0][j])-St[1])+1;
			//cout<<"j="<<j<<' '<<sum<<endl;
		}
		for(j=1;j<=top[1];j++)
			sum+=top[0]-(lower_bound(St[0]+1,St[0]+1+top[0],2*i-St[1][j])-St[0])+1,
			sum+=top[1]-(lower_bound(St[1]+1,St[1]+1+top[1],2*i-St[1][j])-St[1])+1;
		for(j=1;j<=n;j++)if((a[j]+a[j])&(2*i))sum--;
		//cout<<top[0]<<' '<<top[1]<<' '<<i<<' '<<sum<<' '<<sum/2<<endl;
		if((sum/2)%2)ans+=(i*2);
	}cout<<ans+x0%2*x1%2<<endl;
}