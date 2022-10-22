#include<bits/stdc++.h>
using namespace std;
vector<int> read(){
	static char s[105];
	scanf("%s",s);
	vector<int> x; x.resize(26);
	int n=strlen(s);
	for(int i=0;i<n;++i)
		x[s[i]-'a']++;
	return x;
}
map<vector<int>,int> query(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	map<vector<int>,int> mp;
	for(int i=l;i<=r;++i)
		for(int j=i;j<=r;++j)
			mp[read()]++;
	return mp;
}
inline vector<int> operator-(vector<int> a,vector<int> b){
	vector<int> c; c.resize(26);
	for(int i=0;i<a.size();++i) c[i]=a[i]-b[i];
	return c;
}
inline int count(vector<int> a){
	int ret=0;
	for(int i=0;i<a.size();++i) ret+=a[i];
	return ret;
}
vector<int> f[105];
int main(){
	int n; scanf("%d",&n);
	if(n==1){
		auto x=query(1,n);
		printf("! ");
		for(auto t:x){
			for(int i=0;i<26;++i)
				if(t.first[i])
					putchar(i+'a');
		}
		puts("");
		return 0;
	}
	auto x=query(1,n);
	auto y=query(1,n-1);
	for(auto t:y)	
		x[t.first]-=t.second;
	for(auto t:x)
		if(t.second>0)
			f[count(t.first)]=t.first;
	for(int i=n;i>=2;--i)
		f[i]=f[i]-f[i-1];
	printf("! ");
	for(int i=n;i>=1;--i){
		for(int j=0;j<f[i].size();++j)
			if(f[i][j]>0)
				putchar(j+'a');
	}
	puts("");
	fflush(stdout);
	return 0;
}