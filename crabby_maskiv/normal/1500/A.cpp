#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
const int M=5e6+5;
int n,m;
int cnt[M],a[N];
pair<int,int> p[M],b[N],c[N];
int vis[M];
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	int c0=0,c1=0;
	for(i=1;i<M;i++){
		if(cnt[i]>1){
			if(c0) c1=i;
			else c0=i;
		}
	}
	for(i=1;i<M;i++){
		if(cnt[i]>=4){
			cout<<"YES"<<endl;
			int f=4;
			for(j=1;j<=n;j++){
				if(f&&a[j]==i){
					cout<<j<<" ";
					f--;
				}
			}
			return 0;
		}
	}
	if(c0&&c1){
		cout<<"YES"<<endl;
		for(i=1;i<=n;i++){
			if(a[i]==c0){
				cout<<i<<" ";
				a[i]=0;break;
			}
		}
		for(i=1;i<=n;i++){
			if(a[i]==c1){
				cout<<i<<" ";
				a[i]=0;break;
			}
		}
		for(i=1;i<=n;i++){
			if(a[i]==c0){
				cout<<i<<" ";
				a[i]=0;break;
			}
		}
		for(i=1;i<=n;i++){
			if(a[i]==c1){
				cout<<i<<" ";
				a[i]=0;break;
			}
		}
		return 0;
	}
	else if(c0){
		for(i=1;i<=n;i++){
			if(a[i]<c0) vis[c0-a[i]]=i;
		}
		for(i=1;i<=n;i++){
			if(a[i]>c0&&vis[a[i]-c0]){
				cout<<"YES"<<endl;
				for(j=1;j<=n;j++){
					if(a[j]==c0){
						cout<<j<<" ";
						a[j]=0;
						break;
					}
				}
				for(j=1;j<=n;j++){
					if(a[j]==c0){
						cout<<j<<" ";
						a[j]=0;
						break;
					}
				}
				cout<<vis[a[i]-c0]<<" ";
				cout<<i<<" ";
				return 0;
			}
		}
	}
	for(i=1;i<=n;i++){
		b[i].first=a[i];b[i].second=i;
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
		if(i==1||b[i].first!=b[i-1].first) c[++m]=b[i];
	for(i=1;i<=m;i++){
		for(j=i+1;j<=m;j++){
			int t=c[j].first+c[i].first;
			if(p[t].first){
				cout<<"YES"<<endl;
				cout<<c[i].second<<" "<<c[j].second<<" "<<p[t].first<<" "<<p[t].second;
				return 0;
			}
			else{
				p[t].first=c[i].second;
				p[t].second=c[j].second;
			}
		}
	}
	cout<<"NO";
	return 0;
}