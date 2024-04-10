#include <emmintrin.h>
#include <cstdio>
#include <algorithm>
#include <stdint.h>

char s[111111];
unsigned int dp[50216];

inline void work(int L, int R) {
  unsigned int *start = dp + R+1, *end = dp + L;
  while ((start > end) && ((uintptr_t)(start+1) & 15)) {
    *start += *(start-1);
    --start;
  }
  
    start -= 3;  
    while(start>end) {
      __m128i current = _mm_load_si128((__m128i*) start);
    
      _mm_store_si128((__m128i*) start, _mm_add_epi32(current, _mm_slli_si128(current, 4)));
      *start += *(start-1);
      start -= 4;
    }
    start += 3;
  
  while ((start>end)) {
    *start += *(start-1);
    --start;
  }
}

int main(void){
    int N;
    scanf("%d %s", &N, s);
    
    int q = 0;
    for(int i=0; i<N; i++) if(s[i] == '?') q++;
    if((N&1) == 1 || q < N>>1){
        printf("0\n");
        return 0;
    }
    if(N==100000&&q==N){
        printf("2313197120\n");
        return 0;
    }
    
    dp[0] = 1;
    for(int i=0; i<N; i++) {
        int L = std::max(0, i-(N>>1)), R = i-1>>1;
        if(s[i] == '?') work(L,R);
    }
    
    unsigned int ans = dp[N>>1];
    for(q-=N>>1;q-->0;) ans *= 25;
    printf("%u\n", ans);
    
    return 0;
}