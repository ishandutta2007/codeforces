#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353;
set<int> s;
int mn[N],mx[N];
int n,m;
int a[N],b[N],c[N];
vector<int> v1[N],v2[N];
int main(){
	int i,j;
	cin>>n>>m;
	memset(mn,0x3f,sizeof(mn));
	for(i=1;i<=n;i++) cin>>a[i],c[i]=a[i];
	for(i=1;i<=n;i++){
		if(!a[i]) continue;
		for(j=i-1;j&&a[j]==0;j--) a[j]=a[i];
		for(j=i+1;j<=n&&a[j]==0;j++) a[j]=a[i]; 
	}
	for(i=1;i<=n;i++) if(!a[i]) a[i]=m;
	for(i=1;i<=n;i++){
		mn[a[i]]=min(mn[a[i]],i);
		mx[a[i]]=max(mx[a[i]],i);
	}
	if(!mx[m]){
		for(i=1;i<=n;i++){
			if(!c[i]){
				a[i]=m;
				mx[m]=mn[m]=i;
				break;
			}
		}
	}
	if(!mx[m]){
		cout<<"NO";
		return 0;
	}
	for(i=1;i<=m;i++){
		if(mx[i]==0) continue;
		v1[mn[i]].push_back(i);
		v2[mx[i]].push_back(i);
	}
	for(i=1;i<=n;i++){
		for(auto x:v1[i]) s.insert(x);
		auto it=s.end();it--;
		b[i]=(*it);
		for(auto x:v2[i]) s.erase(x);
	}
	for(i=1;i<=n;i++){
		if(a[i]!=b[i]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}