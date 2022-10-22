#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,q,a[200005];
int s[200005],N;
int m,sa[200005],rk[200005],lcp[200005];
int num[200005],nsa[200005];
int st[20][200005],lg[200005];
int get(int p,int x){return p+x>N?0:rk[p+x];}
void qsort(int x,int *a,int *b,int m){
	fill(num+1,num+m+1,0);
	for(int i=1;i<=N;i++)num[get(i,x)]++;
	for(int i=1;i<=m;i++)num[i]+=num[i-1];
	for(int i=N;i;i--)b[num[get(a[i],x)]--]=a[i];
}
bool cmp(int a,int b,int x){
	if(rk[a]!=rk[b])return rk[a]<rk[b];
	return get(a,x)<get(b,x);
}
void builtsa(){
	vector<int>all;
	for(int i=1;i<n;i++)s[++N]=a[i+1]-a[i];
	s[++N]=-1e9;
	for(int i=1;i<n;i++)s[++N]=a[i]-a[i+1];
	for(int i=1;i<=N;i++)all.push_back(s[i]);
	sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
	for(int i=1;i<=N;i++)s[i]=lower_bound(all.begin(),all.end(),s[i])-all.begin()+1;
	m=all.size();for(int i=1;i<=N;i++)rk[i]=s[i],nsa[i]=i;
	qsort(0,nsa,sa,m);num[sa[1]]=m=1;
	for(int i=2;i<=N;i++)m+=cmp(sa[i-1],sa[i],0),num[sa[i]]=m;
	for(int i=1;i<=N;i++)rk[i]=num[i];
	for(int k=1;m<N;k<<=1){
		qsort(k,sa,nsa,m),qsort(0,nsa,sa,m);
		num[sa[1]]=m=1;
		for(int i=2;i<=N;i++)m+=cmp(sa[i-1],sa[i],k),num[sa[i]]=m;
		for(int i=1;i<=N;i++)rk[i]=num[i];
	}
	for(int i=1;i<=N;i++){
		if(rk[i]>1){
			lcp[rk[i]]=max(lcp[rk[i-1]],1);
			while(max(i,sa[rk[i]-1])+lcp[rk[i]]-1<=N){
				if(s[i+lcp[rk[i]]-1]!=s[sa[rk[i]-1]+lcp[rk[i]]-1])break;
				lcp[rk[i]]++;
			}
			lcp[rk[i]]--;
		}
		if(i>1)lg[i]=lg[i>>1]+1;
	}
	for(int i=1;i<=N;i++)st[0][i]=lcp[i];
	for(int t=1;t<20;t++)
		for(int i=1;i+(1<<t)-1<=N;i++)
			st[t][i]=min(st[t-1][i],st[t-1][i+(1<<(t-1))]);
}
int Qry(int l,int r){
	int Lg=lg[r-l];
	return min(st[Lg][l],st[Lg][r-(1<<Lg)+1]);
}
int ans[100005];
vector<pair<pii,pii> >qr[200005];
int bit[100005];
void upd(int i){for(;i<=n;i+=i&-i)bit[i]++;}
int ask(int i){int a=0;for(;i;i-=i&-i)a+=bit[i];return a;}
int qry(int l,int r){return ask(r)-ask(l-1);}
void getqry(){
	for(int i=1;i<=q;i++){
		int l,r;scanf("%d%d",&l,&r);
		int len=r-l;
		if(!len){
			ans[i]=l-1+n-r;
			continue;
		}
		int pos=rk[n+l],ld,rd,L,R;
		ld=0,rd=pos+1;
		while(rd>ld+1){
			int md=(ld+rd)/2;
			if(md>=pos){rd=md;continue;}
			if(md<1){ld=md;continue;}
			if(Qry(md+1,pos)>=len)rd=md;
			else ld=md;
		}
		L=rd;
		ld=pos-1,rd=N+1;
		while(rd>ld+1){
			int md=(ld+rd)/2;
			if(md<=pos){ld=md;continue;}
			if(md>N){rd=md;continue;}
			if(Qry(pos+1,md)>=len)ld=md;
			else rd=md;
		}
		R=ld;
		ld=l-len-1,rd=r+1;
		if(ld>0){
			qr[L-1].push_back({{1,ld},{i,-1}});
			qr[R].push_back({{1,ld},{i,1}});
		}
		if(rd<=n){
			qr[L-1].push_back({{rd,n},{i,-1}});
			qr[R].push_back({{rd,n},{i,1}});
		}
	}
	for(int i=1;i<=N;i++){
		if(sa[i]<n)upd(sa[i]);
		for(auto [p,j]:qr[i]){
			auto [id,x]=j;
			auto [l,r]=p;
			ans[id]+=x*qry(l,r);
		}
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&q);
	if(n==1){while(q--)puts("0");return 0;}
	builtsa(),getqry();
}