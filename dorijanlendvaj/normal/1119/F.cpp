//did i finally find all of the 82973983789435 bugs after 13 years of debugging? time to find out
#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
using ll=long long;
#define pll pair<ll,ll>
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define eb emplace_back
#define all(a) begin(a),end(a)

const int N=300010,MOD=1e9+7;
const char en='\n';
const ll LLINF=1ll<<60;

vl dpc[2],dp[N][2];
int madeg[N];
ll cj,cj2,ns,dok0,dok1;
vector<pii> ch[N];
map<pii,int> cij;

void dfs1(int i,int p=-1)
{
	madeg[i]=ch[i].size();
	for (auto a: ch[i]) if (a.x!=p)
	{
		dfs1(a.x,i);
		madeg[i]=max(madeg[i],madeg[a.x]);
	}
}

ll ge2(int pa,int i)
{
	return ((i<(int)dpc[pa].size())?dpc[pa][i]:0);
	//cout<<pa<<' '<<i<<' '<<dpc[pa][i]<<endl;
	//return dpc[pa][i];
}

ll gec(int pa,int i)
{
	if ((pa==0 && i<=dok0) || (pa==1 && i<=dok1)) return ((i<(int)dpc[pa].size())?dpc[pa][i]:0);
	else if (pa==1) return min(ge2(0,i),ge2(1,i))+cj2;
	else return min(ge2(0,i),ge2(1,i));
}

set<pll> mu;
ll s,ti;
set<pll>::iterator nakzad;

void rep(ll a,ll b)
{
	pll rb={b,ti++};
	mu.insert(rb);
	if (rb<(*nakzad))
	{
		s+=rb.x;
		--nakzad;
		s-=(nakzad->x);
	}
	pll ra=*mu.lower_bound({a,0});
	assert(ra.x==a);
	if (ra>(*nakzad))
	{
		mu.erase(mu.find(ra));
	}
	else
	{
		s+=(nakzad->x);
		++nakzad;
		s-=ra.x;
		mu.erase(mu.find(ra));
	}
}

void mak()
{
	--nakzad;
	s-=(nakzad->x);
}

