#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
using namespace std;
 
typedef long long ll;
typedef double db;
typedef long double ldb;
 
template<class T> inline void checkmin(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,const T &b){if(b>a) a=b;}
 
const int inf=1e9+10;
const int maxn=5e5+10;
 
int tree[maxn*4];
map<int,int> Map;
int n,a[maxn][3];
multiset <int> s[maxn];
 
void update(int x,int l,int r,int pos,int val){
	if(l==r){
		tree[x]=val;
		return;
	}
	int mid=(l+r)>>1;
	if(pos<=mid) update(x<<1,l,mid,pos,val);
	else update(x<<1|1,mid+1,r,pos,val);
	tree[x]=max(tree[x<<1],tree[x<<1|1]);
}
 
int getval(int x,int l,int r,int cl,int cr){
	if(r<cl||l>cr) return 0ll;
	if(cl<=l&&r<=cr) return tree[x];
	int mid=(l+r)>>1;
	int v1=getval(x<<1,l,mid,cl,cr);
	int v2=getval(x<<1|1,mid+1,r,cl,cr);
	return max(v1,v2);
}
 
int main(){
	for(int i=0;i<maxn*4;i++) tree[i]=0;
	scanf("%d",&n);
	for(int i=0;i<3;i++) for(int j=0;j<n;j++) scanf("%d",&a[j][i]);
	for(int i=0;i<n;i++) Map[a[i][1]]=1;
	int cnt=0;
	for(map<int,int>::iterator it=Map.begin();it!=Map.end();it++){
		it->snd=cnt++;
	}
	vector <pair<int,int> > v;
	for(int i=0;i<n;i++) v.pb(mp(a[i][0],i));
	sort(v.begin(),v.end());
	for(int i=0;i<n;i++){
		s[Map[a[i][1]]].insert(-a[i][2]);
	//	cout<<Map[a[i][1]]<<" "<<-*s[Map[a[i][1]]].begin()<<endl;
		update(1,0,cnt-1,Map[a[i][1]],-(*s[Map[a[i][1]]].begin()));
	}
//	cout<<getval(1,0,n-1,2,2)<<endl;
	int ans=0;
	for(int i=0;i<n;i++){
		vector <int> g;
		for(int j=i;j<n;j++){
			if(v[j].fst==v[i].fst) g.pb(v[j].snd);
			else break;
		}
		for(int j=0;j<g.size();j++){
			int idx=g[j];
			s[Map[a[idx][1]]].erase(s[Map[a[idx][1]]].find(-a[idx][2]));
			int upd;
			if(s[Map[a[idx][1]]].empty()) upd=0;
			else upd=-(*s[Map[a[idx][1]]].begin());
		//	cout<<Map[a[idx][1]]<<" "<<upd<<endl;
			update(1,0,cnt-1,Map[a[idx][1]],upd);
		}
	//	cout<<endl;
		for(int j=0;j<g.size();j++){
			int idx=g[j];
			int val=getval(1,0,cnt-1,Map[a[idx][1]]+1,cnt-1);
		//	cout<<Map[a[idx][1]]+1<<" "<<n-1<<endl;
		//	cout<<val<<endl;
			if(val>a[idx][2]) ans++; 
		}
		i+=(int)g.size()-1;
	}
	printf("%d\n",ans);
	return 0;
}