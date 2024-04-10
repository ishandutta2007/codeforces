//starusc
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=3e5+4;
int n,cur,Ans,cou,a[N],b[N],a1[N],a2[N];
vector<int>duan[2];
inline int solve(int l,int r){
	int ret=0;
	for(int i=l,t1=0;i<=r;i++){
		if(b[i])t1++;
		else ret+=t1;
	}
	return ret;
}
inline void split(int l,int r){
	a1[0]=a2[0]=0;
	for(int i=l;i<=r;i++){
		if(b[i])a2[++a2[0]]=a[i];
		else a1[++a1[0]]=a[i];
	}
	for(int i=1;i<=a1[0];i++)a[i+l-1]=a1[i];
	for(int i=1;i<=a2[0];i++)a[i+l+a1[0]-1]=a2[i];
//	cerr<<a1[0]<<" "<<a2[0]<<" "<<l<<" "<<r<<" \n";
	if(a1[0])duan[cur].push_back(l+a1[0]-1);
	if(a2[0])duan[cur].push_back(r); 
}
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	duan[cur].push_back(n);
	for(int t=30,pre,ans0,ans1;t>=0;t--){
		for(int i=1;i<=n;i++)b[i]=(a[i]>>t)&1;
		cur^=1;
		duan[cur].clear();
		pre=ans0=0;
		for(auto v:duan[cur^1]){
			ans0+=solve(pre+1,v);
			pre=v;
		}
		for(int i=1;i<=n;i++)b[i]=b[i]^1;
		pre=ans1=0;
		for(auto v:duan[cur^1]){
			ans1+=solve(pre+1,v);
			pre=v;
		}
		if(ans0<=ans1){
			cou+=ans0;
		}
		else{
			cou+=ans1;
			Ans|=(1<<t);
		}
//		if(!t)cerr<<ans0<<" "<<ans1<<"\n";
		pre=0;
		for(auto v:duan[cur^1]){
//			if(t==30)cerr<<v<<" ";
			split(pre+1,v);
			pre=v;
		}
//		if(t==30)cerr<<"\n";
//		if(t==30)cerr<<duan[cur].size()<<"\n";
	}
	cout<<cou<<" "<<Ans<<"\n";
	return (0-0);
}