#include<bits/stdc++.h>
using namespace std;
int n,a[100003];
vector<int>findmin(vector<int>v){
	if(!v.size())return {};
	int tmp=a[v[0]];
	vector<int>ret;
	ret.push_back(v[0]);
	for(int i=2;i<=tmp;i++)
		if(tmp%i==0){
			int lst=-1,sum=2333;
			for(int j=0;j<v.size();j++){
				int ttmp=a[v[j]],cnt=0;
				while(ttmp%i==0)
					ttmp/=i,cnt++;
				if(cnt<sum)
					sum=cnt,lst=v[j];
			}
			ret.push_back(lst);
			while(tmp%i==0)tmp/=i;
		}
	sort(ret.begin(),ret.end());
	ret.erase(unique(ret.begin(),ret.end()),ret.end());
	tmp=0;
	for(int i=0;i<ret.size();i++)
		tmp=__gcd(tmp,a[ret[i]]);
	for(int i=0;i<ret.size();i++){
		int nw=0;
		for(int j=0;j<ret.size();j++)
			if(i!=j)
				nw=__gcd(nw,a[ret[j]]);
		if(nw==tmp){
			vector<int>V;
			for(int j=0;j<ret.size();j++)
				if(i!=j)
					V.push_back(ret[j]);
			return V;
		}
	}
	return ret;
}
void solve(vector<int>v){
	sort(v.begin(),v.end());
	int sum=0;
	for(int i=1;i<(1<<v.size());i++)
		sum+=abs(__builtin_popcount(i)-2);
	cout<<sum<<'\n';
	for(int i=1;i<(1<<v.size());i++){
		int cnt=__builtin_popcount(i)-2;
		if(__builtin_popcount(i)&1)
			cnt=-cnt;
		for(int j=0;j<cnt;j++){
			cout<<0<<' '<<__builtin_popcount(i)<<' ';
			for(int k=0;k<v.size();k++)
				if((1<<k)&i)
					cout<<v[k]+1<<' ';
			cout<<'\n';
		}
		for(int j=cnt;j<0;j++){
			cout<<1<<' '<<__builtin_popcount(i)<<' ';
			for(int k=0;k<v.size();k++)
				if((1<<k)&i)
					cout<<v[k]+1<<' ';
			cout<<'\n';
		}
	}
}
int main(){
	cin>>n;
	vector<int>v;
	for(int i=0;i<n;i++)
		cin>>a[i],
		v.push_back(i);
	vector<int>g=findmin(v);v.clear();
	for(int i=0;i<n;i++){
		bool ok=1;
		for(int j=0;j<g.size();j++)
			if(g[j]==i)
				ok=0;
		if(ok)
			v.push_back(i);
	}
	vector<int>h=findmin(v);
	while(h.size()){
		g.push_back(h.back());
		h.pop_back(); 
	}
	solve(g);
}