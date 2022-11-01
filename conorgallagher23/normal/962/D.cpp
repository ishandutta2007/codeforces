#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=1.5e+5+5;
int n,sq[N],del[N];LL a[N],b[N*20],len;
set<int>s[N*20];vector<LL>ans;
int getid(LL x){return lower_bound(b+1,b+len+1,x)-b;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);LL x=a[i];
		for(int j=1;j<=20;j++)b[++len]=x,x=x*2LL;
	}
	sort(b+1,b+len+1);len=unique(b+1,b+len+1)-b-1;
	for(int i=1;i<=n;i++)s[getid(a[i])].insert(i);
	for(int i=1,l;i<=len;i++){
		l=0;for(auto it=s[i].begin();it!=s[i].end();it++)sq[++l]=*it;
		s[i].clear();
		for(int j=2;j<=l;j+=2)del[sq[j-1]]=true,a[sq[j]]=a[sq[j]]*2LL,s[getid(a[sq[j]])].insert(sq[j]);
	}
	for(int i=1;i<=n;i++)if(!del[i])ans.pb(a[i]);
	printf("%d\n",(int)ans.size());
	for(auto x:ans)printf("%lld ",x);puts("");
	return 0;
}