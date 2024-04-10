// Problem: CF1097E Egor and an RPG game
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1097E
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=1e5+10;
#define mp make_pair
typedef pair<int,int> pii;
#define lowbit(x) ((x)&-(x))
#define chkmx(a,b) (a)=max((a),(b))
#define fi first
#define se second
int T,n;
class BIT{
	private:
	pii tree[N];//,
	public:
	void init(int x){
		for(;x<=n;x+=lowbit(x))
			tree[x]={0,0};
	}
	void upd(int x,pii val){
		for(;x<=n;x+=lowbit(x))
			chkmx(tree[x],val);
	}
	pii qry(int x){
		pii res(0,0);
		for(;x;x-=lowbit(x))
			chkmx(res,tree[x]);
		return res;
	}
}Tree;
int a[N];bool yang[N];
vector<int>LIS(){
	static int from[N];
	for(int i=1;i<=n;i++){
		if(yang[a[i]])continue;
		pii res=Tree.qry(a[i]);
		int val=res.fi+1;
		from[i]=res.se;
		Tree.upd(a[i],{val,i});
	}
	pii res=Tree.qry(n);
	int now=res.se;vector<int>ans;
	while(now){
		ans.push_back(a[now]);
		now=from[now];
	}reverse(ans.begin(),ans.end());
	for(int i=1;i<=n;i++)Tree.init(a[i]);
	return ans;
}
vector<vector<int>>MDS(){
	vector<vector<int>>ans;
	for(int i=1;i<=n;i++){
		if(yang[a[i]])continue;
		if(!ans.size()||ans.back().back()<a[i])
			ans.push_back(vector<int>(1,a[i]));
		else{
			for(auto&x:ans)
				if(x.back()>a[i]){
					x.push_back(a[i]);
					break;
				}
		}
	}return ans;
}
void solve(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),yang[a[i]]=0;
	int k=0;
	while(k*(k+1)/2<=n)k++;k--;
	int rest=n;vector<vector<int>>ans;
	while(rest){
		vector<int>lis=LIS();
		if(lis.size()>k){
			ans.push_back(lis);
			for(auto x:lis)yang[x]=1;
			k--;rest-=lis.size();
		}else{
			auto ans2=MDS();
			for(auto x:ans2)ans.push_back(x);
			break;
		}
	}
	write(ans.size());putchar('\n');
	for(auto x:ans){
		write(x.size());putchar(' ');
		for(auto y:x)write(y),putchar(' ');
		putchar('\n');
	}
}
signed main(){
	read(T);while(T--)solve();
}