#include<bits/stdc++.h>
#define int long long
const int N=500050,mod=998244353;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,x,y;
}e[N];int hd[N],S;
void add(int fr,int to,int x,int y){
    e[++S]=(edge){to,hd[fr],x,y},hd[fr]=S;
}

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

vector<int> dec(int p){
	vector<int> res;
	for(int i=2;i*i<=p;i++){
		while(p%i==0)
			res.push_back(i),p/=i;
	}
	if(p>1)res.push_back(p);
	return res;
}

int n;
map<int,int> s[N];
int res=0;

void dfs(int k,int fa){
	fore(k)if(_to!=fa){
		dfs(_to,k);
		auto x=dec(e[i].x),y=dec(e[i].y);
		for(auto j:x)s[_to][j]++;
		for(auto j:y)
			if(s[_to][j])
				s[_to][j]--;
		if(s[_to].size()>s[k].size())
			swap(s[k],s[_to]);
		for(auto j:s[_to]){
			int id=j.first,val=j.second;
			s[k][id]=max(s[k][id],val);
		}
	}
//	cout<<endl<<endl;
//	cout<<k<<endl;
//	for(auto x:s[k]){
//		cout<<x.first<<" "<<x.second<<endl;
//	}
}

void df5(int k,int fa,int nv){
	res+=nv;
	fore(k)if(_to!=fa)
		df5(_to,k,nv*e[i].y%mod*inv(e[i].x)%mod);

}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		hd[i]=0;
		s[i].clear();
	}
	S=0;
	res=0;
	for(int i=1;i<n;i++){
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		int p=__gcd(a,b);
		a/=p,b/=p;
		add(x,y,a,b);
		add(y,x,b,a);
	}
	dfs(1,0);
	int rt=1;
	for(auto x:s[1])
		rt=rt*gsc(x.first,x.second)%mod;
	df5(1,0,rt);
	cout<<res%mod<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}