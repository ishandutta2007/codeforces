#include<bits/stdc++.h>
using namespace std;
const long long maxn=1000000000000000007;
const int mod=998244353,bs=7,w=2;
int n,m;
string f[203],st[203],ed[203],tmp,suf[203];
int pw[203];
long long ans[203],k;
int hsh(string s){
	int ret=0;
	for(int i=0;i<s.size();i++)
		ret=(1ll*ret*bs+w+s[i]-'0')%mod;
	return ret;
}
long long query(string s){
	int lm=s.size()-1;ans[0]=0;ans[1]=0;
	if(lm){
		st[0]='0';ed[0]='0';
		st[1]='1';ed[1]='1';
	}else{
		st[0]="";ed[0]="";
		st[1]="";ed[1]="";
		if(s=="0")ans[0]=1;
		if(s=="1")ans[1]=1;
	}
	int qaq=hsh(s);
	for(int i=2;i<=n;i++){
		st[i]=st[i-2];
		int j=0;
		while(st[i].size()<lm&&j<st[i-1].size())
			st[i]=st[i]+st[i-1][j++];
		ed[i]=ed[i-1];
		j=ed[i-2].size()-1;
		while(ed[i].size()<lm&&j>=0)
			ed[i]=ed[i-2][j--]+ed[i];
		ans[i]=ans[i-1]+ans[i-2];
		tmp=ed[i-2]+st[i-1];
		int qwq=0;
		for(int j=0;j<lm;j++)
			qwq=(1ll*qwq*bs+tmp[j]-'0'+w)%mod;
		for(int j=lm;j<tmp.size();j++){
			qwq=(1ll*qwq*bs+tmp[j]-'0'+w)%mod;
			if(qaq==qwq)ans[i]++;
			qwq=(qwq-1ll*(tmp[j-lm]-'0'+w)*pw[lm]%mod+mod)%mod;
		}
		if(ans[i]>maxn)ans[i]=maxn;
//		cout<<st[i]<<' '<<ed[i]<<endl;
	}
	for(int i=0;i<m;i++)
		if(suf[i].size()>=s.size())
			if(suf[i].substr(0,s.size())==s)
				ans[n]--;
	return ans[n];
}
long long check(string s,string lst){
	while(lst.size()<s.size())lst+='0';
	long long ret=0;
	string nw;
	for(int i=0;i<s.size();i++){
		nw+='0';
		if(s[i]=='1'&&lst[i]=='0'){
			ret+=query(nw);
			if(ret>maxn)ret=maxn;
		}
		if(s[i]=='1')
			nw[i]='1';
	}
	for(int i=0;i<m;i++)
		if(suf[i]!="")
			if(suf[i]<s&&suf[i]>=lst)
				ret++;
//	cout<<ret<<endl;
	return ret;
}
string br[203];
int main(){
	br[0]='0';br[1]='1';
	for(int i=2;i<203;i++){
		br[i]=br[i-2]+br[i-1];
		if(br[i].size()>200)
			br[i]=br[i].substr(br[i].size()-200);
	}
	pw[0]=1;
	for(int i=1;i<203;i++)pw[i]=1ll*pw[i-1]*bs%mod;
	cin>>n>>k>>m;
	if(m>br[n].size())m=br[n].size();
	for(int i=0;i<m-1;i++)
		if(i+1<br[n].size())
			suf[i]=br[n].substr(br[n].size()-i-1);
	sort(suf,suf+m-1);
	int Ll=0,Rr=m-2,mid;
	if(m!=1){
		while(Ll!=Rr){
			mid=(Ll+Rr>>1);
			string Q=suf[mid];
			while(Q.size()<m)Q+='0';
			long long ct=check(Q,"");
			if(ct>=k)
				Rr=mid;
			else
				Ll=mid+1;
		}
		string Q=suf[Ll];
		while(Q.size()<m)Q+='0';
		if(check(Q,"")==k){
			cout<<suf[Ll];
			return 0;
		}
	}
	string ans;
	for(int i=0;i<m;i++)ans+='0';
	long long al=0;
	for(int i=0;i<m;i++){
		string t=ans;
		ans[i]='1';
		long long ct=check(ans,t);
//		cout<<ct<<endl;
		if(ct+al>=k)
			ans[i]='0';
		else
			al+=ct;
	}
	cout<<ans;
}