// Problem: E. Polycarp and String Transformation
// Contest: Codeforces - Codeforces Round #739 (Div. 3)
// URL: https://codeforces.com/contest/1560/problem/E
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
const int N=5e5+100;
int t,n;char str[N];
char turn[N];int tot;
int sum[100];int lst[100];int need[100];
pair<int,int>a[100];bool deleted[100];
int pos,kk;
char now[N*20];int l=0;
bool cmp(char*s1,char*s2,int len){
	for(int i=1;i<=len;i++)
		if(s1[i]!=s2[i])return false;
	return true;
}
signed main(){
	//freopen("1.in","r",stdin);
	read(t);while(t--){
		tot=0;
		memset(lst,0,sizeof lst);
		memset(sum,0,sizeof sum);
		memset(need,0,sizeof need);
		memset(deleted,0,sizeof deleted);
		scanf("%s",str+1);n=strlen(str+1);
		for(int i=1;i<=n;i++)
			sum[str[i]-'a']++,
			lst[str[i]-'a']=i;
		for(int i=0;i<26;i++)if(sum[i])
			a[++tot]=mp(lst[i],i);
		sort(a+1,a+tot+1);
		bool flag=true;
		for(int i=1;i<=tot;i++){
			turn[i]=a[i].second+'a';
			if(sum[a[i].second]%i){
				puts("-1");
				flag=false;
				break;
			}
			need[a[i].second]=sum[a[i].second]/i;
		}
		if(flag){
			pos=0;
			for(int i=0;i<26;i++)
				pos+=need[i];
			l=0;
			for(int i=1;i<=tot;i++){
				for(int j=1;j<=pos;j++)if(!deleted[str[j]-'a'])
					now[++l]=str[j];
				if(l>n)break;
				deleted[a[i].second]=1;
			}
			if(l==n&&cmp(now,str,n)){
				for(int i=1;i<=pos;i++)putchar(str[i]);putchar(' ');
				for(int i=1;i<=tot;i++)putchar(turn[i]);putchar('\n');
			}else puts("-1");
		}
	}
}