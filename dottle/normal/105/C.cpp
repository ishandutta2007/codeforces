#include<bits/stdc++.h>
#define int long long
const int N=1005;
using namespace std;

string A="weapon",B="armor",C="orb";
string X="gladiator",Y="sentry",Z="physician";
map<string,int> mp,Id,pd;
struct item{
	string name,type;
	int at,df,rs,sz,ct;
	void input(){cin>>name>>type>>at>>df>>rs>>sz;} 
}a[N];
struct people{
	string name,type;
	int dl,home;
	void input(){string x;cin>>name>>type>>dl>>x,home=Id[x];};
	bool operator < (people b){
		return dl>b.dl;
	}
}b[N],c[N];

int n,m;
int fl,po[N];
int vis[N];
pair<pair<int,int>,vector<string>> ans[4];

void solve1(){
	sort(b+1,b+1+m);
	for(int i=1;i<=m;i++)
		pd[b[i].name]=i;
	for(int i=1;i<=n;i++){
		int na;
		vector<string> nw;
		if(a[i].type==A)na=a[i].at;
		if(a[i].type==B)na=a[i].df;
		if(a[i].type==C)na=a[i].rs;
		for(int j=1;j<=m;j++){
			if(a[i].sz==a[i].ct)break;
			if(mp[b[j].type]==mp[a[i].type])
				na+=b[j].dl,a[i].ct++,nw.push_back(b[j].name);
		}
		int t=mp[a[i].type];
		ans[t]=max(ans[t],make_pair(make_pair(na,i),nw));
	}
	for(int i=1;i<=3;i++)
		for(auto x:ans[i].second)
			vis[pd[x]]=1;
	for(int nw=1,i=1;i<=3;i++){
		int id=ans[i].first.second;
		while(a[id].ct!=a[id].sz){
			while(nw<=m&&vis[nw])nw++;
			if(nw>m)break;
			ans[i].second.push_back(b[nw].name);
			a[id].ct++;
			nw++;
		}
	}
	for(int i=1;i<=3;i++){
		int id=ans[i].first.second;
		cout<<a[id].name<<' '<<a[id].ct<<' ';
		for(auto x:ans[i].second)cout<<x<<' ';
		cout<<endl;
	}
}

void solve2(){
	for(int i=1;i<=n;i++){
		int na;
		vector<string> nw;
		if(a[i].type==A)na=a[i].at;
		if(a[i].type==B)na=a[i].df;
		if(a[i].type==C)na=a[i].rs;
		for(int j=1;j<=m;j++){
			if(b[j].home==i){
				if(mp[b[j].type]==mp[a[i].type])na+=b[j].dl;
				a[i].ct++,nw.push_back(b[j].name);
			}
		}
		int t=mp[a[i].type];
		ans[t]=max(ans[t],make_pair(make_pair(na,i),nw));
	}
	for(int i=1;i<=3;i++){
		int id=ans[i].first.second;
		cout<<a[id].name<<' '<<a[id].ct<<' ';
		for(auto x:ans[i].second)cout<<x<<' ';
		cout<<endl;
	}
}

void init(){
	mp[A]=mp[X]=1;
	mp[B]=mp[Y]=2;
	mp[C]=mp[Z]=3;
}

void solve(){
	cin>>n;
	init();
	for(int i=1;i<=n;i++){
		a[i].input();
		Id[a[i].name]=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		b[i].input();
		c[i]=b[i];
		po[b[i].home]++;
	}
	for(int i=1;i<=n;i++)
		if(po[i]<a[i].sz)
			fl=1;
	if(fl)solve1();
	else solve2();
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}