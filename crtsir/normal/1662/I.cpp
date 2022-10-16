#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
#define PIL pair<int, ll>
#define PLI pair<ll, int>
#define PLL pair<ll, ll>
#define PDD pair<double, double>
#define STR string
#define MP make_pair
#define Fst first
#define Snd second
using namespace std;
int n,m;
int a[200010],cnt[200010],loc[200010];
vector< pair<PII,int> > v;
map<int,int> mp; 
int tc=0;
ll seg[10000010],mrk[10000010];
inline void pushd(int t,int l,int r)
{
	if (l==r || !mrk[t]) return;
	seg[t*2]+=mrk[t],mrk[t*2]+=mrk[t]; 
	seg[t*2+1]+=mrk[t],mrk[t*2+1]+=mrk[t]; 
	seg[t]=max(seg[t*2],seg[t*2+1]),mrk[t]=0;
}
void add(int t,int l,int r,int li,int ri,int val)
{
	if (r<li || ri<l) return;
	pushd(t,l,r);
	if (li<=l && r<=ri)
	{
		seg[t]+=val,mrk[t]+=val;
		return;
	}
	int mid=(l+r)>>1;
	add(t*2,l,mid,li,ri,val),add(t*2+1,mid+1,r,li,ri,val);
	seg[t]=max(seg[t*2],seg[t*2+1]);
}
ll maxi(int t,int l,int r,int li,int ri)
{
	if (r<li || ri<l) return -1e18;
	pushd(t,l,r); 
	if (li<=l && r<=ri) return seg[t];
	int mid=(l+r)>>1;
	return max(maxi(t*2,l,mid,li,ri),maxi(t*2+1,mid+1,r,li,ri));
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf("%d",&cnt[i]);
	for (int i=0;i<m;i++) scanf("%d",&loc[i]);
	a[0]=0;
	for (int i=0;i<n-1;i++) a[i+1]=a[i]+100;
	sort(loc,loc+m);
	for (int i=0;i<n;i++)
	{
		int it=lower_bound(loc,loc+m,a[i])-loc,jt=it-1;
		int mn=1e9;
		if (it<m) mn=min(mn,abs(loc[it]-a[i]));
		if (jt>=0) mn=min(mn,abs(loc[jt]-a[i]));
		if (mn)
		{
			v.push_back(MP(MP(a[i]-mn,a[i]+mn),cnt[i]));
			mp[a[i]-mn]=-1,mp[a[i]+mn]=-1;
		}
	}
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) tc+=2,it->Snd=tc;
	for (int i=0;i<v.size();i++) add(1,0,tc+100,mp[v[i].Fst.Fst]+1,mp[v[i].Fst.Snd]-1,v[i].Snd);
	printf("%I64d",maxi(1,0,tc+100,0,tc+100));
	return 0;
}