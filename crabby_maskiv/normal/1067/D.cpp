#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<db,db> pdd;
const int N=1e5+5;
const int M=34;
int n,m;
ll t;
db mxb;
pdd a[N],s[N];
int top;
struct mat{
	db x[3][3];
	inline mat(){
		memset(x,0,sizeof(x));
	}
	inline mat operator *(const mat &b)const{
		mat res;
		for(int i=0;i<3;i++)
			for(int k=0;k<3;k++)
				for(int j=0;j<3;j++)
					res.x[i][j]+=x[i][k]*b.x[k][j];
		return res;
	}
};
mat c0[M],c1[M];
inline void prep(mat *c,int i){
	c[0].x[0][0]=1-a[i].sc;
	c[0].x[1][0]=a[i].sc*mxb;
	c[0].x[2][0]=a[i].fr;
	c[0].x[1][1]=1;
	c[0].x[2][1]=1;
	c[0].x[2][2]=1;
	for(int j=1;j<M;j++) c[j]=c[j-1]*c[j-1];
}
int main(){
	int i,j;
	cin>>n>>t;
	for(i=1;i<=n;i++){
		cin>>a[i].fr;
		db b;cin>>b;
		cin>>a[i].sc;
		mxb=max(mxb,b*a[i].sc);
		a[i].fr*=a[i].sc;
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		while(top&&a[i].sc>s[top].sc) top--;
		s[++top]=a[i];
	}
	n=top;
	for(i=1;i<=n;i++) a[i]=s[i];
	prep(c0,n);
	mat dp;ll cur=0;
	dp.x[0][2]=1;
	for(i=n;i>1;i--){
		memcpy(c1,c0,sizeof(c0));
		prep(c0,i-1);
		mat _dp=dp;
		ll ti=cur;
		for(j=M-1;j>=0;j--){
			mat f=_dp*c1[j];
			mat f1=f*c1[0],f2=f*c0[0];
			if(f1.x[0][0]>f2.x[0][0]){
				_dp=f;
				ti+=(1ll<<j);
			}
		}
		mat f1=_dp*c1[0],f2=_dp*c0[0];
		if(f1.x[0][0]>f2.x[0][0]){
			_dp=f1;
			ti++;
		}
		if(ti>=t){
			mat ans=dp;
			for(j=M-1;j>=0;j--)
				if(t-cur>>j&1) ans=ans*c1[j];
			cout<<fixed<<setprecision(10)<<ans.x[0][0];
			return 0;
		}
		cur=ti;
		dp=_dp;
	}
	mat ans=dp;
	for(j=M-1;j>=0;j--)
		if(t-cur>>j&1) ans=ans*c0[j];
	cout<<fixed<<setprecision(10)<<ans.x[0][0];
	return 0;
}