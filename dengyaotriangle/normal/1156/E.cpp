#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;


int n;
int a[maxn];
int p[maxn];
stack<int> stk;
int lf[maxn],rh[maxn];
 
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)p[a[i]]=i;
	for(int i=1;i<=n;i++)lf[i]=n+1; 
	for(int i=1;i<=n;i++){
		while(!stk.empty()&&stk.top()<a[i]){
			lf[stk.top()]=i;
			stk.pop();
		}
		stk.push(a[i]);
	}	
	while(!stk.empty())stk.pop();
	for(int i=n;i>=1;i--){
		while(!stk.empty()&&stk.top()<a[i]){
			rh[stk.top()]=i;
			stk.pop();
		}
		stk.push(a[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){ 
		int l=rh[i]+1,r=lf[i]-1,md=p[i];
		if(md-l<r-md){
			for(int j=l;j<md;j++){
				if(p[i-a[j]]>md&&p[i-a[j]]<=r)ans++;
			}
		}else{
			for(int j=r;j>md;j--){
				if(p[i-a[j]]<md&&p[i-a[j]]>=l)ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}