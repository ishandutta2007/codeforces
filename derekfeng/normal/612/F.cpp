#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define mkp make_pair
#define fi first
#define se second
int n,s,cnt;
vector<pii>all;
vector<int>pos[2003];
int f[2003],fr[2003];
int m,num,a[2003];
void gettrans(int s,vector<int>p){
	m=p.size(),num=0;
	int pos=-1;
	for(int i=0;i<m;i++)if(p[i]>=s){pos=i;break;}
	if(pos<0)pos=0;
	for(int i=0;i<m;i++)a[++num]=p[(pos+i)%m];
}
void soldp(int s,int w){
	for(int i=1;i<=m;i++){
		int W=w+(a[i]+n-s)%n+(i<m?(s+n-a[i+1])%n:0)*2;
		if(W<f[a[i]])f[a[i]]=W,fr[a[i]]=s;
		W=w+(i<2?0:(a[i-1]+n-s)%n)*2+(s+n-a[i])%n;
		if(W<f[a[i]])f[a[i]]=W,fr[a[i]]=s;
	}
}
vector<int>res;
void makepath(int s,int t){
	int pos;
	for(int i=1;i<=m;i++)if(a[i]==t){pos=i;break;}
	int W1=(t+n-s)%n+(pos<m?(s+n-a[pos+1])%n:0)*2;
	int W2=(pos<2?0:(a[pos-1]+n-s)%n)*2+(s+n-t)%n;
	if(W1<W2){
		for(int i=m;i>pos;i--)res.push_back(-(s+n-a[i])%n),s=a[i];
		for(int i=1;i<=pos;i++)res.push_back((a[i]+n-s)%n),s=a[i];
	}else{
		for(int i=1;i<pos;i++)res.push_back((a[i]+n-s)%n),s=a[i];
		for(int i=m;i>=pos;i--)res.push_back(-(s+n-a[i])%n),s=a[i];
	}
}
void dfs(int x,int cur){
	if(x>1)dfs(x-1,fr[cur]);
	gettrans(fr[cur],pos[x]);
	makepath(fr[cur],cur);
}
int main(){
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++){
		pii x;x.se=i;
		scanf("%d",&x.fi);
		all.push_back(x);
	}
	sort(all.begin(),all.end());
	for(int i=0,j;i<n;){
		++cnt;
		for(j=i;j<n&&all[j].fi==all[i].fi;j++){
			pos[cnt].push_back(all[j].se);
			if(cnt==1&&all[j].se==s)res.push_back(0),pos[cnt].pop_back();
		}
		if(pos[cnt].empty())cnt--;
		i=j;
	}
	if(cnt==0){
		puts("0\n+0");
		return 0;
	}
	for(int i=1;i<=n;i++)f[i]=1e9;
	gettrans(s,pos[1]),soldp(s,0);
	for(int i=2;i<=cnt;i++)
		for(auto x:pos[i-1])
			gettrans(x,pos[i]),soldp(x,f[x]);
	int ans=1e9,cur;
	for(auto x:pos[cnt])if(f[x]<ans)ans=f[x],cur=x;
	printf("%d\n",ans);
	dfs(cnt,cur);
	for(auto x:res){
		if(x>=0)putchar('+');
		printf("%d\n",x);
	}
}