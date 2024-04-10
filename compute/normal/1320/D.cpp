#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0)
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r) { //[l, r]
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}
using uint=unsigned;
using ull=unsigned long long;
 
struct modinfo{uint mod,root;};
template<modinfo const&ref>
struct modular{
	static constexpr uint const &mod=ref.mod;
	static modular root(){return modular(ref.root);}
	uint v;
	//modular(initializer_list<uint>ls):v(*ls.bg){}
	modular(ll vv=0){s(vv%mod+mod);}
	modular& s(uint vv){
		v=vv<mod?vv:vv-mod;
		return *this;
	}
	modular operator-()const{return modular()-*this;}
	modular& operator+=(const modular&rhs){return s(v+rhs.v);}
	modular&operator-=(const modular&rhs){return s(v+mod-rhs.v);}
	modular&operator*=(const modular&rhs){
		v=ull(v)*rhs.v%mod;
		return *this;
	}
	modular&operator/=(const modular&rhs){return *this*=rhs.inv();}
	modular operator+(const modular&rhs)const{return modular(*this)+=rhs;}
	modular operator-(const modular&rhs)const{return modular(*this)-=rhs;}
	modular operator*(const modular&rhs)const{return modular(*this)*=rhs;}
	modular operator/(const modular&rhs)const{return modular(*this)/=rhs;}
	modular pow(int n)const{
		modular res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}
	modular inv()const{return pow(mod-2);}
	/*modular inv()const{
		int x,y;
		int g=extgcd(v,mod,x,y);
		assert(g==1);
		if(x<0)x+=mod;
		return modular(x);
	}*/
	friend modular operator+(int x,const modular&y){
		return modular(x)+y;
	}
	friend modular operator-(int x,const modular&y){
		return modular(x)-y;
	}
	friend modular operator*(int x,const modular&y){
		return modular(x)*y;
	}
	friend modular operator/(int x,const modular&y){
		return modular(x)/y;
	}
	friend ostream& operator<<(ostream&os,const modular&m){
		return os<<m.v;
	}
	friend istream& operator>>(istream&is,modular&m){
		ll x;is>>x;
		m=modular(x);
		return is;
	}
	bool operator<(const modular&r)const{return v<r.v;}
	bool operator==(const modular&r)const{return v==r.v;}
	bool operator!=(const modular&r)const{return v!=r.v;}
	explicit operator bool()const{
		return v;
	}
};
 
//extern constexpr modinfo base{998244353,3};
extern constexpr modinfo base{1000000007,0};
using mint=modular<base>;
//ABC135F
//Yukicoder No.263
namespace rhash{
	const int k=4;
	vc<array<mint,k>> a,b;
	void init(int n){
		a.resize(n+1);
		b.resize(n+1);
        for(int i=0;i<k;i++){
			a[0][i]=1;
			a[1][i]=rand_int(1,mint::mod-1);
			b[0][i]=1;
			b[1][i]=a[1][i].inv();
		}
        for(int i=1;i<n;i++)
            for(int j=0;j<k;j++){
				a[i+1][j]=a[i][j]*a[1][j];
				b[i+1][j]=b[i][j]*b[1][j];
			}
	}
	using P=pair<array<mint,k>,int>;
	P mrg(P x,P y){
        for(int i=0;i<k;i++)
			x.first[i]+=y.first[i]*a[x.second][i];
		x.second+=y.second;
		return x;
	}
	struct gen{
		gen(){}
		vc<array<mint,k>> c;
		template<class S>
		gen(S s):c(s.size()+1){
            for(int i=0;i<s.size();i++)
                for(int j=0;j<k;j++)
					c[i+1][j]=c[i][j]+a[i][j]*s[i];
		}
		P get(int l,int r){
			P res;
            for(int i=0;i<k;i++)
				res.first[i]=(c[r][i]-c[l][i])*b[l][i];
			res.second=r-l;
			return res;
		}
	};
};
int n;
string t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    rhash::init(n);
    cin>>t;
    vi pos;
    for(int i=0;i<n;i++)
    {
        if(t[i]=='0')
            pos.push_back(i);
    }
    vi x[2];
    for(auto u:pos)
    {
        for(int i=0;i<2;i++)
            x[i].push_back(i^(u&1));
    }
    rhash::gen y[2];
    for(int i=0;i<2;i++) y[i]=rhash::gen(x[i]);
    auto get=[&](int l,int r)->rhash::P{
        int tp=l&1;
        l=lower_bound(pos.begin(),pos.end(),l)-pos.begin();
        r=upper_bound(pos.begin(),pos.end(),r)-pos.begin()-1;
        //dbg(l,r,tp);
        if(l>r||l==pos.size()) return {};
        return y[tp].get(l,r+1);
    };
    int q;
    cin>>q;
    while(q--)
    {
        int l1,l2,len;
        cin>>l1>>l2>>len;
        l1--,l2--;
        if(get(l1,l1+len-1)==get(l2,l2+len-1)) cout<<"Yes\n";
        else cout<<"No\n";
    }

}