#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define mkp make_pair
#define fi first
#define se second
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	register char ch=getchar();s="";
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
map<int,int>mp;
string type;
int n_=1,cnt,q,dat[524300],p[200004],p1,p2;
set<int>st[200004];
vector<piii>v;
void upd(int id,int x){
	dat[id]=x;
	while(id)id=(id-1)/2,dat[id]=max(dat[id*2+1],dat[id*2+2]);
}
pii bs(int id,int x){
	if(id>n_-2) return mkp(id-n_+1,(*(st[id-n_+1].lower_bound(x+1))));
	if(dat[id*2+1]>x) return bs(id*2+1,x);
	return bs(id*2+2,x);
}
pii got(int l,int r,int id,int a,int b,int x){
	if(b<l || r<a) return mkp(-1,-1);
	if(a<=l && r<=b){
		if(dat[id]>x) return bs(id,x);
		return mkp(-1,-1);
	}
	pii A=got(l,(l+r)/2,id*2+1,a,b,x);
	if(A.fi>=0) return A;
	return got((l+r+1)/2,r,id*2+2,a,b,x);
}
int main(){
	v.push_back(mkp(114514,mkp(1919,810))); 
	read(q);
	for(int i=1;i<=q;i++){
		reads(type),read(p1),read(p2);
		if(type[0]=='a')v.push_back(mkp(0,mkp(p1,p2))),mp[p1]=1;
		if(type[0]=='r')v.push_back(mkp(1,mkp(p1,p2)));
		if(type[0]=='f')v.push_back(mkp(2,mkp(p1,p2)));
	}
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)it->second=cnt,p[cnt++]=it->first;
	while(n_<cnt)n_<<=1;
	for(int i=0;i<cnt;i++)st[i].insert(0);
	for(int i=1;i<=q;i++){
		if(v[i].fi==0){
			p1=v[i].se.fi,p2=v[i].se.se;
			p1=mp[p1];
			if(p2==0)continue;
			st[p1].insert(p2);
			if(dat[p1+n_-1]<(*st[p1].rbegin()))upd(p1+n_-1,(*st[p1].rbegin()));
		}
		if(v[i].fi==1){
			p1=v[i].se.fi,p2=v[i].se.se;
			p1=mp[p1];
			if(p2==0)continue;
			st[p1].erase(st[p1].find(p2));
			if(dat[p1+n_-1]>(*st[p1].rbegin()))upd(p1+n_-1,(*st[p1].rbegin()));
		}
		if(v[i].fi==2){
			int p1=lower_bound(p,p+cnt,v[i].se.fi+1)-p;
			pii res=got(0,n_-1,0,p1,cnt-1,v[i].se.se);
			if(res.fi<0)puts("-1");
			else write(p[res.fi]),putchar(' '),write(res.se),puts("");
		}
	}
}