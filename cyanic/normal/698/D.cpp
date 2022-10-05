#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define qwq(x) cout<<"# "<<#x<<" = "<<x<<endl;
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

const int N=1005;
struct pt{
	int x,y;
	pt(int _x=0,int _y=0):x(_x),y(_y){}
	friend pt operator - (pt a,pt b){
		return pt(a.x-b.x,a.y-b.y);
	}
	friend ll cro(pt a,pt b){
		return (ll)a.x*b.y-(ll)a.y*b.x;
	}
	friend ll dot(pt a,pt b){
		return (ll)a.x*b.x+(ll)a.y*b.y;
	}
}q[N],p[N];
int P[8],vis[N],m,n,ans,tim;
vi owo[8][N];

bool on(pt a,pt b,pt c){
	if(cro(c-b,a-b))return 0;
	return dot(b-a,c-a)>0&&dot(b-c,a-c)>0;
}

int chk(int &k,int aim){
	if(k>m)return 0;
	for(auto x:owo[P[k]][aim])
		if(vis[x]!=tim){
			++k;
			if(!chk(k,x))
				return 0;
		}
	vis[aim]=tim;
	return 1;
}

int main(){
	read(m),read(n);
	rep(i,1,m){
		read(q[i].x);
		read(q[i].y);
	}
	rep(i,1,n){
		read(p[i].x);
		read(p[i].y);
	}
	rep(i,1,m)rep(j,1,n)
		rep(k,1,n) if(on(q[i],p[k],p[j]))
			owo[i][j].pb(k);
	for(int aim=1;aim<=n;aim++){
		rep(i,1,m) P[i]=i;
		do{
			++tim;
			int now=1;
			if(chk(now,aim)){
				ans++;
				break;
			}
		}
		while(next_permutation(P+1,P+m+1));
	}
	cout<<ans<<endl;
	return 0;
}