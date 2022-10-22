#include<bits/stdc++.h>
using namespace std;
int a[5],b[5],n_;
int trans[12][12];
vector<int>v;
int dat[12][400000];
int n,q;
char s[100004];
void init(){
	for(int i=1;i<32;i++){
		for(int j=0;j<5;j++)a[j]=(i>>j)&1;
		if(!a[0]&&a[3])continue;
		if(!a[1]&&a[3])continue;
		if(!a[1]&&a[4])continue;
		if(!a[2]&&a[4])continue;
		v.push_back(i);
	}
	for(int p=0;p<v.size();p++)
		for(int q=0;q<v.size();q++){
			int x=v[p],y=v[q];
			for(int j=0;j<5;j++)a[j]=(x>>j)&1,b[j]=(y>>j)&1;
			trans[p][q]=-1;
			if(a[0]&&b[4])continue;
			if(a[3]&&b[2])continue;
			int msk=0;
			for(int j=0;j<5;j++)if(a[j]||b[j])msk|=(1<<j);
			if(a[0]&&b[1])msk|=8;
			if(a[1]&&b[2])msk|=16;
			for(int z=0;z<v.size();z++)if(v[z]==msk)trans[p][q]=z;
		}
}
void pushup(int id){
	for(int i=0;i<12;i++)dat[i][id]=1e9;
	for(int i=0;i<12;i++)if(dat[i][id<<1]<1e9)
		for(int j=0;j<12;j++)if(trans[i][j]!=-1)
			dat[trans[i][j]][id]=min(dat[trans[i][j]][id],dat[i][id<<1]+dat[j][id<<1|1]);
}
void init(int id,char c){
	for(int i=0;i<12;i++)dat[i][id]=1e9;
	dat[0][id]=dat[1][id]=dat[3][id]=1;
	if(c=='a')dat[0][id]=0;
	if(c=='b')dat[1][id]=0;
	if(c=='c')dat[3][id]=0;
}
void built(int i,int l,int r){
	if(l>n)return;
	if(l==r){
		init(i,s[l]);
		return;
	}
	int md=(l+r)>>1;
	built(i<<1,l,md),built(i<<1|1,md+1,r);
	pushup(i);
}
void upd(int i,char c){
	i+=n_-1;
	init(i,c);
	for(;i>1;)i>>=1,pushup(i);
}
int main(){
	init();
	scanf("%d%d%s",&n,&q,s+1);
	n_=1;while(n_<n)n_<<=1;
	built(1,1,n_);
	while(q--){
		int p;char buf[3];
		scanf("%d%s",&p,buf);
		upd(p,buf[0]);
		int ans=1e9;
		for(int i=0;i<12;i++)ans=min(ans,dat[i][1]);
		printf("%d\n",ans);
	}
}