#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
map<int,int>mp;
int dat[32][1048576],n,q,val[32],a[300003];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(mp.find(a[i])==mp.end())
			mp[a[i]]=rng();
		int tmp=mp[a[i]];
		for(int j=0;j<32;j++)
			if(tmp&(1<<j))
				dat[j][i+524288]=1;
	}
	for(int i=524287;i>0;i--)
		for(int j=0;j<32;j++)
			dat[j][i]=dat[j][i<<1]+dat[j][i<<1|1];
	while(q--){
		int tp;
		cin>>tp;
		if(tp==1){
			int i,x;
			cin>>i>>x;i--;a[i]=x;
			if(mp.find(a[i])==mp.end())
				mp[a[i]]=rng();
			int tmp=mp[a[i]];
			for(int j=0;j<32;j++)
				if(tmp&(1<<j))
					dat[j][i+524288]=1;
				else
					dat[j][i+524288]=0;
			i+=524288;
			while(i>1){
				i>>=1;
				for(int j=0;j<32;j++)
					dat[j][i]=dat[j][i<<1]+dat[j][i<<1|1];
			}
		}else{
			int l,r,k;
			cin>>l>>r>>k;
			l--;r--;
			l+=524287;r+=524289;
			memset(val,0,sizeof(val));
			for(;l^r^1;l>>=1,r>>=1){
				if(~l&1)
					for(int i=0;i<32;i++)
						val[i]+=dat[i][l^1];
				if(r&1)
					for(int i=0;i<32;i++)
						val[i]+=dat[i][r^1];
			}
			string ans="YES\n";
			for(int i=0;i<32;i++)
				if(val[i]%k)
					ans="NO\n";
			cout<<ans;
		}
	}
}