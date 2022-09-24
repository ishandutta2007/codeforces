/*
ID: dorijan1
TASK: tu napisi ime zadatka molim te molim te ali samo ako si na usaco training
LANG: C++11
*/
#include <bits/stdc++.h>
#define x first
#define y second
#define pii pair<int,int>

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
const int MOD=1000000007;
const int MOD2=998244353;
vector<int> bases;
const ll LLINF=1ll<<60;
const char en='\n';

void yes() {cout<<"YES"<<en; exit(0);}
void no() {cout<<"NO"<<en; exit(0);}
template<class T>
void prVec(vector<T> w)
{
	cout<<w.size()<<endl;
	for (int i=0;i<int(w.size())-1;++i) cout<<w[i]<<' ';
	cout<<w[w.size()-1]<<endl;
}

ll raand()
{
	ll a=rand();
	a*=RAND_MAX;
	a+=rand();
    return a%(MOD-7);
}

string to_upper(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
	return a;
}

string to_lower(string a)
{
	for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
	return a;
}

ll sti(string a)
{
	ll k=0;
	for (int i=0;i<(int)a.size();++i)
	{
		k*=10;
		k+=a[i]-'0';
	}
	return k;
}

string its(ll k)
{
	if (k==0) return "0";
	string a;
	while (k)
	{
		a.push_back((k%10)+'0');
		k/=10;
	}
	reverse(a.begin(),a.end());
	return a;
}

ll gcd(ll a,ll b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

template<class T,class K>
pair<T,K> mp(T a,K b)
{
	return make_pair(a,b);
}

ll mult(ll a,ll b)
{
	return (a*b)%MOD;
}

ll pot(ll n,ll k)
{
	if (k==0) return 1;
	ll a=pot(n,k/2);
	a=mult(a,a);
	if (k%2) return mult(a,n);
	else return a;
}

ll divide(ll a,ll b)
{
	return mult(a,pot(b,MOD-2));
}

ll sub(ll a,ll b)
{
	return (a-b+MOD)%MOD;
}

ll add(ll a,ll b)
{
	return (a+b)%MOD;
}

bool prime(ll a)
{
	if (a==1) return 0;
	for (int i=2;i<=round(sqrt(a));++i)
	{
		if (a%i==0) return 0;
	}
	return 1;
}

pair<int,int> has(string x)
{
	ll h1=0,h2=0;
	x=to_lower(x);
	for (char a: x)
	{
		h1*=bases[0];
		h1+=a-'a';
		h1%=MOD;
		h2*=bases[1];
		h2+=a-'a';
		h2%=MOD2;
	}
	return make_pair(h1,h2);
}

const int N=300010;
int n,k,re;
string h[N];
unordered_map<string,multiset<int> > m;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
vector<pair<pair<int,int>,bool> > v;

int main()
{
	ios_base::sync_with_stdio(false);
	srand((long long)new char);
	for (int i=0;i<10;++i) bases.push_back(raand()+13893829);
	cin>>k>>n;
	for (int i=0;i<k;++i)
	{
		int a;
		cin>>h[i]>>a;
		m[h[i]].insert(a);
	}
	for (auto a: m)
	{
		string s=a.first;
		auto mu=a.second;
		reverse(s.begin(),s.end());
		if (s==a.first)
		{
			auto it=mu.rbegin();
			if ((*it)<=0) continue;
			if (mu.size()==1)
			{
				v.push_back({{(*it),-(*it)},1});
				continue;
			}
			auto miit=it;
			++miit;
			v.push_back({{(*it),(*miit)},1});
			//cout<<a.first<<endl;
			while (miit!=mu.rend() && (*it)>0)
			{
				++miit;
				++miit;
				++it;
				++it;
				if (it==mu.rend() || miit==mu.rend()) break;
				v.push_back({{(*it),(*miit)},1});
			}
			if (it==mu.rend())
			{
				continue;
			}
			if ((*it)<=0)
			{
				continue;
			}
			if (miit==mu.rend())
			{
				v.push_back({{(*it),-(*it)},1});
				continue;
			}
			if ((*miit)<=0)
			{
				v.push_back({{(*it),(*miit)},1});
				continue;
			}
		}
		else
		{
			auto su=m[s];
			m.erase(s);
			auto it=mu.rbegin(),bi=su.rbegin();
			while (it!=mu.rend() && bi!=su.rend() && ((*it)>0 || (*bi)>0))
			{
				if ((*it)>0 && (*bi)>0)
				{
					re+=(*it);
					re+=(*bi);
					++it;
					++bi;
					continue;
				}
				v.push_back({mp(max(*it,*bi),min(*it,*bi)),0});
				++it;
				++bi;
			}
			/*if (it!=mu.rend() && bi==su.rend())
			{
				v.push_back({*it,-(*it)});
				continue;
			}
			if (it==mu.rend() && bi!=su.rend())
			{
				v.push_back({*bi,-(*bi)});
			}*/
		}
	}
	int mi=0;
	//cout<<re<<endl;
	for (auto a: v)
	{
		re+=max(0,a.x.first+a.x.second);
		if (a.y) mi=min(mi,max(a.x.second,-a.x.x));
		//cout<<a.x.x<<' '<<a.x.y<<endl;
	}
	cout<<re-mi;
}