#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
#define il inline
typedef long long ll;
using namespace std;
const int MAXN=1e5+10;
int T,n,k;
int cnt[30];
char str[MAXN];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%s",&n,&k,str+1);
		if(n%k){printf("-1\n");continue;}
		memset(cnt,0,sizeof cnt);
		rep(i,1,n){
			cnt[str[i]-'a'+1]++;
		}
		rep(i,1,26){
			if(cnt[i]%k)goto FAIL;
		}
		printf("%s\n",str+1);continue;
		FAIL:; 
		rep(i,1,26)cnt[i]%=k;
		per(i,n,1){
			cnt[str[i]-'a'+1]=(cnt[str[i]-'a'+1]-1+k)%k;
			rep(j,str[i]+1,'z'){
				cnt[j-'a'+1]=(cnt[j-'a'+1]+1)%k;
				int rest=n-i;
				rep(c,1,26){
					if(cnt[c])rest-=(k-cnt[c]);
				}
				if(rest>=0 && rest%k==0){
					rep(idx,1,i-1)printf("%c",str[idx]);
					printf("%c",(char)j);
					while(rest--)printf("a");
					rep(c,1,26){
						if(cnt[c]){
							rest=k-cnt[c];
							while(rest--)printf("%c",'a'+c-1);
						}
					}
					printf("\n");
					goto SUCCES;
				}
				cnt[j-'a'+1]=(cnt[j-'a'+1]-1+k)%k;
			}
		}
		printf("-1\n");
		SUCCES:continue;
	}
	return 0;
}