void dfs(int nod,int p=-1,bool lar=0)
{
	dpc[0].clear();
	dpc[1].clear();
	vector<pii> dj;
	for (auto a: ch[nod]) if (a.x!=p) dj.pb({madeg[a.x],a.x});
	sort(all(dj));
	reverse(all(dj));
	//cout<<nod<<' '<<dj.size()<<en;
	for (int i=1;i<(int)dj.size();++i) dfs(dj[i].y,nod,0);
	if (dj.size()) dfs(dj[0].y,nod,1);
	for (int i=1;i<(int)dj.size();++i) dj[i].x=dp[dj[i].y][1].size();
	if (dj.size()>=2)
	{
		sort(1+all(dj));
		reverse(1+all(dj));
	}
	cj=0;
	for (auto a: ch[nod]) if (a.x==p) cj=a.y;
	int s2=0;
	for (auto a: dj) s2=max(s2,(int)dp[a.y][1].size());
	//1: parent is deleted, 0: it's not
	vl stv0(max((int)dj.size()+1,s2)+1),stv1(max((int)dj.size(),s2)+1);
	vl sus(dj.size()+1);
	for (int i=(int)dj.size()-1;i>=0;--i)
	{
		sus[i]=sus[i+1]+cij[{nod,dj[i].y}];
	}
	stv0[0]=LLINF;
	
	mu.clear();
	for (int j=1;j<(int)dj.size();++j) mu.insert({-cij[{nod,dj[j].y}],ti++});
	mu.insert({min(0ll,gec(0,max((int)dj.size(),s2)+1)-gec(1,max((int)dj.size(),s2)+1)),ti++});
	s=0;
	for (auto z: mu) s+=z.x;
	mu.insert({LLINF,ti++});
	nakzad=mu.end();
	--nakzad;
	
	//cout<<"poc1 "<<nod<<' '<<s2<<endl;
	//for (auto a: dj) cout<<a.x<<' '<<a.y<<' '<<dp[a.y][1].size()<<en;
	//cout<<flush;
	
	for (int i=max((int)dj.size(),s2);i>=0;--i)
	{
		ll re=0;
		if (dj.size())
		{
			rep(min(0ll,gec(0,i+1)-gec(1,i+1)),min(0ll,gec(0,i)-gec(1,i)));
			re+=gec(1,i);
			for (int j=1;j<(int)dj.size();++j)
			{
				vl& u=dp[dj[j].y][1];
				if ((int)u.size()==i+1)
				{
					vl& v=dp[dj[j].y][0];
					assert((int)v.size()>=i+1);
					rep(-cij[{nod,dj[j].y}],min(0ll,v[i]-u[i]));
				}
				else if ((int)u.size()>i+1)
				{
					vl& v=dp[dj[j].y][0];
					assert((int)v.size()>=i+2);
					rep(min(0ll,v[i+1]-u[i+1]),min(0ll,v[i]-u[i]));
				}
				//cout<<i<<' '<<j<<' '<<u.size()<<' '<<re<<en;
				if ((int)u.size()<=i)
				{
					re+=sus[j];
					break;
				}
				re+=u[i];
			}
			if (i<(int)dj.size()) mak();
			/*cout<<re<<' '<<s<<' ';
			for (auto a: mu) cout<<a.x<<' ';
			cout<<en;*/
			re+=s;
		}
		stv1[i]=re+cj;
	}
	mu.clear();
	for (int j=1;j<(int)dj.size();++j) mu.insert({-cij[{nod,dj[j].y}],ti++});
	mu.insert({min(0ll,gec(0,max((int)dj.size()+1,s2)+1)-gec(1,max((int)dj.size()+1,s2)+1)),ti++});
	s=0;
	for (auto z: mu) s+=z.x;
	mu.insert({LLINF,ti++});
	nakzad=mu.end();
	--nakzad;
	//cout<<"poc0 "<<nod<<endl;
	for (int i=max((int)dj.size()+1,s2);i>=1;--i)
	{
		ll re=0;
		if (dj.size())
		{
			rep(min(0ll,gec(0,i+1)-gec(1,i+1)),min(0ll,gec(0,i)-gec(1,i)));
			re+=gec(1,i);
			for (int j=1;j<(int)dj.size();++j)
			{
				vl& u=dp[dj[j].y][1];
				if ((int)u.size()==i+1)
				{
					vl& v=dp[dj[j].y][0];
					rep(-cij[{nod,dj[j].y}],min(0ll,v[i]-u[i]));
				}
				else if ((int)u.size()>i+1)
				{
					vl& v=dp[dj[j].y][0];
					rep(min(0ll,v[i+1]-u[i+1]),min(0ll,v[i]-u[i]));
				}
				//cout<<re<<' '<<u.size()<<' '<<i<<en;
				if ((int)u.size()<=i)
				{
					re+=sus[j];
					break;
				}
				re+=u[i];
			}
			if (i<=(int)dj.size()) mak();
			/*cout<<re<<' '<<s<<' ';
			for (auto a: mu) cout<<a.x<<' ';
			cout<<en;*/
			re+=s;
		}
		stv0[i]=re;
	}
	dok1=max((int)dj.size(),s2);
	dok0=max((int)dj.size()+1,s2);
	if ((int)dpc[1].size()<=dok1) dpc[1].resize(dok1+1);
	if ((int)dpc[0].size()<=dok0) dpc[0].resize(dok0+1);
	//cout<<dok1<<' '<<stv1.size()<<' '<<dpc[1].size()<<' '<<dok0<<' '<<stv0.size()<<' '<<dpc[0].size()<<endl;
	for (int i=0;i<=dok1;++i) dpc[1][i]=stv1[i];
	for (int i=0;i<=dok0;++i) dpc[0][i]=stv0[i];
	//cout<<stv0[0]<<' '<<dok0<<' '<<dpc[0][0]<<' '<<ge2(0,0)<<' '<<dpc[0].size()<<endl;
	cj2=cj;
	if (lar==0)
	{
		for (int i=0;i<(int)dpc[0].size();++i) dp[nod][0].pb(gec(0,i));
		for (int i=0;i<(int)dpc[1].size();++i) dp[nod][1].pb(gec(1,i));
	}
	/*cout<<nod<<en;
	for (int i=0;i<(int)dpc[0].size();++i) cout<<gec(0,i)<<' ';
	cout<<en;
	for (int i=0;i<(int)dpc[1].size();++i) cout<<gec(1,i)<<' ';
	cout<<en;
	cout<<endl;*/
	//sum(dp[i][0]
}

vl minimum_closure_costs(int n, vi U, vi V, vi W) {
	ns=n;
	for (int i=0;i<n-1;++i) ch[U[i]].pb({V[i],W[i]}),ch[V[i]].pb({U[i],W[i]}),cij[{U[i],V[i]}]=W[i],cij[{V[i],U[i]}]=W[i];
	dfs1(0);
	//for (int i=0;i<n;++i) cout<<madeg[i]<<' ';
	//cout<<en;
	dfs(0);
	while ((int)dp[0][1].size()<n) dp[0][1].pb(0);
	return dp[0][1];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin>>tt;
	vi U,V,W;
	for (int i=1;i<tt;++i)
	{
		int a,b,c;
		cin>>a>>b>>c;
		--a;
		--b;
		U.pb(a);
		V.pb(b);
		W.pb(c);
	}
	vl re=minimum_closure_costs(tt,U,V,W);
	for (auto a: re) cout<<a<<' ';
	cout<<en;
}