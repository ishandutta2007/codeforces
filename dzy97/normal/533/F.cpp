#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mo=1e9+7;
int pow(int a,int b,int c){int ret=1;for(;b;b>>=1,a=1LL*a*a%c)if(b&1)ret=1LL*ret*a%c;return ret;}
const int N=2e5+10;
int n,m;
char s[N],t[N];
typedef unsigned long long ull;
const ull P=1000000007ULL;
ull p[N];
ull cnt[26],K[26];
vector<int> A;
#define MO 5233
int h[MO],ee,n1[MO],used[MO],vt=1;
ull V[MO];

int ask(int c){
	int v=cnt[c]%MO;
	for(int i=h[v];~i;i=n1[i])if(V[i]==cnt[c]&&cnt[i]==V[c]){
		if(used[i]!=vt){
			used[i]=vt;
			return 1;
		}
	}return 0;
}void add(ull k){
	int v=k%MO;
	V[ee]=k;n1[ee]=h[v];h[v]=ee++;
}
int main(){
//	freopen("data.in", "r", stdin);
	scanf("%d%d",&n,&m);
	scanf("%s%s",s+1,t+1);
	p[0]=1;for(int i=1;i<=n;i++)p[i]=p[i-1]*P;
	memset(h,-1,sizeof(h));
	for(int c=0;c<26;c++){
		ull ha=0;
		for(int i=m;i;i--) ha=ha*P+(t[i]-'a'==c);
		K[c]=ha;
		add(K[c]);
		for(int i=n;i>n-m+1;i--) cnt[c]=cnt[c]*P+(s[i]-'a'==c);
	}
	for(int i=n-m+1;i;i--,vt++){
		for(int c=0;c<26;c++) cnt[c]*=P;
		cnt[s[i]-'a']++;
		int ok=1;
		for(int c=0;c<26;c++)if(!ask(c))ok=0;
		cnt[s[i+m-1]-'a']-=p[m-1];
		if(ok) A.push_back(i);
	}
	sort(A.begin(),A.end());
	printf("%d\n", (int)A.size());
	for(int i=0;i<A.size();i++)printf("%d ",A[i]);
	return 0;
}