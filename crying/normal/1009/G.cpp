#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int MAXN=2e5+10,MAXM=1<<6;
int n,m,s[MAXN];
int cnt[MAXM],state[MAXN],g[MAXM][MAXN];
char str[MAXN],ans[MAXN],tmp[MAXM];
int main(){
	scanf("%s",str+1);n=strlen(str+1);
	rep(i,1,n){
		s[i]=str[i]-'a';
		state[i]=(1<<6)-1;
	}
	scanf("%d",&m);
	rep(i,1,m){
		int k,len;
		scanf("%d%s",&k,tmp+1);
		len=strlen(tmp+1);
		state[k]=0;
		rep(j,1,len){
			state[k]|=1<<(tmp[j]-'a');
		}
	}
	per(i,n,1){
		rep(j,1,(1<<6)-1){
			if((1<<s[i])&j)cnt[j]++;
			g[j][i]=g[j][i+1]+(bool)(state[i]&j);
		}
	}
	rep(i,1,n){
		int flag=0;
		rep(j,0,5){
			if(!(state[i] & (1<<j)) || !cnt[1<<j])continue;
			int valid=1;
			rep(k,1,(1<<6)-1){
				if(g[k][i+1]<cnt[k]-(bool)((1<<j)&k)){
					valid=0;break;
				}
			} 
			if(valid){
				flag=1;
				ans[i]='a'+j;
				rep(k,1,(1<<6)-1){
					if((1<<j)&k){
						cnt[k]--;
					}
				}
				break;
			}
		}
		if(!flag){printf("Impossible\n");return 0;}
	}
	printf("%s",ans+1);
	return 0;
}