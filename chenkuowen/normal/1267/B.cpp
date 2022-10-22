#include<bits/stdc++.h>
using namespace std;
namespace IO{
	const int sz=1<<20;
	char a[sz+5],b[sz+5],*p1=a,*p2=a,*t=b,p[105];
	inline char gc(){
		return getchar();
		return p1==p2?(p2=(p1=a)+fread(a,1,sz,stdin)
			,(p1==p2?EOF:*p1++)):*p1++;
	}
	template<class T> void gi(T& ret){
		ret=0; char c=gc(); int f=1;
		for(;c<'0'||c>'9';c=gc())
			if(c=='-') f=-1;
		for(;c>='0'&&c<='9';c=gc())
			ret=ret*10+(c-'0');
		ret*=f;
	}
	template<class T> void gi_mod(T& ret,int MOD){
		ret=0; char c=gc(); 
		for(;c<'0'||c>'9';c=gc());
		for(;c>='0'&&c<='9';c=gc())
			ret=(ret*10ll+(c-'0'))%MOD;
	}
	inline void flush(){ fwrite(b,1,t-b,stdout),t=b; }
	inline void pc(char x){ *t++=x; if(t-b==sz) flush(); }
	template<class T> void pi(T x,char c='\n'){
		if(x<0) pc('-'),x=-x;
		if(x==0) pc('0'); int t=0;
		for(;x;x/=10) p[++t]=x%10+'0';
		for(;t;--t) pc(p[t]); pc(c);
	}
}
using IO::gi;
using IO::pi;
using IO::gi_mod;
const int MAX_N=5+3e5;
char s[MAX_N];
vector<pair<char,int> > v;
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;++i)
		if(i==1||s[i]!=s[i-1]) v.push_back(make_pair(s[i],1));
		else v[v.size()-1].second++;
	for(int i=0;i<v.size();++i){
		int j=v.size()-i-1;
		if(i==j){
			if(v[i].second>1){
				printf("%d\n",v[i].second+1);
				return 0;
			}
		}
		if(i>j) break;
		if(v[i].first!=v[j].first||v[i].second+v[j].second<3)
			break;
	}
	puts("0");
	return 0;
}