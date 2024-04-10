#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2000010;
int i,j,k,n,m,Min[maxn],a[maxn],b[maxn],W[99],S[99];
string S1,S2;
ll ans=0;
int main(){
	cin>>S1>>S2;
	n=S1.size();m=S2.size();
	for(i=0;i<n;i++)a[i+1]=S1[i]%3;
	for(i=0;i<m;i++)b[i+1]=S2[i]%3;
	int len=1;
	for(i=1;i<=n;i++){
		Min[i]=len;
		if(len!=m+1 && a[i]==b[len])++len;
//		cout<<"Min["<<i<<"]="<<Min[i]<<endl;
	}len=1;int w=1;
	for(i=1;i<=m;i++){
		while(w!=n && Min[w+1]<=i)w++,W[a[w-1]*3+a[w]]++;
		ans+=max(w-len+1,0);
//		cout<<"ans="<<ans<<" i="<<i<<" len="<<len<<" w="<<w<<endl;
		if(i!=1 && b[i]!=b[i-1])ans-=max(0,W[b[i-1]+b[i]*3]);
//		cout<<ans<<endl;
		if(b[i]==a[len] && len!=n+1)++len,W[a[len-1]*3+a[len]]--;
		if(len==n+1)break;
	}cout<<ans<<endl;
	return 0;
}