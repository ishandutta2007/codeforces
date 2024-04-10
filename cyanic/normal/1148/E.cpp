#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=300005;
struct node{int a,b,c;};
vector<node> ans;
int a[N],s[N],t[N],rk[N],n;
ll pre[N];

inline int cmp(int x,int y){
	return s[x]<s[y];
}

int stk[N],top;

int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&s[i]),rk[i]=i;
	rep(i,1,n)scanf("%d",&t[i]);
	sort(rk+1,rk+n+1,cmp);
	sort(t+1,t+n+1);
	rep(i,1,n){
		pre[i]=pre[i-1]+t[i]-s[rk[i]];
		a[i]=t[i]-s[rk[i]];
		if(pre[i]<0)return puts("NO"),0;
	}
	if(pre[n])return puts("NO"),0;
	rep(i,1,n)
		if(a[i]>0)stk[++top]=i;
		else while(a[i]<0){
			//assert(top);
			int t=min(-a[i],a[stk[top]]);
			//cerr<<i<<" "<<stk[top]<<endl;
			ans.pb((node){rk[stk[top]],rk[i],t});
			a[i]+=t,a[stk[top]]-=t;
			if(!a[stk[top]])top--;
		}
	puts("YES");
	cout<<ans.size()<<endl;
	for(auto x:ans)
		printf("%d %d %d\n",x.a,x.b,x.c);
	return 0;
}