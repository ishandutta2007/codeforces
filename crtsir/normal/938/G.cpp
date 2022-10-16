#include<bits/stdc++.h>
using namespace std;
const int pw=262144;
struct Linear_basis{
	int a[33];
	void init(){
		memset(a,0,sizeof(a));
	}
	void add(int x){
//		cout<<x<<' '<<endl;
		for(int i=29;i>=0;i--)
			if(x&(1<<i))
				if(a[i])
					x^=a[i];
				else{
					a[i]=x;
					break;
				}
	}
	int query(int x){
//		cout<<x<<endl;
		for(int i=29;i>=0;i--)
			if((x^a[i])<x)
				x^=a[i];
		return x;
	}
}nw;
vector<int>datx[524288],daty[524288],datd[524288];
int n,m,q,qidx[524288],sz[200003],fa[200003],len[200003],ans[200003],qx[524288],qy[524288];
int fnd(int x){if(fa[x]!=x)return fnd(fa[x]);return x;}
int fndlen(int x){if(fa[x]!=x)return fndlen(fa[x])^len[x];return 0;}
void dfs(int k){
	if(k>=pw){
//		for(int i=0;i<n;i++)cout<<fa[i]<<' '<<sz[i]<<' '<<len[i]<<"    ";cout<<endl;
		if(qidx[k]>=0)ans[qidx[k]]=nw.query(fndlen(qx[k])^fndlen(qy[k]));
		return;
	}
	vector<int>X,Y,SZ;
	for(int i=0;i<datx[k].size();i++)
		if(fnd(datx[k][i])!=fnd(daty[k][i])){
			int tmpx=datx[k][i],tmpy=daty[k][i],fndx=fnd(tmpx),fndy=fnd(tmpy);
//			cout<<"tree:"<<tmpx<<' '<<tmpy<<' '<<datd[k][i]<<' '<<fndx<<' '<<fndy<<' '<<len[tmpx]<<endl; 
			if(sz[fndx]<sz[fndy])
//			if(rand()%2)
				swap(tmpx,tmpy),swap(fndx,fndy);
			X.push_back(fndx);
			Y.push_back(fndy);
			SZ.push_back(sz[fndx]);
			len[fndy]=datd[k][i]^fndlen(tmpy)^fndlen(tmpx);
			fa[fndy]=fndx;
			sz[fndx]+=sz[fndy];
			sz[fndy]=0;
		}else
			nw.add(datd[k][i]^fndlen(datx[k][i])^fndlen(daty[k][i]));
	Linear_basis tmp=nw;
	dfs(k<<1);
	nw=tmp;
	dfs(k<<1|1);
	for(int i=X.size()-1;i>=0;i--){
		sz[Y[i]]=sz[X[i]]-SZ[i];
		sz[X[i]]=SZ[i];
		fa[Y[i]]=Y[i];
		len[Y[i]]=0;
	}
}
void add(int l,int r,int L,int R,int k,int x,int y,int d){
	if(L<=l&&r<=R){
//		cout<<l<<' '<<r<<' '<<x<<' '<<y<<' '<<d<<endl;
		datx[k].push_back(x);
		daty[k].push_back(y);
		datd[k].push_back(d);
		return;
	}
	if(L>r)return;
	if(R<l)return;
	add(l,l+r>>1,L,R,k<<1,x,y,d);
	add(l+r+1>>1,r,L,R,k<<1|1,x,y,d);
}
map<long long,int>mp,mpd;
set<long long>s;
int main(){
	srand(time(NULL));
	cin>>n>>m;
	for(int i=0;i<n;i++)fa[i]=i,sz[i]=1;
	for(int i=0;i<m;i++){
		int x,y,d;
		scanf("%d%d%d",&x,&y,&d);x--;y--;
		if(x>y)swap(x,y);
		mp[1ll*x*n+y]=0;
		mpd[1ll*x*n+y]=d;
		s.insert(1ll*x*n+y);
	}memset(qidx,-1,sizeof(qidx));
	int q,N=0;cin>>q;
	for(int i=1;i<=q;i++){
		int tp,x,y,d;
		scanf("%d%d%d",&tp,&x,&y);x--;y--;
		if(x>y)swap(x,y);
		if(tp==1){
			scanf("%d",&d);
			mp[1ll*x*n+y]=i;
			mpd[1ll*x*n+y]=d;
			s.insert(1ll*x*n+y);
		}
		if(tp==2){
			add(0,pw-1,mp[1ll*x*n+y],i,1,x,y,mpd[1ll*x*n+y]);
			s.erase(1ll*x*n+y);
		}
		if(tp==3){
			qidx[i+pw]=N++;
			qx[i+pw]=x;qy[i+pw]=y;
		}
	}
	while(s.size()){
		long long nw=(*s.begin());s.erase(s.begin());
		add(0,pw-1,mp[nw],q+1,1,nw/n,nw%n,mpd[nw]);
	}dfs(1);
	for(int i=0;i<N;i++)
		printf("%d\n",ans[i]);
}