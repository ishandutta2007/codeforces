#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);++(i))
using namespace std;
int t,n,i,j,cnt[26],sum;
int stk[200005],tp;
char s[200005],ss[200005];
int p[200005],pc;
vector<pair<int,int> > res,ans;
int fndzs(){
	int s=-1,i;
	rep(i,26)if(cnt[i-1]>=sum/2)s=i-1;
	return s;
}
struct bit{
	int s[200005];
	void add(int x,int y){
		while(x<=n+1){
			s[x]+=y;
			x+=(x&-x);
		}
	}
	int query(int x){
		int t=0;
		while(x){
			t+=s[x];
			x-=(x&-x);
		}
		return t;
	}
}b;
void ins(int l,int r){
	int sl=b.query(l),sr=b.query(r);
	ans.push_back(make_pair(sl+1,sr));
	b.add(r,sl-sr);
}
int main(){
	scanf("%d",&t);
	while(t--){
		memset(cnt,0,sizeof(cnt));
		pc=0;res.clear();ans.clear();sum=0;
		scanf("%s",s+1);
		n=strlen(s+1);
		rep(i,n-1){
			if(s[i]==s[i+1]){
				p[++pc]=i;ss[pc]=s[i];
				cnt[s[i]-'a']++;
			}
		}
		rep(i,26) sum+=cnt[i-1];
		tp=0;
		int zs=-1;
		rep(i,pc){
			stk[++tp]=i;
			if(zs==-1) zs=fndzs();
			if(zs==-1){
				if(tp>1&&ss[stk[tp]]!=ss[stk[tp-1]]){
					res.push_back(make_pair(stk[tp-1],stk[tp]));
					cnt[ss[stk[tp]]-'a']--;cnt[ss[stk[tp-1]]-'a']--;
					sum-=2;tp-=2;
				}
			}
			else{
				if(tp>1&&(ss[stk[tp]]==zs+'a')!=(ss[stk[tp-1]]==zs+'a')){
					res.push_back(make_pair(stk[tp-1],stk[tp]));
					cnt[ss[stk[tp]]-'a']--;cnt[ss[stk[tp-1]]-'a']--;
					sum-=2;tp-=2;
				}
			}
		}
		while(tp){
			res.push_back(make_pair(stk[tp],-1));
			tp--;
		}
		rep(i,n+1) b.s[i]=0;
		rep(i,n) b.add(i,1);
		rep(i,res.size()){
			if(res[i-1].second==-1) ins(p[res[i-1].first],n); else ins(p[res[i-1].first],p[res[i-1].second]);
		}
		ins(0,n);
		printf("%d\n",ans.size());
		rep(i,ans.size()){
			printf("%d %d\n",ans[i-1].first,ans[i-1].second);
		}
	}
	return 0;
}