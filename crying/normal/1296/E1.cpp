#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=210;
char s[MAXN];
int n,arr[MAXN],color[MAXN];
int main(){
	scanf("%d%s",&n,s+1);
	rep(i,1,n)arr[i]=i,color[i]=2;
	rep(i,1,n){
		int pos=i;
		rep(j,i+1,n){
			if(s[arr[j]]<s[arr[pos]])pos=j;
		}
		//arr[pos] 
		int flag0=1,flag1=1;
		rep(j,i,pos-1){
			if(color[arr[j]]==0)flag0=0;
			else if(color[arr[j]]==1)flag1=0;
		}
		if(!flag0 && !flag1){printf("NO");return 0;}
		if(color[arr[pos]]!=2){
			if(color[arr[pos]] && !flag1){printf("NO");return 0;}
			else if(!flag0){printf("NO");return 0;}
			rep(j,i,pos-1)color[arr[j]]=!color[arr[pos]];
			int tmp=arr[pos];
			per(j,pos,i+1)arr[j]=arr[j-1];
			arr[i]=tmp;
		//	rep(j,1,n)printf("%d ",arr[j]);printf("\n");
		//	rep(j,1,n)printf("%d ",color[arr[j]]);printf("\n");
		//	printf("\n");
			continue;
		}
		else if(flag0){color[arr[pos]]=0;}else{color[arr[pos]]=1;}
		rep(j,i,pos-1){
			color[arr[j]]=!color[arr[pos]];
		}
		int tmp=arr[pos];
		per(j,pos,i+1)arr[j]=arr[j-1];
		arr[i]=tmp;
	//	rep(j,1,n)printf("%d ",arr[j]);printf("\n");
	//	rep(j,1,n)printf("%d ",color[arr[j]]);printf("\n");
	//	printf("\n");
	}
	printf("YES\n");
	rep(j,1,n)printf("%d",color[j]);
	return 0;
}