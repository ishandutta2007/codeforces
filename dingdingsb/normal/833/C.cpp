#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll poww[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000ll,100000000000ll,1000000000000ll,10000000000000ll,100000000000000ll,1000000000000000ll,10000000000000000ll,100000000000000000ll,1000000000000000000ll};
ll l,r;int num,mem[20],L[20],R[20],tmp[20],ans;
bool ZLC_AK(int i,bool down,bool up){
	if(i==0)return 1;
	if(down&&up&&L[i]==R[i]){
		if(tmp[L[i]]==0)return false;
		tmp[L[i]]--;
		bool res=ZLC_AK(i-1,1,1);
		tmp[L[i]]++;
		return res;
	}
	int st=L[i]+1,ed=R[i]-1;
	if(!up)ed=9;
	if(!down)st=0;
	for(int i=st;i<=ed;i++)
		if(tmp[i])return true;
	if(tmp[L[i]]&&down){
		tmp[L[i]]--;
		bool res=ZLC_AK(i-1,1,0);
		tmp[L[i]]++;
		if(res)return true;
	}
	if(tmp[R[i]]&&up){
		tmp[R[i]]--;
		bool res=ZLC_AK(i-1,0,1);
		tmp[R[i]]++;
		if(res)return true;
	}
	return false;
}
void ck(){
	if(mem[0]==18)return;
	memcpy(tmp,mem,sizeof mem);
	if(ZLC_AK(18,1,1))ans++;
}
void dfs(int n,int st){
	ck();
	if(poww[n-1]>r)return;
	if(n>18)return;
	for(int i=st;i<=9;i++){
		mem[0]--;mem[i]++;
		dfs(n+1,i);
		mem[0]++;mem[i]--;
	}
}
signed main(){
	//freopen("greed.in","r",stdin);
	//freopen("greed.out","w",stdout);
	cin>>l>>r;
	if(l==r)return puts("1");
	if(r==1000000000000000000ll){
		if(l>100000000000000000ll)
			ans++;
		r--;
	}
	mem[0]=18;
	auto work=[&](ll x,int *a){
		for(int i=1;i<=19;i++)
			a[i]=x%10,x/=10;
	};work(l,L);work(r,R);
	dfs(1,1);cout<<ans;
	return 0;
}