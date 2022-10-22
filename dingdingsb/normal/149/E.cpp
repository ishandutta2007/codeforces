#include<bits/stdc++.h>
#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
template<const int N>
struct String{
	//string buxing
	int n;
	/**/
	char s[N];int x[100100],y[100100],c[100100],sa[N];
	bool cmp(int a,int b,int c){return y[a]==y[b]&&y[a+c]==y[b+c];}
	void SA(int m='Z'){
		for(int i=0;i<=m;i++)c[i]=0;
		for(int i=1;i<=n;i++)c[x[i]=s[i]]++;
		for(int i=1;i<=m;i++)c[i]+=c[i-1];
		for(int i=n;i>=1;i--)sa[c[x[i]]--]=i;
		for(int k=1;k<=n;k<<=1){
			int num=0;
			for(int i=0;i<=m;i++)c[i]=0;
			for(int i=n-k+1;i<=n;i++)y[++num]=i;
			for(int i=1;i<=n;i++)if(sa[i]>k)y[++num]=sa[i]-k;
			for(int i=1;i<=n;i++)c[x[i]]++;
			for(int i=1;i<=m;i++)c[i]+=c[i-1];
			for(int i=n;i>=1;i--)sa[c[x[y[i]]]--]=y[i],y[i]=0;
			swap(x,y);num=1;x[sa[1]]=1;
			for(int i=2;i<=n;i++){
				if(cmp(sa[i],sa[i-1],k))x[sa[i]]=num;
				else x[sa[i]]=++num;
			}
			if(num==n)break;m=num;
		}
	}
	/*HASH*/
	const int mod=998244353,base=107;
	int power[100100],val[N];
	void HASH(){
		power[0]=1;for(int i=1;i<=n;i++)power[i]=1ll*power[i-1]*base%mod;
		val[0]=0;for(int i=1;i<=n;i++)val[i]=(1ll*val[i-1]*base+s[i])%mod;
	}
	int get(int l,int r){
		long long V=val[r]-1ll*val[l-1]*power[r-l+1];
		return (V%mod+mod)%mod;
	}
	/**/
	void read(){scanf("%s",s+1);n=strlen(s+1);}
	void print(){printf("%s\n",s+1);}
	/**/
	void reverse(String<N> &b){
		b.n=n;
		for(int i=1;i<=n;i++)
			b.s[i]=s[n-i+1];
	}
};
template<const int N,const int M>
struct ST{
	int cmp(int a,int b){return a>b?b:a;}
	int dp[M][N];
	int &operator[](int x){return dp[0][x];}
    void init(int n){
        for(int j=1;(1<<j)<=n;j++)
            for(int i=1;i+(1<<j)-1<=n;i++)
                dp[j][i]=cmp(dp[j-1][i],dp[j-1][i+(1<<j-1)]);
    }
    int query(int st,int ed){
        int j=log(ed-st+1)/log(2);
        return cmp(dp[j][st],dp[j][ed-(1<<j)+1]);
    }
};
template<class A,class B>
bool Strcmp(A &S1,int st1,B &S2,int st2,int len,int get2=-1){
	if(len==0)return true;
	if(S1.n<st1+len-1)return false;
	if(S2.n<st2+len-1)return false;
	if(get2==-1)
		return S1.get(st1,st1+len-1)==S2.get(st2,st2+len-1);
	else return S1.get(st1,st1+len-1)==get2;
}
ST<100100,18>ST1,ST2;
String<100100>S1,S2;
String<1005>P1,P2;
int m,ans=0;
int pre[1005],suf[1005];
signed main(){
	//freopen("aaa","r",stdin);
	S1.read();S1.SA();S1.HASH();
	S1.reverse(S2);S2.SA();S2.HASH();
	for(int i=1;i<=S1.n;i++)ST1[i]=S1.sa[i];
	for(int i=1;i<=S2.n;i++)ST2[i]=S2.sa[i];
	ST1.init(S1.n);ST2.init(S2.n);
	scanf("%d",&m);
	while(m--){
		P1.read();P1.HASH();
		P1.reverse(P2);P2.HASH();
		auto f=[&](int *arr,String<100100>&S,ST<100100,18>&RMQ,String<1005>&P){
			memset(arr,255,sizeof pre);
			int l=1,r=S.n;
			for(int i=0;i<=P.n;i++){
				int now=P.get(1,i);
				while(l<=r&&!Strcmp(S,S.sa[l],P,1,i,now))l++;
				while(r>=l&&!Strcmp(S,S.sa[r],P,1,i,now))r--;
				if(l>r)break;
				arr[i]=RMQ.query(l,r);
			}
		};
		f(pre,S1,ST1,P1);f(suf,S2,ST2,P2);
		//for(int i=0;i<=P1.n;i++)printf("%d ",pre[i]);puts("");
		//for(int i=0;i<=P1.n;i++)printf("%d ",suf[i]);puts("");
		for(int i=1;i<P1.n;i++)
			if(pre[i]!=-1&&suf[P1.n-i]!=-1)
				if(S1.n+2-pre[i]-suf[P1.n-i]>=P1.n){
					ans++;break;
				}
	}
	printf("%d",ans);
	return 0;
}