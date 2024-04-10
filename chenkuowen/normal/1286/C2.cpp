#include<bits/stdc++.h>
using namespace std;
struct Key{
	vector<int> a;
	inline int& operator[](int x){ return a[x]; }
	Key(){ a.resize(26); fill(a.begin(),a.end(),0); }
	Key operator-(Key b){
		Key c;
		for(int i=0;i<26;++i)
			c[i]=a[i]-b[i];
		return c;
	}
	bool operator<(Key b) const{return a<b.a;}
	int count() const{
		int ret=0;
		for(int i=0;i<26;++i)
			ret+=a[i];
		return ret;
	}
	char get(){
		for(int i=0;i<26;++i)
			if(a[i]>0) return i+'a';
	}
};
Key read(){
	static char s[205];
	scanf("%s",s); int n=strlen(s);
	Key ret;
	for(int i=0;i<n;++i)
		ret[s[i]-'a']++;
	return ret;
}
map<Key,int> query(int l,int r){
	if(l>r) return map<Key,int>();
	printf("? %d %d\n",l,r);
	fflush(stdout);
	map<Key,int> mp;
	for(int i=l;i<=r;++i)
		for(int j=i;j<=r;++j)
			mp[read()]++;
	return mp;
}
char ans[105];
void solve1(int l,int r){
	auto x=query(l,r),y=query(l,r-1);
	for(auto t:y) x[t.first]-=t.second;
	static Key f[105];
	for(auto t:x)
		if(t.second>0)
			f[t.first.count()]=t.first;
	for(int i=1;i<=r-l+1;++i)
		ans[r-i+1]=(f[i]-f[i-1]).get();
}
map<Key,int> g[105];
Key all;
int n;
Key get_inter(int l,int r){
	bool flag1=1,flag2=1;
	for(int i=1;i<=n;++i){
//		putchar(ans[i]);
		if(ans[i]=='0'){
			if(i<l||i>r)
				flag1=0;
			else
				flag2=0;
		}
	}
//	puts("");
	Key ret;
	if(flag1){
		ret=all;
		for(int i=1;i<l;++i)
			ret[ans[i]-'a']--;
		for(int i=r+1;i<=n;++i)
			ret[ans[i]-'a']--;
	}else if(flag2){
		for(int i=l;i<=r;++i)
			ret[ans[i]-'a']++;
	}else{
		puts("GG");
		exit(0);
	}
	return ret;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) ans[i]='0';
	int m=n+1>>1;
	solve1(1,m);
	auto x=query(1,n);
//	for(int i=1;i<=n;++i) putchar(ans[i]); puts("");
	for(auto t:x)
		g[t.first.count()][t.first]+=t.second;
	all=g[n].begin()->first;
	for(int i=n-1;i>=1;--i){
		for(int j=2;i+j-1<=n;++j)
			g[i][get_inter(j,j+i-1)]--;
		for(auto x:g[i])
			if(x.second>0){
				ans[i+1]=(get_inter(1,i+1)-x.first).get();
			}
	}
	printf("! ");
	for(int i=1;i<=n;++i) putchar(ans[i]);
	puts(""); fflush(stdout);
	return 0;
}