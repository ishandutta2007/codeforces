#include<bits/stdc++.h>
using namespace std;
int n;
int a,b,ans;
int f[200004],c[200004];
int suf[200004];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		if(a<=n&&b<=n)return puts("-1"),0;
		int cost=0;
		if(a>b)cost=1,swap(a,b);
		if(a<=n)f[a]=b,c[a]=cost;
	}
	for(int i=n;i;i--)suf[i]=max(suf[i+1],f[i]);
	int pre=1e9;
	vector<int>v1,v2;
	int cost1=0,cost2=0;
	for(int i=1;i<=n;i++){
		pre=min(pre,f[i]);
		if(v1.empty()||f[v1.back()]>f[i])v1.push_back(i),cost1+=c[i]; 
		else if(v2.empty()||f[v2.back()]>f[i])v2.push_back(i),cost2+=c[i];
		else return puts("-1"),0;
		if(pre>suf[i+1]){
			int s1=v1.size(),s2=v2.size();
			ans+=min(cost1+s2-cost2,cost2+s1-cost1);
			cost1=cost2=0;
			v1.clear(),v2.clear();
		}
	}
	cout<<ans;
}