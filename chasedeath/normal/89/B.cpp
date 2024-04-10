#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


//#pragma GCC optimize(2)



const int N=1010,P=998244353;

int n,cnt;
string s;
struct Rec{
	ll x,y;
}R[N];
map <string,int> M;
vector <int> G[N];
int kind[N],setspace[N],setborder[N],ind[N];

template <typename T> void rd(string s,T &x,int &p){
	x=0;
	while(p<(int)s.size() && isdigit(s[p])) x=x*10+s[p++]-'0';
}

int vis[N];
void dfs(int u) {
	if(vis[u]) return;vis[u]=1;
	if(!kind[u]) return;
	if(kind[u]==1) {
		ll ma=0,s=0;
		rep(i,0,G[u].size()-1) {
			int v=G[u][i];
			dfs(v);
			s+=R[v].x;
			if(i) s+=setspace[u];
			ma=max(ma,R[v].y);
		}
		if(G[u].size()) ma+=2*setborder[u],s+=2*setborder[u];
		R[u]=(Rec){s,ma};
	} else {
		ll ma=0,s=0;
		rep(i,0,G[u].size()-1) {
			int v=G[u][i];
			dfs(v);
			s+=R[v].y;
			if(i) s+=setspace[u];
			ma=max(ma,R[v].x);
		}
		if(G[u].size()) ma+=2*setborder[u],s+=2*setborder[u];
		R[u]=(Rec){ma,s};
	}
}




int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	rep(i,1,n) {
		cin>>s;
		if(s=="Widget") {
			cin>>s;
			//string t;
			int j=0;
			while(s[j]!='(') j++;
			//t=s.substr(0,j);
			//cout<<"#  "<<s.substr(0,j)<<' '<<s.substr(0,j-1)<<endl;
			M[s.substr(0,j)]=++cnt;
			j++;
			rd(s,R[cnt].x,j);
			j++;
			rd(s,R[cnt].y,j);
		} else if(s=="HBox") {
			cin>>s;
			kind[M[s]=++cnt]=1;
		} else if(s=="VBox") {
			cin>>s;
			kind[M[s]=++cnt]=2;
		} else {
			int j=0;
			while(s[j]!='.') j++;
			int t=M[s.substr(0,j)];
			if(s[j+1]=='s' && s[j+5]=='b') {
				j+=12;
				rd(s,setborder[t],j);
			} else if(s[j+1]=='s' && s[j+5]=='s') {
				j+=13;
				rd(s,setspace[t],j);
			} else {
				//cout<<"#"<<s<<' '<<s.substr(0,s.size()-1)<<endl;
				//cout<<"#  "<<j+6<<' '<<s.size()<<' '<<s.substr(j+6,s.size()-1)<<endl;
				//cout<<"#  "<<s<<' '<<s.substr(j+6,s.size()-j-7)<<endl;
				int num=M[s.substr(j+6,s.size()-j-7)];
				//cout<<s.substr(j+6,s.size()-j-7)<<' '<<num<<endl;
				ind[num]++;
				G[t].push_back(num);
			}
		}	
	}
	for(map <string,int> ::iterator it=M.begin();it!=M.end();++it) {
		int t=it->second;
		if(!ind[t]) dfs(t);
	}
	for(map <string,int> ::iterator it=M.begin();it!=M.end();++it) cout<<it->first<<' '<<R[it->second].x<<' '<<R[it->second].y<<endl;
}