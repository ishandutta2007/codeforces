#include<bits/stdc++.h>

using namespace std;

typedef unsigned int uint;
typedef pair<int,int> pii;
#define mp make_pair
#define se second
#define fr first

const int MX=200005,MXW=33,MXS=MX*MXW;
int n;
struct ips{
	int l;uint pr;
	void regpr(){pr&=(l==0?0:(-1u)<<(32-l));}
	ips(uint _pr=0,int _l=0):l(_l),pr(_pr){regpr();}
	ips(string s){
		l=32;
		int i=0,n=s.length();
		uint buf=0;
		#define clrbuf() (pr=pr<<8|buf,buf=0)
		for(;i<n;i++){
			char c=s[i];
			if(c=='.')clrbuf();
			else if(isdigit(c))buf=buf*10u+(uint)(c-'0');
			else if(c=='/'){
				l=0;i++;break;
			}
		}
		clrbuf();
		#undef clrbuf
		for(;i<n;i++){
			char c=s[i];
			if(isdigit(c))l=l*10+c-'0';
		}
		regpr();
	}
	void print(){uint tpr=pr;for(int i=0;i<4;tpr<<=8,i++)cout<<(tpr>>24)<<(i==3?'/':'.');cout<<l<<endl;}
};
vector<ips>ans;

void GG(){cout<<-1<<endl;exit(0);}

struct trie{
	trie* s[2];int typ;
	trie():typ(0){s[0]=s[1]=NULL;}
	uint dfsck(){
		uint r=(typ?(typ==1?1:2):0);
		for(int i=0;i<2;i++)if(s[i])r|=s[i]->dfsck();
		if(typ&&r==3)GG();
		return r;
	}
	void dfs(){
		for(int i=0;i<2;i++)if(s[i])s[i]->dfs();
		for(int j=1;j>=-1;j-=2){
			for(int i=0;i<2;i++)if(s[i]){
				if(s[i]->typ==j){
					typ=j;
					return;
				}
			}
		}
	}
	void dfsp(ips v){
		if(typ==-1){ans.push_back(v);return;}
		for(int i=0;i<2;i++)if(s[i]){
			s[i]->dfsp(ips(v.pr|(i<<(31-v.l)),v.l+1));
		}
	}
}pol[MXS],*nn=pol,*rot;

void analysisip(string s){
	ips ts(s.substr(1));
	// ts.print();
	trie* t=rot;
	for(int i=0;i<ts.l;i++){
		int x=(ts.pr>>(31-i))&1;
		t=t->s[x]?t->s[x]:(t->s[x]=nn++);
	}
	int ty=(s[0]=='-'?-1:1);
	if(t->typ&&t->typ!=ty)GG();
	else t->typ=ty;
}
int main(){
	ios::sync_with_stdio(false);
	rot=nn++;
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		analysisip(s);
	}
	rot->dfsck();
	rot->dfs();
	rot->dfsp(ips(0,0));
	cout<<ans.size()<<endl;
	for(auto i:ans)i.print();
	return 0;
}