#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 200005
#define maxq 200005
#define maxt 1000005
#define ll long long 
using namespace std;

const ll p1=31,mo1=1000000007,p2=29,mo2=998244353;
int n,q,i,j,k,a[maxn],t[2][maxt],ts[maxt],f1[maxn],f2[maxn],cntc[maxn][26];
ll hs1[maxn],hs2[maxn],mp1[maxn],mp2[maxn];
vector<ll> g1[maxn],g2[maxn];

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

ll Hash1(int l,int r){return hs1[r]-hs1[l-1]*mp1[r-l+1];}
ll Hash2(int l,int r){return hs2[r]-hs2[l-1]*mp2[r-l+1];}
int pd(int l1,int r1,int l2,int r2){
	return (Hash1(l1,r1)-Hash1(l2,r2))%mo1==0
		&& (Hash2(l1,r1)-Hash2(l2,r2))%mo2==0;
}

void maketree(int x,int l,int r){
	t[0][x]=t[1][x]=n+1;
	if (l==r) return;
	int mid=(l+r)>>1;
	maketree(x<<1,l,mid),maketree(x<<1^1,mid+1,r);
}

void change(int i,int x,int l,int r,int L,int R,int p){
	if (l>R||r<L) return;
	if (L<=l&&r<=R) {t[i][x]=p;return;}
	int mid=(l+r)>>1;
	change(i,x<<1,l,mid,L,R,p);
	change(i,x<<1^1,mid+1,r,L,R,p);
}

void updtree(int x,int l,int r,int t1,int t2){
	t1=min(t1,t[0][x]),t2=min(t2,t[1][x]);
	if (l==r){f1[l]=t1,f2[l]=t2,ts[x]=l+t1*2-1;return;}
	int mid=(l+r)>>1;
	updtree(x<<1,l,mid,t1,t2);
	updtree(x<<1^1,mid+1,r,t1,t2);
	ts[x]=min(ts[x<<1],ts[x<<1^1]);
}

int find(int x,int l,int r,int L,int R){
	if (l>R||r<L) return n+1;
	if (L<=l&&r<=R) return ts[x];
	int mid=(l+r)>>1;
	return min(find(x<<1,l,mid,L,R),find(x<<1^1,mid+1,r,L,R));
}

int rk[maxn],sa[maxn],h[maxn],s[maxn*2],w,d[maxn],v;
int cmp(int i,int j,int k){return s[i]==s[j]&&s[i+k]==s[j+k];}
void GetSA(){
	v=26;
	for(i=1;i<=n;i++) rk[i]=a[i],s[a[i]]++;
	for(i=1;i<=v;i++) s[i]+=s[i-1];
	for(i=1;i<=n;i++) sa[s[rk[i]]--]=i;
	for(k=1;k<n;k<<=1){
		w=0;
		for(i=n-k+1;i<=n;i++) d[++w]=i;
		for(i=1;i<=n;i++) if (sa[i]>k) d[++w]=sa[i]-k;
		memset(s,0,sizeof(int)*(v+1));
		for(i=1;i<=n;i++) s[rk[i]]++;
		for(i=1;i<=v;i++) s[i]+=s[i-1];
		for(i=n;i>=1;i--) sa[s[rk[d[i]]]--]=d[i];
		memcpy(s,rk,sizeof(int)*(n+1));
		rk[sa[1]]=v=1;
		for(i=2;i<=n;i++) rk[sa[i]]=cmp(sa[i],sa[i-1],k)?v:++v;
		if (v>=n) break;
	}
	for(i=1,j=0;i<=n;i++,j=max(0,j-1)){
		while (a[i+j]==a[sa[rk[i]-1]+j]) j++;
		h[rk[i]]=j;
	} 
}

