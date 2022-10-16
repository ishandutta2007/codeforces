#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
     
const int ALPHA=62;
     
const int MOD=998244353;
     
int cnt[11][ALPHA][ALPHA];
     
char str[16];
char rstr[16];
     
std::map<char,int> cps;
     
int compress(char c){
  if(cps.count(c)) return cps[c];
  int index=cps.size();
  return cps[c]=index;
}
     
void add(){
  static std::set<std::string> set;
  std::string S(str);
  if(set.count(S)) return;
  set.insert(S);
  //printf("cnt[%d][%d][%d]++\n",(int)S.size(),compress(S.front()),compress(S.back()));
  cnt[S.size()][compress(S.front())][compress(S.back())]++;
}
     
int dp[ALPHA][ALPHA][ALPHA];

static int f(int a,int b,int c,int d){
  return 1LL*dp[a][b][c]*dp[a][b][d]%MOD*dp[a][c][d]%MOD*dp[b][c][d]%MOD;
}
     
int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%s",str);
    int len=strlen(str);
    add();
    std::reverse(str,str+len);
    add();
  }
  int total=0;
  for(int len=3;len<=10;len++){
    memset(dp,0,sizeof dp);
    for(int d=0;d<ALPHA;d++){
      for(int a=0;a<ALPHA;a++){
	//if(cnt[len][d][a]==0) continue;
	for(int b=0;b<=a;b++){
	  //if(cnt[len][d][b]==0) continue;
	  for(int c=0;c<=b;c++){
	    //if(cnt[len][d][b]==0) continue;
	    dp[a][b][c]=(dp[a][b][c]+1LL*cnt[len][d][a]*cnt[len][d][b]%MOD*cnt[len][d][c])%MOD;
	  }
	}
      }
    }
    for(int a=0;a<ALPHA;a++){
      for(int b=0;b<a;b++){
    	for(int c=0;c<b;c++){
    	  //if(dp[a][b][c]==0) continue;
    	  for(int d=0;d<c;d++){
    	    total=(total+24LL*f(a,b,c,d))%MOD;
    	  }
	  total=(total+12LL*f(a,a,b,c))%MOD;
	  total=(total+12LL*f(a,b,b,c))%MOD;
	  total=(total+12LL*f(a,b,c,c))%MOD;
    	}
	total=(total+4LL*f(a,a,a,b))%MOD;
	total=(total+6LL*f(a,a,b,b))%MOD;
	total=(total+4LL*f(a,b,b,b))%MOD;
      }
      total=(total+1LL*f(a,a,a,a))%MOD;
    }
  }
  printf("%d\n",total);
}