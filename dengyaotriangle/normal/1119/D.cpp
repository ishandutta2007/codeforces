#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn=100005;
 
struct qry{
	long long dv;
	int i;
};
 
int n;
long long t[maxn];
qry qs[maxn];
long long an[maxn];
long long dls[maxn];
 
bool cm1(qry a,qry b){
	return a.dv<b.dv;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>t[i];
	sort(t+1,t+1+n);
	for(int i=1;i<n;i++) dls[i]=t[i+1]-t[i];
	sort(dls+1,dls+n);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		qs[i].i=i;
		long long l,r;
		cin>>l>>r;
		qs[i].dv=r-l;
	}
	sort(qs+1,qs+1+q,cm1);
	long long ans=0;
	long long cl=0;
	long long dlt=n;
	int dli=1;
	int qi=1;
	while(dls[dli]<=cl&&dli<n){
		dlt--;
		dli++;
	}
	ans+=dlt;
	while(1){
		if((qs[qi].dv<dls[dli]||dli>=n)&&qi<=q){
			ans+=(qs[qi].dv-cl)*dlt;
			cl=qs[qi].dv;
			an[qs[qi].i ]=ans;
			qi++;
		}else if(dli<n){
			ans+=(dls[dli]-1-cl)*dlt;
			cl=dls[dli]-1;
			dlt--;
			dli++;
		}else break;
	}
	for(int i=1;i<=q;i++) cout<<an[i]<<' ';
	return 0;
}//yyy