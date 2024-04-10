#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define mp make_pair
#define pb push_back
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

const int N=2005;
int a[N],R[N],n,pos,ans;
unordered_map<int,int> las;

int main(){
	read(n);
	rep(i,1,n)read(a[i]);
	int flag=0;
	per(i,n,1)
		if(las.count(a[i])){
			R[i]=las[a[i]];
			flag=1;
		}
		else{
			las[a[i]]=i;
			if(!flag)pos=i;
		}
	ans=pos-1;
	las.clear();
	rep(i,1,n){
		if(R[i])pos=max(pos,R[i]+1);
		if(las.count(a[i]))break;
		//printf("%d %d\n",i,pos);
		ans=min(ans,pos-i-1);
		las[a[i]]=i;
	}
	printf("%d\n",max(0,ans));
	return 0;
}