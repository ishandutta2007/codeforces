#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int mod=1e9+7,inf=1e9;
int n,l,r,x,ans=1;
set<int> s;
char op[9];

int main(){
	read(n);
	s.insert(l=0);
	s.insert(r=inf);
	while(n--){
		scanf("%s",op);
		if(op[1]=='D'){
			read(x);
			s.insert(x);
		}
		else{
			read(x);
			if(x<l||r<x){
				puts("0");
				return 0;
			}
			if(x!=l&&x!=r) ans=ans*2%mod;
			auto it=s.find(x);
			l=*prev(it),r=*next(it);
			s.erase(it);
		}
	}
	int cnt=0;
	for(auto it=s.find(l);*it<r;it++) cnt++;
	ans=(ll)ans*cnt%mod;
	cout<<ans<<endl;
	return 0;
}