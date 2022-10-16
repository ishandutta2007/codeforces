#include<bits/stdc++.h>
using namespace std;
int T,n,a[300003],q,cnt[300003];
long long w;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++){
			scanf("%d",a+i);
			int j=2;
			while(j<=sqrt(a[i])){
				while(a[i]%(j*j)==0)
					a[i]=a[i]/j/j;
				j++;
			}
		}
		vector<int>v;
		for(int i=0;i<n;i++)
			v.push_back(a[i]);
		sort(v.begin(),v.end());
		v.erase(unique(v.begin(),v.end()),v.end());
		map<int,int>mp;
		for(int i=0;i<v.size();i++)cnt[i]=0;
		for(int i=0;i<v.size();i++)
			mp[v[i]]=i;
		for(int i=0;i<n;i++)
			cnt[mp[a[i]]]++;
		long long ans0=0,ans1=0;
		for(int i=0;i<v.size();i++)
			ans0=max(ans0,1ll*cnt[i]);
		for(int i=0;i<v.size();i++)
			if(cnt[i]%2==0||v[i]==1)
				ans1+=cnt[i];
		cin>>q;
		while(q--){
			scanf("%lld",&w);
			if(w==0)
				printf("%lld\n",ans0);
			else
				printf("%lld\n",max(ans0,ans1));
		}
	}
}