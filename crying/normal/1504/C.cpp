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
const int MAXN=2e5+10;
int t,n,sum1,sum2,cnt1,cnt2,tot,flag;
char s1[MAXN],s2[MAXN],s[MAXN];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>s+1;
		if(n&1){printf("NO\n");continue;}
		if(s[1]=='0' || s[n]=='0'){printf("NO\n");continue;}
		sum1=0,sum2=0,cnt1=0,cnt2=0,tot=0;
		rep(i,1,n){
			if(s[i]=='1'){
				cnt1++;
			}else{
				cnt2++;
			}
		}
		if(cnt1&1){printf("NO\n");continue;}
		rep(i,1,n){
			if(s[i]=='1'){
				tot++;
				if(tot<=cnt1/2){
					s1[i]=s2[i]='(';
				}else{
					s1[i]=s2[i]=')';
				}
			} 
		}
		int sum1=0,sum2=0;flag=1;
		rep(i,1,n){
			if(s[i]=='1'){
				if(s1[i]=='(')sum1++,sum2++;
				else sum1--,sum2--;
			}else{
				if(sum1>=sum2){
					s1[i]=')',s2[i]='(';
					sum1--;sum2++;
				}else{
					s1[i]='(',s2[i]=')';
					sum1++;sum2--;
				}
			}
			if(sum1<0 || sum2<0){
				flag=0;
				printf("NO\n");break;
			}
		}
		if(!flag)continue;
		s1[n+1]=s2[n+1]='\0';
		if(sum1 == 0 && sum2==0){
			printf("YES\n");
			printf("%s\n%s\n",s1+1,s2+1);
		}else printf("NO\n");
	}

	return 0;
}