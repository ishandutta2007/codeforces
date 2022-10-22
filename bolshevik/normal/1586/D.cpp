#include<iostream>
using namespace std;
int n,p[210],q[210],cnt,ans[210],d[210];
void slv(int n){
	if(!n) return;
	if(n==1){ans[p[1]]=1;return;}
	for(int i=1,x;1;++i){
		if(i==n) x=0;
		else{
			for(int j=1;j<=::n;++j) d[j]=::n;
			for(int j=1;j<n;++j) d[p[j]]=1;
			d[p[n]]=i+1;
			cout<<"?";
			for(int j=1;j<=::n;++j) cout<<" "<<d[j];
			cout<<endl;cin>>x;
		}
		if(!x){
			ans[p[n]]=n-i+1;cnt=0;
			for(int j=1;j<n;++j)
				if(ans[p[j]]) ans[p[j]]+=ans[p[n]];else q[++cnt]=p[j];
			for(int j=1;j<=cnt;++j) p[j]=q[j];
			slv(cnt);
			return;
		}
		ans[x]=i;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;++i) p[i]=i;
	slv(n);
	cout<<"!";
	for(int i=1;i<=n;++i) cout<<" "<<ans[i];
	cout<<endl;
	return 0;
}