//And in that light,I find deliverance.
//This code is written by Yiran Empty.
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#undef local
#define ll long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n=read(),m=read(),k;
int a[200003],b[200003],c[200003];
int B[200003],C[200003],cnt[200003],tnc[200003],ntc[200003];
int tv[200003];
ll v[200003],pre[200003],sum[200003];
const int S=230;
int op[233],x[233],y[233];
int f[200003];
//
int pos[233],len,qs;
//
int tA[233],tB[233],tC[233],r[233];
int ta[233][233],tb[233][233],tc[233][233],tf[233][233];
ll ans[233];
//
struct node{int id,val,mul;};
vector<node> qb[200003],qc[200003],qd[200003],qp[200003],qA[200003],qC[200003];
#ifdef local
vector<node> qcc[200003];
#endif
int ca[200003],cb[200003],cc[200003],cd[200003];
int resA[100003],resC[100003],resid[100003],rescnt;
inline void make_query(int id,int val,int l,int r)
{
	(l<r)&&(
	qp[r].push_back((node){id,val,1}),qp[l-1].push_back((node){id,val,-1}),
	++rescnt,resid[rescnt]=id,resA[rescnt]=resC[rescnt]=0,
	qA[l-1].push_back((node){rescnt,val,1}),
	qC[r].push_back((node){rescnt,val,1}),qC[l-1].push_back((node){rescnt,val,-1}),0);
	return ;
}
#ifdef local
ll Ans[233][8];
#endif
int qwq[200003];
inline void fyyakioi(vector<node>&t){vector<node>g;swap(t,g);return ;}
void solve()
{
#ifdef local
	memset(Ans,0,sizeof(Ans));
#endif
	memset(qwq,0,sizeof(qwq));
	//Init
	memset(f,0,sizeof(f)),len=0,rescnt=0,qs=0;
	int tmp=0;
	for(int i=1; i<=k; ++i) (op[i]==1&&!f[x[i]])&&(f[x[i]]=1,pos[++len]=x[i]);
	for(int i=1; i<=n; ++i) (f[i])&&(f[i]=++tmp);
	sort(pos+1,pos+len+1);
	for(int i=1; i<=len; ++i) tA[i]=a[pos[i]],tB[i]=B[pos[i]],tC[i]=C[pos[i]];
	for(int i=1; i<=k; ++i) 
		if(op[i]==1) tA[f[x[i]]]=y[i],tB[f[x[i]]]=b[y[i]],tC[f[x[i]]]=c[y[i]];
		else {r[++qs]=x[i],ans[qs]=0;for(int j=1; j<=len; ++j)ta[qs][j]=tA[j],tb[qs][j]=tB[j],tc[qs][j]=tC[j];}
	//Case 1 S S S
	//Case 2 S S D
	//Case 3 S D S (Queries making)
	for(int i=1; i<=n; ++i) 
#ifdef local
		fyyakioi(qp[i]),
#endif
		fyyakioi(qb[i]),fyyakioi(qc[i]),fyyakioi(qd[i]),fyyakioi(qp[i]),fyyakioi(qA[i]),fyyakioi(qC[i]); 
	memset(cnt,0,sizeof(cnt)),memset(sum,0,sizeof(sum));
	for(int i=1,id=0; i<=n; ++i) 
	{
		pre[i]=pre[i-1];
		if(f[i])
		{
			++id;
			for(int j=1; j<=qs; ++j) 
			tf[j][id]=qwq[tb[j][id]],
#ifdef local
			(r[j]>=i)&&(qcc[r[j]].push_back((node){j,ta[j][id],cnt[ta[j][id]]}),
			qcc[i].push_back((node){j,ta[j][id],-cnt[ta[j][id]]}),
			Ans[j][1]+=sum[tc[j][id]]
#else
			(r[j]>=i)&&(qc[r[j]].push_back((node){j,ta[j][id],cnt[ta[j][id]]}),
			qc[i].push_back((node){j,ta[j][id],-cnt[ta[j][id]]}),
			ans[j]+=sum[tc[j][id]]
#endif
			);
		}
		else v[i]=cnt[a[i]],++qwq[a[i]],++cnt[B[i]],pre[i]+=sum[C[i]],sum[a[i]]+=v[i];
	}
	for(int i=1; i<=qs; ++i) 
#ifdef local
		Ans[i][0]+=pre[r[i]];
#else
		ans[i]+=pre[r[i]];
#endif
	//Case 4 D D D
	//Case 5 D D S (Queries making)
	//Case 6 S D D (Queries making)
	//Case 7 D S D (Part 1)
	//Case 7 D S D (Part 2 queries making)
	//Case 8 D S S (Queries making)
	for(int i=1; i<=qs; ++i) 
	{
		for(int j=1; pos[j]<=r[i]&&j<=len; ++j) 
			cnt[ta[i][j]]=cnt[tb[i][j]]=0,
			sum[ta[i][j]]=sum[tc[i][j]]=0,
			ntc[tb[i][j]]=ntc[tc[i][j]]=0,
			tnc[tb[i][j]]=tnc[tc[i][j]]=0;
		int R=0;
		for(int j=1; pos[j]<=r[i]&&j<=len; ++j) 
			make_query(i,tb[i][j],pos[j]+1,r[i]),
			R=j,tv[j]=cnt[ta[i][j]],
			(ntc[tc[i][j]])&&(qd[pos[j]].push_back((node){i,tc[i][j],ntc[tc[i][j]]}),0),
			(tv[j])&&(qc[r[i]].push_back((node){i,ta[i][j],tv[j]}),
			qc[pos[j]].push_back((node){i,ta[i][j],-tv[j]}),0),
#ifdef local
			Ans[i][6]-=tnc[tc[i][j]],
			Ans[i][3]+=sum[tc[i][j]],
#else
			ans[i]-=tnc[tc[i][j]],
			ans[i]+=sum[tc[i][j]],
#endif
			tnc[tb[i][j]]+=tf[i][j],
			++cnt[tb[i][j]],++ntc[tb[i][j]],
			sum[ta[i][j]]+=tv[j];
		for(int j=1; j<=R; ++j) cnt[ta[i][j]]=cnt[tc[i][j]]=0;
		for(int j=R; j>=1; --j) 
			(cnt[ta[i][j]])&&(qb[pos[j]-1].push_back((node){i,ta[i][j],cnt[ta[i][j]]}),0),
			++cnt[tc[i][j]];
	}
	//Case 3 S D S (Queries answering)
	//Case 5 D D S (Queries answering)
	//Case 6 S D D (Queries answering)
	//Case 7 D S D (Part 2 queries answering)
	//Case 8 D S S (Queries answering)
	memset(ca,0,sizeof(ca)),memset(cb,0,sizeof(cb)),
	memset(cc,0,sizeof(cc)),memset(cd,0,sizeof(cd));
	memset(sum,0,sizeof(sum));
	for(int i=1; i<=n; ++i)
	{
		(!f[i])&&(sum[C[i]]+=ca[C[i]],++ca[a[i]],++cb[B[i]],++cc[C[i]]);
#ifdef local
		for(auto j:qb[i]) Ans[j.id][5]+=1ll*cb[j.val]*j.mul;
		for(auto j:qc[i]) Ans[j.id][4]+=1ll*cc[j.val]*j.mul;
		for(auto j:qd[i]) Ans[j.id][6]+=1ll*ca[j.val]*j.mul;
		for(auto j:qp[i]) Ans[j.id][7]+=1ll*sum[j.val]*j.mul;
		for(auto j:qcc[i])Ans[j.id][2]+=1ll*cc[j.val]*j.mul;
#else
		for(auto j:qb[i]) ans[j.id]+=1ll*cb[j.val]*j.mul;
		for(auto j:qc[i]) ans[j.id]+=1ll*cc[j.val]*j.mul;
		for(auto j:qd[i]) ans[j.id]+=1ll*ca[j.val]*j.mul;
		for(auto j:qp[i]) ans[j.id]+=1ll*sum[j.val]*j.mul;
#endif
		for(auto j:qA[i]) resA[j.id]+=ca[j.val]*j.mul;
		for(auto j:qC[i]) resC[j.id]+=cc[j.val]*j.mul;
	}
#ifdef local
	for(int i=1; i<=rescnt; ++i) Ans[resid[i]][7]-=1ll*resA[i]*resC[i];
#else
	for(int i=1; i<=rescnt; ++i) ans[resid[i]]-=1ll*resA[i]*resC[i];
#endif
	//Update & output
	for(int i=1; i<=k; ++i) (op[i]==1)&&(a[x[i]]=y[i],B[x[i]]=b[y[i]],C[x[i]]=c[y[i]]);
#ifdef local
	for(int i=1; i<=qs; ++i,puts("")) 
	for(int j=0; j<8; ++j) printf("%lld ",Ans[i][j]);
#else
	for(int i=1; i<=qs; ++i) printf("%lld\n",ans[i]);
#endif
	return ;
}
signed main()
{
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int i=1; i<=n; ++i) b[i]=read();
	for(int i=1; i<=n; ++i) c[i]=read();
	for(int i=1; i<=n; ++i) B[i]=b[a[i]],C[i]=c[a[i]];
	for(int i=1; i<=m; ++i) op[++k]=read(),x[k]=read(),(op[k]==1)&&(y[k]=read()),(k==S)&&(solve(),k=0);
	if(k) solve();
	return 0;
}