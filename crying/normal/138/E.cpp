#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
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
const int MAXN=1e5+10,MAXM=510;
char s[MAXN];
int k,n,L,R,l[MAXN],r[MAXN],rk[MAXN];
char c[MAXN];
int pos[30][MAXN],len[30];
int cnt[MAXN]; 
ll ans,cur;
bool check(int x){
	return x>=L && x<=R;
}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d%d%d",&k,&L,&R);
	rep(i,1,k){
		scanf(" %c%d%d",&c[i],&l[i],&r[i]);
	}
	rep(i,1,n){
		pos[s[i]-'a'][++len[s[i]-'a']]=i;
		rk[i]=len[s[i]-'a'];
	}
	rep(i,1,n){
		//i-1->i
		cur+=check(0);
		rep(j,1,k){
			if(!l[j] && !r[j]){
				if(s[i]==c[j]){
					rep(x,pos[c[j]-'a'][rk[i]-1]+1,i-1){
						cnt[x]--;
						cur+=(check(cnt[x])-check(cnt[x]+1));
					}
				}else{
				//	if(i==8)printf("HERE %d %d\n",l[j],r[j]);
					cnt[i]++;
					cur+=(check(cnt[i])-check(cnt[i]-1));
				}
				continue;
			}
			if(s[i]!=c[j]){
				if(l[j]==0){
					cnt[i]++;
				//	if(i==8)printf("HERE %d %d\n",l[j],r[j]);
					cur+=(check(cnt[i])-check(cnt[i]-1));
				}
			}else{
			if(rk[i]>=l[j]){
				if(l[j]!=0){
				rep(x,pos[c[j]-'a'][rk[i]-l[j]]+1,pos[c[j]-'a'][rk[i]-l[j]+1]){
					cnt[x]++;
					cur+=(check(cnt[x])-check(cnt[x]-1));
				}
				}else{
					cnt[i]++;
					cur+=(check(cnt[i])-check(cnt[i]-1));
				}
			}
			if(rk[i]>r[j]){
				rep(x,pos[c[j]-'a'][rk[i]-r[j]-1]+1,pos[c[j]-'a'][rk[i]-r[j]]){
					cnt[x]--;
					cur+=(check(cnt[x])-check(cnt[x]+1));
				}
			}
			}
		} 
		ans+=cur;
		/*
		printf("i:%d\n",i);
		rep(j,1,i){
			printf("[%d,%d]:%d\n",j,i,cnt[j]);
		}
		*/
	}
	cout<<ans;
	return 0;
}