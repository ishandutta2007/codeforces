#include<bits/stdc++.h>
#define ll __int128
#define N 1005
using namespace std;
ll read_ll(){
	ll x=0;
	string s;
	cin>>s;
	int i;
	for(i=0;i<s.length();++i)x=x*10+(ll)(s[i]-'0');
	return x;
}
ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}
ll a[N],b[N],g[N][N];
ll ta[N][N<<2],tb[N][N<<2];
ll val[N];
bool boa[N],bob[N];
void up(ll *t,int x){
	t[x]=gcd(t[x<<1],t[x<<1|1]);
}
void init(ll *t,int i,int l,int r,ll *val){
	if(l==r){
		t[i]=val[l];
		return;
	}
	int mid=(l+r)>>1;
	init(t,i<<1,l,mid,val);
	init(t,i<<1|1,mid+1,r,val);
	up(t,i);
}
void modify(ll *t,int i,int l,int r,int x,ll val){
	if(l==r){
		t[i]=val;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)modify(t,i<<1,l,mid,x,val);
	else modify(t,i<<1|1,mid+1,r,x,val);
	up(t,i);
}
void print_ll(ll x){
	if(x==0){
		puts("0");
		return;
	}
	vector<int>p;
	while(x>0){
		p.push_back(x%10);
		x/=10;
	}
	for(int i=p.size()-1;i>=0;--i)printf("%d",p[i]);
	printf(" ");
}
int main(){
	int T,n,m,i,j;
	bool flg;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i){
			a[i]=read_ll();
			boa[i]=1;
		}
		for(i=1;i<=m;++i){
			b[i]=read_ll();
			bob[i]=1;
		}
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j)g[i][j]=gcd(a[i],b[j]);			
		}
		for(i=1;i<=n;++i){
			for(j=1;j<=m;++j)val[j]=a[i]/g[i][j];
			init(ta[i],1,1,m,val);
		}
		for(i=1;i<=m;++i){
			for(j=1;j<=n;++j)val[j]=b[i]/g[j][i];
			init(tb[i],1,1,n,val);
		}
		flg=1;
		while(flg){
			flg=0;
			for(i=1;i<=n;++i){
				if(!boa[i])continue;
				if(ta[i][1]!=1){
					flg=1;
					boa[i]=0;
					for(j=1;j<=m;++j){
						modify(tb[j],1,1,n,i,b[j]);
					}
				}
			}
			for(i=1;i<=m;++i){
				if(!bob[i])continue;
				if(tb[i][1]!=1){
					flg=1;
					bob[i]=0;
					for(j=1;j<=n;++j){
						modify(ta[j],1,1,m,i,a[j]);
					}
				}
			}
		}
		
		int s1=0,s2=0;
		for(i=1;i<=n;++i)s1+=boa[i];
		for(j=1;j<=m;++j)s2+=bob[j];
		if(s1==0||s2==0){
			puts("NO");
			continue;
		}
		else{
			printf("YES\n%d %d\n",s1,s2);
			for(i=1;i<=n;++i)if(boa[i])print_ll(a[i]);puts("");
			for(i=1;i<=m;++i)if(bob[i])print_ll(b[i]);puts("");
		}
	}
	return 0;
}