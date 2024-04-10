#include<iostream>
#include<cstdio>
#include<set>
#define MN 200000
#define N 262144
#define ll long long
#define pa pair<ll,int>
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
ll tt[MN+5];
int n,K,m,cnum,aa[MN+5],bb[MN+5];
struct Car{int x;ll t;int id;
	bool operator < (const Car&b)const{return t==b.t?id<b.id:t<b.t;}
/*	friend Car operator +(const Car&a,const Car&b)
	{
		return a.t==b.t?(a.id<b.id?a:b):(a.t<b.t?a:b);
	}*/
}T[N*2+5];
multiset<int> s;
set<Car> S,s2[MN+5];
/*
void Renew(int x,Car v)
{
	for(T[x+=N]=v;x>>=1;)
		T[x]=T[x<<1]+T[x<<1|1];	
}*/

void Add(int x,Car v)
{
//	cout<<"Add"<<x<<endl;
	s.insert(x);
	s2[x].insert(v);	++cnum;
//	Renew(x,*s2[x].begin());
}

void Del(int x,Car v)
{
//	cout<<"del"<<x<<endl;
	s.erase(s.find(x));
	s2[x].erase(s2[x].find(v));  --cnum;
//	if(!s2[x].size()) Renew(x,(Car){0,(ll)1e18,0});
//	else Renew(x,*s2[x].begin());
}
inline int abs(int x){return x<0?-x:x;}
int main()
{
	n=read();K=read();m=read();
	for(int i=1;i<=K;++i)
	{
		int x=read();
		Add(x,(Car){x,0,i}); 
	}
	for(int i=1;i<=m;++i) tt[i]=read(),aa[i]=read(),bb[i]=read();
	ll nowtime=0;
	for(int i=1;i<=m;)
		if(!cnum||(S.size()&&S.begin()->t<=tt[i]))
		{
			ll ti=S.begin()->t;	nowtime=ti;
			while(S.size()&&S.begin()->t==ti)
			{
				Add(S.begin()->x,*S.begin());	
				S.erase(S.begin());
			}
		}
		else
		{
			nowtime=max(nowtime,tt[i]);
			int mindis=1e9,v;
			multiset<int>::iterator it=s.lower_bound(aa[i]);
			if(it!=s.end()) mindis=min(mindis,*it-aa[i]);
			if(it!=s.begin()) mindis=min(mindis,aa[i]-*(--it)); 
			if(aa[i]+mindis<=n&&s2[aa[i]+mindis].size()&&(aa[i]-mindis<=0||!(s2[aa[i]-mindis].size())||(*s2[aa[i]+mindis].begin()<*s2[aa[i]-mindis].begin())))
				v=aa[i]+mindis;
			else v=aa[i]-mindis;
		//	cout<<v<<" "<<mindis<<endl;
			printf("%d %lld\n",s2[v].begin()->id,nowtime+mindis-tt[i]);
			S.insert((Car){bb[i],nowtime+abs(v-aa[i])+abs(aa[i]-bb[i]),s2[v].begin()->id});
			Del(v,*s2[v].begin());
			++i;
		}
	return 0;
}