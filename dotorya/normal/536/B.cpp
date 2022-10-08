#include <stdio.h>
typedef long long ll;
const ll MOD = 1000000007;
char d[1000050];
int pi[1000050];
int L, L2;
int chk[1000050];
int chk_sum[1000050];
int d2[1000050];
void find_pi()
{
   int i=0,j=-1;
   pi[0]=-1;
   while(i <= L)
   {
      if(j==-1 || d[i]==d[j])
      {
         i++,j++;
         pi[i]=j;
      }
      else j=pi[j];
   }
   L2 = L-pi[L];
   return;
}
int main() {
    int N, M, i;
    scanf("%d %d", &N, &M);
    scanf("%s", d);
    for(L = 0; d[L] != 0; L++);
    find_pi();
    if(M == 0) {
        ll ans = 1;
        for(i = 1; i <= N; i++) ans = (ans*26)%MOD;
        printf("%lld", ans);
        return 0;
    }
    for(i = 1; i <= M; i++) {
        scanf("%d", &d2[i]);
        chk[d2[i]]++;
        if(d2[i]+L <= N) chk[d2[i]+L]--;
    }
    for(i = 1; i < M; i++) if((d2[i+1]-d2[i]) < L && (d2[i+1]-d2[i])%L2 != 0) break;
    if(i != M) {
        printf("0");
        return 0;
    }
    ll ans = 1;
    for(i = 1; i <= N; i++) {
        chk_sum[i] = chk_sum[i-1]+chk[i];
        if(chk_sum[i] == 0) ans = (ans*26)%MOD;
    }
    printf("%lld", ans);
    return 0;
}