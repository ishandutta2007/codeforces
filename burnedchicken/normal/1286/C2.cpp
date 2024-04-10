#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
int n,cnt[26],cnt1[26],cnt2[26],ans[105],x,y;
bool visited[105];
char c;
vector<vector<int> > adj[105];
vector<int> vec1;
queue<int> q;

bool comp(string str1, string str2){return str1.size()>str2.size();}
void solve(int l, int r){
	cout << "? " << l << ' ' << r << endl;
	l--,r--;
	int range=r-l+1;
	int size=range*(range+1)/2;
	string str[size];
	rep(size) cin >> str[i];
	sort(str,str+size,comp);
	rep(26) cnt[i]=cnt1[i]=cnt2[i]=0;
	rep(str[0].size()) cnt[str[0][i]-'a']++,cnt2[str[0][i]-'a']++;
	rep2(i,1,range/2+1){
		vec1.clear();
		x=l+i-1,y=r-i+1;
		vec1.pb(y);
		rep1(j,26) cnt[j]+=cnt2[j];
		rep1(j,26) cnt1[j]=0;
		rep2(j,i*(i+1)/2,(i+1)*(i+2)/2) rep1(k,str[j].size()) cnt1[str[j][k]-'a']++; 
		rep1(j,26){
			if(cnt[j]==cnt1[j]+2){
				vec1.pb(j),vec1.pb(j);
				cnt2[j]-=2;
				cnt[j]-=2;
			}
			if(cnt[j]==cnt1[j]+1){
				vec1.pb(j);
				cnt2[j]--;
				cnt[j]--;
			}
		}
		adj[x].pb(vec1);
		vec1[0]=x;
		adj[y].pb(vec1);
	}
	if(range%2){
		vec1.clear();
		vec1.pb(l+range/2);
		rep(26){
			if(cnt2[i]){
				vec1.pb(i),vec1.pb(i);
				adj[l+range/2].pb(vec1);
				break;
			}
		}
	}
	return;
}
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	cin >> n;
	if(n==1){
		cout << "? 1 1" << endl;
		cin >> c;
		cout << "! " << c << endl;
		return 0;
	}
	solve(1,n);
	solve(1,n/2);
	solve(n/2,n);
	x=n/2-1;
	rep(26) cnt[i]=0;
	rep(n) visited[i]=false;
	rep(adj[x].size()){
		vec1=adj[x][i];
		if(vec1[0]==0||vec1[0]==n-1) cnt[vec1[1]]++,cnt[vec1[2]]++;
	}
	rep(adj[0].size()){
		vec1=adj[0][i];
		if(vec1[0]==n-1) cnt[vec1[1]]--,cnt[vec1[2]]--;
	}
	rep(26){
		if(cnt[i]){
			ans[x]=i;
			q.push(x);
			visited[x]=true;
			break;
		}
	}
	rep(n){
		rep1(j,adj[i].size()){
			vec1=adj[i][j];
			if(vec1[0]==i){
				ans[i]=vec1[1];
				q.push(i);
				visited[i]=true;
				break;
			}
		}
	}
	while(!q.empty()){
		x=q.front();
		rep(adj[x].size()){
			vec1=adj[x][i];
			if(visited[vec1[0]]) continue;
			ans[vec1[0]]=(ans[x]==vec1[1]?vec1[2]:vec1[1]);
			q.push(vec1[0]);
			visited[vec1[0]]=true;
		}
		q.pop();
	}
	cout << "! ";
	rep(n) cout << char(ans[i]+'a');
	cout << endl;
	return 0;
}