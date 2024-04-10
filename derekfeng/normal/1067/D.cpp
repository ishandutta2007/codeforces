#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<db,db> pdd;
#define mkp make_pair
#define fi first
#define se second
int n,a,b,ed;
db p,M;
ll T;
vector<pdd>v;
pdd sta[100004];
db cros(pdd a,pdd b){return (b.se-a.se)/(a.fi-b.fi);}
db r[100004],ret;
db mat[35][3][3],cur[3]; 
int main(){
	scanf("%d%I64d",&n,&T);
	for(int i=0;i<n;i++){
		scanf("%d%d%lf",&a,&b,&p);
		M=max(M,p*b);
		v.push_back(mkp(p,-p*a));
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		if(i>0&&v[i].fi==v[i-1].fi)continue;
		v[i].se*=-1;
		while(ed>1&&cros(sta[ed-1],sta[ed])>cros(sta[ed],v[i]))ed--;
		sta[++ed]=v[i];
	}
	for(int i=1;i<ed;i++)r[i]=cros(sta[i],sta[i+1]);
	r[ed]=1e18+114; 
	db lst=0;ll t1=0;
	for(int i=1;i<=ed;i++){
		if(t1==T||(t1*M-lst)>=r[i])continue;
		mat[0][0][0]=1-sta[i].fi,mat[0][0][1]=0,mat[0][0][2]=0;
		mat[0][1][0]=sta[i].fi*M,mat[0][1][1]=1,mat[0][1][2]=0;
		mat[0][2][0]=sta[i].se,mat[0][2][1]=1,mat[0][2][2]=1;
		for(int j=1;j<=33;j++){
			for(int i1=0;i1<3;i1++)for(int j1=0;j1<3;j1++){
				mat[j][i1][j1]=0;
				for(int k=0;k<3;k++)mat[j][i1][j1]+=mat[j-1][i1][k]*mat[j-1][k][j1];
			}
		}
		for(int j=33;j>=0;j--){
			if(t1+(1ll<<j)>=T)continue;
			cur[0]=lst,cur[1]=t1,cur[2]=1;
			ret=0;
			for(int k=0;k<3;k++)ret+=cur[k]*mat[j][k][0];
			if(M*(t1+(1ll<<j))-ret<r[i])lst=ret,t1+=(1ll<<j);
		}
		cur[0]=lst,cur[1]=t1,cur[2]=1;
		lst=0;
		for(int j=0;j<3;j++)lst+=cur[j]*mat[0][j][0];
		t1++;
	}
	printf("%.6lf",lst);
}