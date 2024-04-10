#include<bits/stdc++.h>
using namespace std;
const long long inf=10000000000000000;
int n,m,q,a[100003],b[100003],c[100003],d[100003];
int hd[100003],nxt[200003],val[200003],N;
long long dis[100003];
int HD[100003],NXT[100003],M,VAL[100003];
int _dis[100003];
void reinit(){
	for(int i=0;i<m;i++)
		d[i]=min(dis[a[i]]+c[i]-dis[b[i]],(long long)n);
	memset(_dis,31,sizeof(_dis));
	int I=0;
	M=0;HD[0]=M;VAL[M]=0;NXT[M++]=-1;
	_dis[0]=0;
	int cnt=0;
	while(I<=n)
		if(HD[I]==-1)
			I++;
		else{
			int nw=VAL[HD[I]];HD[I]=NXT[HD[I]];
			if(_dis[nw]!=I)continue;
			for(int i=hd[nw];i!=-1;i=nxt[i])
				if(d[val[i]]+_dis[nw]<_dis[b[val[i]]]&&d[val[i]]+_dis[nw]<=n){
					_dis[b[val[i]]]=_dis[nw]+d[val[i]];
					VAL[M]=b[val[i]];
					NXT[M]=HD[_dis[b[val[i]]]];
					HD[_dis[b[val[i]]]]=M++;
				}
		}
	for(int i=0;i<n;i++)
		dis[i]+=_dis[i];
}
char _c;
void read(int &x){
	_c='?';x=0;
	while(_c>'9'||_c<'0')_c=getchar();
	while(_c<='9'&&_c>='0')x=10*x+_c-'0',_c=getchar();
}
vector<int>v[2003];
long long ans[2003];
int main(){
	read(n);read(m);read(q);
	memset(hd,-1,sizeof(hd));
	for(int i=0;i<m;i++){
		read(a[i]);
		read(b[i]);
		read(c[i]);
		a[i]--;b[i]--;
		nxt[N]=hd[a[i]];
		val[N]=i;
		hd[a[i]]=N++;
	}
	priority_queue<pair<long long,int> >p;
	memset(dis,31,sizeof(dis));dis[0]=0;
	p.push({0,0});
	while(p.size()){
		long long len=-p.top().first;int nw=p.top().second;p.pop();
		if(dis[nw]!=len)continue;
		for(int i=hd[nw];i!=-1;i=nxt[i])
			if(dis[b[val[i]]]>len+c[val[i]]){
				dis[b[val[i]]]=len+c[val[i]];
				p.push({-len-c[val[i]],b[val[i]]});
			}
	}
	for(int i=0;i<q;i++){
		int tp,x;
		read(tp);
		if(tp==1){
			read(x);
			if(dis[x-1]>inf)
				printf("-1\n");
			else
				printf("%lld\n",dis[x-1]);
		}else{
			read(tp);
			while(tp--)
				read(x),c[x-1]++;
			reinit();
		}
	}
}