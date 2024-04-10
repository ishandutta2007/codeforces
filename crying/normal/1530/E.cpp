#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
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
const int MAXN=1e5+10;
int T,n;
int cnt[26];
char s[MAXN];
int main(){
	cin>>T;
	while(T--){
		memset(cnt,0,sizeof cnt);
		cin>>(s+1);n=strlen(s+1);
		rep(i,1,n){
			cnt[s[i]-'a']++;
		}
		int flag=0;
		rep(j,0,25){
			if(cnt[j]==n){
				flag=1;
				printf("%s\n",s+1);
				break;
			}
		}
		if(flag)continue;
		rep(j,0,25){
			if(cnt[j]==1){
				flag++;
			}
		}
		if(flag>=1){
			//0
			rep(j,0,25){
				if(cnt[j]==1){
					printf("%c",'a'+j);
					cnt[j]=0;
					break;
				}
			}
			rep(j,0,25){
				while(cnt[j]){
					printf("%c",'a'+j);
					cnt[j]--;
				}
			}
			printf("\n");
			continue; 
		}
		flag=-1;
		rep(j,0,25){
			if(cnt[j] && flag==-1){
				if(n-cnt[j] >= cnt[j]-2){
					printf("%c",'a'+j);
					printf("%c",'a'+j);
					cnt[j]-=2;
					while(cnt[j]--){
						rep(k,j+1,25){
							if(cnt[k]){
								printf("%c",'a'+k);
								cnt[k]--;
								break;
							}
						}
						printf("%c",'a'+j);
					}
					rep(k,j+1,25){
						while(cnt[k]){
							printf("%c",'a'+k);
							cnt[k]--;
						}
					}
				}else{
					int num=0;
					rep(k,0,25){
						if(cnt[k])num++;
					}
					if(num==2){
						printf("%c",'a'+j);
						cnt[j]--;
						rep(k,j+1,25){
							while(cnt[k]){
								printf("%c",'a'+k); 
								cnt[k]--;
							}
						}
						while(cnt[j]){
							printf("%c",'a'+j);
							cnt[j]--;
						}
					}else{
						printf("%c",'a'+j);
						cnt[j]--;
						int pos=0;
						rep(k,j+1,25){
							if(cnt[k]){
								printf("%c",'a'+k);
								cnt[k]--;
								pos=k;
								break;
							}
						}
						while(cnt[j]){
							printf("%c",'a'+j);
							cnt[j]--;
						}
						rep(x,pos+1,25){
							if(cnt[x]){
								printf("%c",'a'+x);
								cnt[x]--;
								break;
							} 
						}
						rep(k,j+1,25){
							while(cnt[k]){
								printf("%c",'a'+k);
								cnt[k]--;
							}
						}
					}
				}
				flag=1;
			}
		}
		printf("\n");
	}

	return 0;
}
/*
1
abababa


*/