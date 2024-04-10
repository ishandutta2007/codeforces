#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=100010;
int i,j,k,n,m,T,ans,a[maxn],s[maxn],c[maxn*2],last[maxn*2],lask[maxn],LAST,cnt;
int p[maxn*2],len[maxn*2],dp[maxn],tmp[maxn*2];
set<pii>S[maxn];
set<pii>::iterator IT;
multiset<int>::iterator it;
multiset<int>cr;
void init(){
	sort(c+1,c+1+cnt);
	int len=1;
	for(int i=2;i<=cnt;i++)
		if(c[i]!=c[i-1])c[++len]=c[i];
	cnt=len;
	for(i=1;i<=n;i++)a[i]=lower_bound(c+1,c+1+n,a[i])-c;
	for(i=1;i<=m;i++)s[i]=lower_bound(c+1,c+1+n,s[i])-c;
}
void work(int now,int sum){
	if(sum==1)return;
	//cout<<"work "<<now<<' '<<sum<<' '<<a[now]<<endl;
	IT=S[sum-1].upper_bound(make_pair(a[now],0));
	if(IT==S[sum-1].begin()){
		it=cr.lower_bound(a[now]);
		it--;
		//cout<<"erased "<<now<<' '<<lask[now]<<' '<<a[lask[now]]<<' '<<cr.size()<<endl;
		a[lask[now]]=*it;cr.erase(it);
		for(int j=lask[now];j<now;j++){if(a[j]!=-1)S[dp[j]].erase(make_pair(a[j],j));}
		work(lask[now],sum-1);
	}else{
		//cout<<"op="<<2<<' '<<a[now]<<endl;
		//if(S[1].find(make_pair(2,2))!=S[1].end())cout<<"   OK!"<<endl;else cout<<"  NO!!!!!"<<endl;
		IT--;
		int to=(*IT).second;
		//cout<<"to="<<to<<" w="<<(*IT).first<<endl;
		for(int j=to;j<now;j++){if(a[j]!=-1)S[dp[j]].erase(make_pair(a[j],j));}
		work(to,sum-1);
	}
}
int main(){
	cin>>n;
	for(i=1;i<=n;i++)a[i]=read(),c[++cnt]=a[i];
	cin>>m;
	for(i=1;i<=m;i++)s[i]=read(),c[++cnt]=s[i],cr.insert(s[i]);
//	init();
	sort(s+1,s+1+m);
	memset(len,0x3f,sizeof(len));
	len[0]=0;
	for(i=1;i<=n;i++){
		lask[i]=LAST;
		if(a[i]==-1){
			LAST=i;
			int p1=0;
			memset(tmp,0x3f,sizeof(tmp));
			for(j=1;j<=m;j++){
				while(p1<=n && len[p1+1]<s[j])++p1;
				if(len[p1]<s[j])tmp[p1+1]=min(tmp[p1+1],s[j]);
			}
			for(j=1;j<=n;j++){
				if(len[j]==0x3f3f3f3f && tmp[j]!=len[j])ans=i;
				len[j]=min(len[j],tmp[j]);
			}
		}else{
			int L=0,R=n;
			while(L<=R){
				int Mid=(L+R)>>1;
				if(a[i]>len[Mid])L=Mid+1;
				else R=Mid-1;
			}
			dp[i]=L;
			if(len[L]>a[i]){
				if(len[L]==0x3f3f3f3f)ans=i;
				len[L]=a[i],last[i]=p[L],p[L]=i;
			}
			S[dp[i]].insert(make_pair(a[i],i));
		}
	}
	for(i=n;i>=1;i--)if(len[i]!=0x3f3f3f3f){
		for(j=ans;j<=n;j++)
			if(a[j]!=-1)S[dp[j]].erase(make_pair(a[j],j));
		//cout<<i<<endl;
		if(a[ans]==-1){
			cr.erase(cr.find(s[m]));
			a[ans]=s[m];s[m]=0;
		}
		work(ans,i);
		for(i=1;i<=n;i++){
			//cout<<"i="<<i<<' '<<a[i]<<' '<<cr.size()<<endl;
			if(a[i]==-1)a[i]=*cr.begin(),cr.erase(cr.begin());
		}//cout<<endl;
		for(i=1;i<=n;i++)printf("%d ",a[i]);puts("");
		return 0;
	}
}