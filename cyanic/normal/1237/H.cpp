#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
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

const int N=4005;
int a[N],b[N],n;
char s[N],t[N];
vi ans,ans2;

int suitable(int len){
	int ca=0,cb=0;
	rep(i,1,len) ca+=(a[i]==1),cb+=(b[i]==2);
	return ca==cb;
}
void rever(int p){
	if(p) ans.pb(p*2);
	reverse(a+1,a+p+1);
	rep(i,1,p) if(a[i]==1||a[i]==2) a[i]=3-a[i];
}
void rever2(int p){
	if(p) ans2.pb(p*2);
	reverse(b+1,b+p+1);
	rep(i,1,p) if(b[i]==1||b[i]==2) b[i]=3-b[i];
}

void rmain(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1)/2;
	int cnt[4]={0,0,0,0};
	rep(i,1,n){
		a[i]=(s[i*2-1]-'0')*2+(s[i*2]-'0');
		b[i]=(t[i*2-1]-'0')*2+(t[i*2]-'0');
		cnt[a[i]]++,cnt[b[i]]--;
	}
	if(cnt[0]||cnt[3]){
		puts("-1");
		return;
	}
	ans.clear(),ans2.clear();
	int len=n;
	while(len&&!suitable(len)){
		int cur=1;
		while(cur<=len&&a[cur]!=b[len]) cur++;
		if(cur<=len){
			rever(cur),rever(len);
		}
		else{
			cur=1;
			while(a[len]!=b[cur]) cur++;
			rever2(cur),rever2(len);
		}
		len--;
	}
	rep(i,len+1,n) assert(a[i]==b[i]);
	rep(i,1,len){
		int cur=i;
		while((a[cur]==0||a[cur]==3?a[cur]:3-a[cur])!=b[len+1-i]) cur++;
		rever(cur-1),rever(cur);
	}
	rep(i,1,n) assert(a[i]==b[i]);
	reverse(ans2.begin(),ans2.end());
	printf("%d\n",(int)ans.size()+ans2.size());
	for(auto x:ans) printf("%d ",x);
	for(auto x:ans2) printf("%d ",x);
	puts("");
}

int main(){
	int T; read(T);
	while(T--) rmain();	
	return 0;
}