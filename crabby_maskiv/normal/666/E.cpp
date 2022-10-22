#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef pair<int,int> pii;
const int N=6e5+5;
const int L=19;
const int M=5e4+5;
const int B=230;
int sa[N],h[N],tmp[N<<1],rk[N],cnt[N];
int st[L][N],lg[N];
inline void SA(char *a){
	int i,j,m=200,n=strlen(a+1);
	for(i=0;i<=m;i++) cnt[i]=0;
	for(i=1;i<=n;i++) cnt[rk[i]=a[i]]++;
	for(i=1;i<=m;i++) cnt[i]+=cnt[i-1];
	for(i=1;i<=n;i++) sa[++cnt[rk[i]-1]]=i;
	for(j=1;j<=n;j<<=1){
		for(i=0;i<=m;i++) cnt[i]=0;
		for(i=1;i<=n;i++) cnt[rk[i]]++;
		for(i=1;i<=m;i++) cnt[i]+=cnt[i-1];
		for(i=n-j+1;i<=n;i++) tmp[++cnt[rk[i]-1]]=i;
		for(i=1;i<=n;i++)
			if(sa[i]>j) tmp[++cnt[rk[sa[i]-j]-1]]=sa[i]-j;
		for(i=1;i<=n;i++) sa[i]=tmp[i];
		for(i=1;i<=n;i++) tmp[i]=rk[i];
		m=0;
		for(i=1;i<=n;i++)
			rk[sa[i]]=((tmp[sa[i]]==tmp[sa[i-1]]&&tmp[sa[i]+j]==tmp[sa[i-1]+j])?m:++m);
		if(m==n) break;
	}
	for(i=1;i<=n;i++){
		if(rk[i]==1) continue;
		h[rk[i]]=max(h[rk[i-1]]-1,0);
		while(i+h[rk[i]]<=n&&a[i+h[rk[i]]]==a[sa[rk[i]-1]+h[rk[i]]]) h[rk[i]]++;
	}
	for(i=1;i<=n;i++) st[0][i]=h[i];
	for(j=1;j<L;j++){
		for(i=1;i+(1<<j)-1<=n;i++)
			st[j][i]=min(st[j-1][i],st[j-1][i+(1<<j-1)]);
	}
}
char a[N];
int pos[N];
int n,m,k;
int c[M],b,s;
int lft[B],rgt[B],blk[M];
int mx[B][B][B],sum[B][M];
inline int lcp(int x,int y){
	if(x==y) cout<<n-sa[x]+1;
	if(x>y) swap(x,y);
	x++;
	int l=lg[y-x+1];
	return min(st[l][x],st[l][y-(1<<l)+1]);
}
inline pii range(int x,int y){
	pii res;int l=1,r=x;
	while(l<r){
		int mid=l+r>>1;
		if(lcp(mid,x)>=y) r=mid;
		else l=mid+1;
	}
	res.fr=l;
	l=x;r=n;
	while(l<r){
		int mid=l+r+1>>1;
		if(lcp(x,mid)>=y) l=mid;
		else r=mid-1;
	}
	res.sc=l;
	return res;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int i,j,t;
	cin>>(a+1);n=strlen(a+1);
	cin>>m;
	for(i=1;i<=m;i++){
		a[n+1]='#';
		cin>>(a+n+2);
		n=n+1+strlen(a+n+2);
		for(j=n;a[j]!='#';j--) pos[j]=i;
	}
	for(i=1;i<=n;i++) lg[i]=lg[i-1]+(1<<lg[i-1]+1==i);
	SA(a);
	for(i=1;i<=n;i++) tmp[i]=pos[i];
	for(i=1;i<=n;i++) pos[i]=tmp[sa[i]];
	memset(tmp,0,sizeof(tmp));
	//for(i=1;i<=n;i++) cerr<<i<<" "<<h[i]<<" "<<pos[i]<<" "<<(a+sa[i])<<endl;
	for(i=1;i<=n;i++)
		if(pos[i]!=0) c[++k]=i;
	b=sqrt(k);s=(k+b-1)/b;
	for(i=1;i<=s;i++){
		lft[i]=max(i*b-b+1,1);
		rgt[i]=min(i*b,k);
		for(j=lft[i];j<=rgt[i];j++) blk[j]=i;
	}
	//for(i=1;i<=k;i++) cerr<<i<<" "<<c[i]<<" "<<pos[c[i]]<<" "<<blk[i]<<endl;
	for(i=1;i<=s;i++){
		for(j=i;j;j--){
			for(t=1;t<=s;t++) mx[j][i][t]=mx[j+1][i][t];
			for(t=lft[j];t<=rgt[j];t++){
				int w=pos[c[t]];
				sum[i][w]++;
				if(sum[i][w]>sum[i][mx[j][i][blk[w]]]) mx[j][i][blk[w]]=w;
				else if(sum[i][w]==sum[i][mx[j][i][blk[w]]]&&w<mx[j][i][blk[w]]) mx[j][i][blk[w]]=w;
			}
		}
	}
	int q;cin>>q;
	while(q--){
		int l,r,pl,pr;cin>>l>>r>>pl>>pr;
		pii rng=range(rk[pl],pr-pl+1);
		pl=lower_bound(c+1,c+k+1,rng.fr)-c;
		pr=upper_bound(c+1,c+k+1,rng.sc)-c-1;
		//cerr<<"range = "<<pl<<" "<<pr<<endl;
		if(pl>pr){
			cout<<l<<" 0\n";
			continue;
		}
		int ans=0;
		if(blk[pl]==blk[pr]){
			for(i=pl;i<=pr;i++){
				int w=pos[c[i]];
				if(w<l||w>r) continue;
				tmp[w]++;
				if(tmp[w]>tmp[ans]) ans=w;
				else if(tmp[w]==tmp[ans]&&w<ans) ans=w;
			}
			if(ans==0) ans=l;
			cout<<ans<<" "<<tmp[ans]<<'\n';
			for(i=pl;i<=pr;i++) tmp[pos[c[i]]]=0;
			continue;
		}
		for(i=blk[l]+1;i<blk[r];i++){
			int w=mx[blk[pl]+1][blk[pr]-1][i];
			int ans1=sum[blk[pr]-1][w]-sum[blk[pl]][w];
			int ans2=sum[blk[pr]-1][ans]-sum[blk[pl]][ans];
			if(ans1>ans2) ans=w;
			else if(ans1==ans2&&w<ans) ans=w;
		}
		for(i=lft[blk[pr]];i<=pr;i++){
			int w=pos[c[i]];
			if(w<l||w>r) continue;
			tmp[w]++;
			int ans1=sum[blk[pr]-1][w]-sum[blk[pl]][w]+tmp[w];
			int ans2=sum[blk[pr]-1][ans]-sum[blk[pl]][ans]+tmp[ans];
			if(ans1>ans2) ans=w;
			else if(ans1==ans2&&w<ans) ans=w;
		}
		for(i=rgt[blk[pl]];i>=pl;i--){
			int w=pos[c[i]];
			if(w<l||w>r) continue;
			tmp[w]++;
			int ans1=sum[blk[pr]-1][w]-sum[blk[pl]][w]+tmp[w];
			int ans2=sum[blk[pr]-1][ans]-sum[blk[pl]][ans]+tmp[ans];
			if(ans1>ans2) ans=w;
			else if(ans1==ans2&&w<ans) ans=w;
		}
		if(blk[l]==blk[r]){
			for(i=l;i<=r;i++){
				int ans1=sum[blk[pr]-1][i]-sum[blk[pl]][i]+tmp[i];
				int ans2=sum[blk[pr]-1][ans]-sum[blk[pl]][ans]+tmp[ans];
				if(ans1>ans2) ans=i;
				else if(ans1==ans2&&i<ans) ans=i;
			}
		}
		else{
			for(i=l;i<=rgt[blk[l]];i++){
				int ans1=sum[blk[pr]-1][i]-sum[blk[pl]][i]+tmp[i];
				int ans2=sum[blk[pr]-1][ans]-sum[blk[pl]][ans]+tmp[ans];
				if(ans1>ans2) ans=i;
				else if(ans1==ans2&&i<ans) ans=i;
			}
			for(i=lft[blk[r]];i<=r;i++){
				int ans1=sum[blk[pr]-1][i]-sum[blk[pl]][i]+tmp[i];
				int ans2=sum[blk[pr]-1][ans]-sum[blk[pl]][ans]+tmp[ans];
				if(ans1>ans2) ans=i;
				else if(ans1==ans2&&i<ans) ans=i;
			}
		}
		if(ans==0) ans=l;
		cout<<ans<<" "<<sum[blk[pr]-1][ans]-sum[blk[pl]][ans]+tmp[ans]<<'\n';
		for(i=lft[blk[pr]];i<=pr;i++) tmp[pos[c[i]]]=0;
		for(i=rgt[blk[pl]];i>=pl;i--) tmp[pos[c[i]]]=0;
	}
	return 0;
}