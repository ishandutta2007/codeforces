#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
int s1[N],s2[N],a[N],n;
vector<pii> ans;

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		s1[i]=s1[i-1]+(a[i]==1);
		s2[i]=s2[i-1]+(a[i]==2);
	}
	rep(step,1,n){
		int p=1,A=0,B=0,flag=0;
		for(;p<=n;p++){
			int l=p,r=n+1,mid;
			while(l<r){
				mid=(l+r)>>1;
				if(max(s1[mid]-s1[p-1],s2[mid]-s2[p-1])>=step) r=mid;
				else l=mid+1;
			}
			if(r==n+1){
				flag=1;
				break;
			}
			p=l;
			if(a[p]==1) A++;
			else B++;
		}
		if(!flag&&A!=B&&(A>B&&a[n]==1||B>A&&a[n]==2)){
			ans.pb(mp(max(A,B),step));
		}
	}
	cout<<SZ(ans)<<endl;
	sort(ans.begin(),ans.end());
	REP(k,SZ(ans)){
		printf("%d %d\n",ans[k].fi,ans[k].se);
	}
	return 0;
}