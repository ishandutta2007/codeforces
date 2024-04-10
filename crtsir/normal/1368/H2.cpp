#include<bits/stdc++.h>
using namespace std;
const int inf=19260817;
struct mat{
	int a[2][2];
	mat(){memset(a,31,sizeof(a));}
};
struct tree{
	int n;//0 R 1 B
	mat dat[2][2][262144];
	bool rev[2][262144];
	mat tmp;
	tree(){memset(rev,0,sizeof(rev));tmp.a[0][0]=inf;tmp.a[1][0]=inf;tmp.a[0][1]=inf;tmp.a[1][1]=inf;}
	mat merge(mat x,mat y){
		if(x.a[0][0]>=inf)return y;
		if(y.a[0][0]>=inf)return x;
		mat ret;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					for(int l=0;l<2;l++)
						ret.a[i][l]=min(ret.a[i][l],x.a[i][j]+y.a[k][l]+(j^k)*n);
		return ret;
	}
	void init(string s,string t,int N){
		n=N;
		for(int i=0;i<s.size();i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++){
					dat[j][k][i+131072].a[0][0]=int((s[i]!='R')^j)+int((t[i]!='R')^k);
					dat[j][k][i+131072].a[0][1]=inf;
					dat[j][k][i+131072].a[1][0]=inf;
					dat[j][k][i+131072].a[1][1]=int((s[i]!='B')^j)+int((t[i]!='B')^k);
				}
		for(int i=131071;i>0;i--)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					dat[j][k][i]=merge(dat[j][k][i<<1],dat[j][k][i<<1|1]);
/*		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++)
				cout<<dat[0][0][1].a[i][j]<<' ';
			cout<<endl;
		}*/
	}
	void SWAP(int tp,int k){
		if(tp==0){
			swap(dat[0][0][k],dat[1][0][k]);
			swap(dat[0][1][k],dat[1][1][k]);
		}else{
			swap(dat[0][0][k],dat[0][1][k]);
			swap(dat[1][0][k],dat[1][1][k]);
		}
	}
	void pushdown(int k){
		if(rev[0][k]){
			SWAP(0,k<<1);
			SWAP(0,k<<1|1);
			rev[0][k<<1]^=rev[0][k];
			rev[0][k<<1|1]^=rev[0][k];
		}
		if(rev[1][k]){
			SWAP(1,k<<1);
			SWAP(1,k<<1|1);
			rev[1][k<<1]^=rev[1][k];
			rev[1][k<<1|1]^=rev[1][k];
		}
		rev[0][k]=0;rev[1][k]=0; 
	}
	void modify(int _l,int _r,int l,int r,int k,int tp){
		if(l<=_l&&_r<=r){
			rev[tp][k]^=1;
			SWAP(tp,k);
			return;
		}
		if(l>_r||r<_l)return;
		pushdown(k);
		modify(_l,_l+_r>>1,l,r,k<<1,tp);
		modify(_l+_r+1>>1,_r,l,r,k<<1|1,tp);
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				dat[i][j][k]=merge(dat[i][j][k<<1],dat[i][j][k<<1|1]);
	}
	mat query(int _l,int _r,int l,int r,int k){
		if(l<=_l&&_r<=r)return dat[0][0][k];
		if(l>_r||r<_l)return tmp;
		pushdown(k);
		return merge(query(_l,_l+_r>>1,l,r,k<<1),query(_l+_r+1>>1,_r,l,r,k<<1|1));
	}
}pos,neg;//pos  cutton  
struct str{
	int dat[2][262144],lzy[262144];
	void init(string s){
		memset(dat,0,sizeof(dat));
		memset(lzy,0,sizeof(lzy));
		for(int i=0;i<s.size();i++)
			if(s[i]=='R')
				dat[0][i+131072]=1;
			else
				dat[1][i+131072]=1;
		for(int i=131071;i>0;i--){
			dat[0][i]=dat[0][i<<1]+dat[0][i<<1|1];
			dat[1][i]=dat[1][i<<1]+dat[1][i<<1|1];
		}
	}
	void pushdown(int k){
		if(lzy[k])
			swap(dat[0][k<<1],dat[1][k<<1]),
			swap(dat[0][k<<1|1],dat[1][k<<1|1]),
			lzy[k<<1]^=1,lzy[k<<1|1]^=1;
		lzy[k]=0;
	}
	void modify(int _l,int _r,int l,int r,int k){
		if(l<=_l&&_r<=r){
			lzy[k]^=1;
			swap(dat[0][k],dat[1][k]);
			return;
		}
		if(l>_r||r<_l)return;
		pushdown(k);
		modify(_l,_l+_r>>1,l,r,k<<1);
		modify(_l+_r+1>>1,_r,l,r,k<<1|1);
		dat[0][k]=dat[0][k<<1]+dat[0][k<<1|1];
		dat[1][k]=dat[1][k<<1]+dat[1][k<<1|1];
	}
}l,r,u,d;
int n,m;
int getans(){
	mat pret=pos.query(0,131071,0,m-1,1),nret=neg.query(0,131071,0,n-1,1);
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			pret.a[i][j]+=l.dat[i^1][1];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			pret.a[i][j]+=r.dat[j^1][1];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			nret.a[i][j]+=u.dat[i^1][1];
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			nret.a[i][j]+=d.dat[j^1][1];
	int ret=inf;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++){
			ret=min(ret,pret.a[i][j]);
			ret=min(ret,nret.a[i][j]);
		}
//	for(int i=0;i<2;i++)
//		cout<<nret.a[i][i]<<' ';
//	cout<<endl;
	return ret;
}
string s,t;
int q;
int main(){
	cin>>n>>m>>q;
	cin>>s>>t;
	l.init(s);
	r.init(t);
	neg.init(s,t,m);
	cin>>s>>t;
	u.init(s);
	d.init(t);
	pos.init(s,t,n);
	printf("%d\n",getans());
	while(q--){
		char c;
		int L,R;
		cin>>c>>L>>R;L--;R--;
		if(c=='L')l.modify(0,131071,L,R,1),neg.modify(0,131071,L,R,1,0);
		if(c=='R')r.modify(0,131071,L,R,1),neg.modify(0,131071,L,R,1,1);
		if(c=='U')u.modify(0,131071,L,R,1),pos.modify(0,131071,L,R,1,0);
		if(c=='D')d.modify(0,131071,L,R,1),pos.modify(0,131071,L,R,1,1);
		printf("%d\n",getans());
	}
}