#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=110;
int n,a[N],c[2],ans,d1,d2,c1,c2,pre,p=-1;
vector<int>v[2],vv[2];
int main(){
	scanf("%d",&n);c[0]=n/2;c[1]=n-c[0];
	if(n==1)puts("0"),exit(0);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(!a[i])continue;a[i]&=1;
		if(a[i]==p)v[a[i]].pb(i-pre-1);
		else if(p!=-1)ans++;
		if(p==-1)vv[a[i]].pb(i-1);
		pre=i;p=a[i];c[a[i]]--;
	}
	if(p==-1)puts("1"),exit(0);
	vv[p].pb(n-pre);
	for(int i=0;i<2;i++){
		sort(v[i].begin(),v[i].end());
		for(int j=0;j<v[i].size();j++)
			if(c[i]>=v[i][j])c[i]-=v[i][j];
			else{ans+=2*(v[i].size()-j);break;}
		sort(vv[i].begin(),vv[i].end());
		for(int j=0;j<vv[i].size();j++)
			if(c[i]>=vv[i][j])c[i]-=vv[i][j];
			else{ans+=(vv[i].size()-j);break;}
	}
	cout<<ans;
	return 0;
}