int main(){
	read(n);
	char ch=getchar();
	while (ch<'a'||ch>'z') ch=getchar();
	for(i=1;i<=n;i++) a[i]=ch-'a'+1,ch=getchar();
	for(mp1[0]=mp2[0]=1,i=1;i<=n;i++) {
		mp1[i]=mp1[i-1]*p1%mo1;
		mp2[i]=mp2[i-1]*p2%mo2;
		hs1[i]=(hs1[i-1]*p1+a[i])%mo1;
		hs2[i]=(hs2[i-1]*p2+a[i])%mo2;
	}
	maketree(1,1,n);
	for(k=n/2;k>=1;k--) for(i=k;i+k<=n;i+=k) if (a[i]==a[i+k]){
		j=i+k;
		int lcs=1,lcp=0,l,r,mid;
		l=2,r=k;
		while (l<=r){
			mid=(l+r)>>1;
			if (pd(i-mid+1,i,j-mid+1,j)) lcs=mid,l=mid+1;
			else r=mid-1;
		}
		l=max(k-lcs,1),r=min(k,n-j);
		while (l<=r){
			mid=(l+r)>>1;
			if (pd(i+1,i+mid,j+1,j+mid)) lcp=mid,l=mid+1;
			else r=mid-1;
		}
		if (lcs+lcp>=k) {
			change(0,1,1,n,i-lcs+1,i-k+lcp+1,k);
			change(1,1,1,n,j-lcs+k,j+lcp,k);
		}
	}
	updtree(1,1,n,n+1,n+1);
	GetSA();
	for(i=1;i<=n;i++){
		for(j=0;j<26;j++) cntc[i][j]=cntc[i-1][j];
		cntc[i][a[i]-1]++;
	}
	for(i=1;i<=n;i++) {
		g1[i].push_back(0),g2[i].push_back(0);
		for(j=1;i*j<=n;j++){ 
			g1[i].push_back((g1[i][j-1]*mp1[i]+1)%mo1);
			g2[i].push_back((g2[i][j-1]*mp2[i]+1)%mo2);
		}
	}
	read(q);
	int Sn=sqrt(n);
	while (q--){
		int st,ed,len,tp=0,B; read(st),read(ed),len=ed-st+1,B=sqrt(len);
		for(i=0;i<26;i++) if (cntc[ed][i]-cntc[st-1][i]>1) tp=1;
		if (!tp) {printf("-1\n");continue;}
		for(int d=1;d<=B;d++) if (len%d==0) {
			k=d;
			if ((Hash1(st,st+k-1)%mo1*g1[k][len/k]-Hash1(st,ed))%mo1==0
			&&  (Hash2(st,st+k-1)%mo2*g2[k][len/k]-Hash2(st,ed))%mo2==0)
				{tp=0;break;}
			k=len/d;
			if (k==d||k==len) continue;
			if ((Hash1(st,st+k-1)%mo1*g1[k][len/k]-Hash1(st,ed))%mo1==0
			&&  (Hash2(st,st+k-1)%mo2*g2[k][len/k]-Hash2(st,ed))%mo2==0)
				{tp=0;break;}
		}
		if (!tp) {printf("1\n");continue;}
		if (f1[st]*2<=len||f2[ed]*2<=len) {printf("2\n");continue;}
		for(i=1;i<=Sn&&2*i<=len;i++) if (pd(st,st+i-1,ed-i+1,ed))
			{tp=0;break;}
		if (!tp) {printf("2\n");continue;}
		k=n+1; int cc;
		for(i=rk[st]-1,cc=0;i>=1&&cc<=Sn;i--,cc++) {
			k=min(k,h[i+1]);
			if (k<=Sn) break;
			if ((ed-sa[i]+1)*2<=len&&sa[i]<=ed&&sa[i]>=st&&sa[i]+k>ed)
				{tp=0;break;}
		}
		if (!tp) {printf("2\n");continue;}
		k=n+1;
		for(i=rk[st]+1,cc=0;i<=n&&cc<=Sn;i++,cc++) {
			k=min(k,h[i]);
			if (k<=Sn) break;
			if ((ed-sa[i]+1)*2<=len&&sa[i]<=ed&&sa[i]>=st&&sa[i]+k>ed)
				{tp=0;break;}
		}
		if (!tp) {printf("2\n");continue;}
		if (cntc[ed][a[st]-1]-cntc[st][a[st]-1]
		||  cntc[ed-1][a[ed]-1]-cntc[st-1][a[ed]-1])
			{printf("3\n");continue;}
		if (find(1,1,n,st,ed)<=ed) 
			{printf("3\n");continue;}
		printf("4\n");
	}
}