#include<bits/stdc++.h>
using namespace std;
const int B=200000;
string s;long long msk,tmp=1,_mp[B+3];
map<long long,int>mp;
int main(){cin>>s;int cnt=1;
	while(s.size()&&s[0]=='0')
		s=s.substr(1),cnt++;
	if(!s.size()){cout<<"-1";return 0;}
	int n=s.size();for(int i=0;i<n;i++)
		msk|=(s[i]-48ll<<i);
	for(int i=0;i<B;i++){mp[tmp]=i;
		if(tmp&1)tmp^=msk;tmp>>=1;_mp[i+1]=tmp;}msk=1;
	for(int i=1;i<=B;i++){tmp=0;
		for(int j=0;j<n;j++)
			if(msk&(1ll<<j))
				tmp^=_mp[B-j];
		msk=tmp;if(mp.find(msk)!=mp.end())
		{cout<<cnt<<' '<<1ll*i*B+cnt-mp[msk];return 0;}
	}cout<<-1;
}