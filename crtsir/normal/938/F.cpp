#include<bits/stdc++.h>
using namespace std;
string s;
int n,k,nxt[2103][5003],K,tim;
pair<long long,int>minn[8192];
long long val[5003],pw=26;
int main(){
	cin>>s;
	n=s.size();s=' '+s;
	K=log2(n);
	tim=n-(1<<K)+1;
	for(int i=1;i<=n;i++){
		nxt[1][i]=-1;
		val[i]=s[i]-'a';
	}
	for(int k=2;k<=tim;k++){
		for(int y=1;y<=n+2-k;y++)
			minn[n-y+2-k]=make_pair(val[y],y);
		for(int i=0;i<K;i++)
			for(int j=0;j<(1<<K);j++)
				if(j&(1<<i))
					minn[j]=min(minn[j],minn[j^(1<<i)]);
		for(int x=1;x<=n+1-k;x++){
			val[x]=(s[x]-'a')*pw+minn[n+1-k-x].first;
			nxt[k][x]=minn[n+1-k-x].second;
		}
		if(pw>=3000000000000000){
			vector<long long>v;
			for(int i=1;i<=n+1-k;i++)
				v.push_back(val[i]);
			sort(v.begin(),v.end());
			v.erase(unique(v.begin(),v.end()),v.end());
			unordered_map<long long,int>mp;
			for(int i=0;i<v.size();i++)
				mp[v[i]]=i;
			for(int i=1;i<=n+1-k;i++)
				val[i]=mp[val[i]];
			pw=n;
		}else
			pw*=26;
	}
	pair<long long,int>st;st.first=pw*26;
	for(int i=1;i<=n+1-tim;i++)
		st=min(st,make_pair(val[i],i));
	int nw=st.second;
	while(tim){
		cout<<s[nw];
		nw=nxt[tim--][nw];
	}
}