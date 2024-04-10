#include <cmath>
#include <cstdio>
#include <cstring>
#include "immintrin.h"

int x[3000], y[3000];
long long V[3000*2999/2];
long long temp[3000*2999/2];
int cnt[1<<16];
__m256 bitset[3000][(3000/256+1)];
  
void sort(int n) {
    for (int i = n - 1; i >= 0; --i) {
      ++cnt[(V[i]>>32)&0xFFFF];
    }
    for (int i = 0; i < 0xFFFF; ++i) {
      cnt[i + 1] += cnt[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      temp[--cnt[(V[i]>>32)&0xFFFF]] = V[i];
    }
    memset(cnt, 0, sizeof(cnt));
    
    for (int i = n - 1; i >= 0; --i) {
      ++cnt[(temp[i]>>48)];
    }
    for (int i = 0; i < 0xFFFF; ++i) {
      cnt[i + 1] += cnt[i];
    }
    for (int i = n - 1; i >= 0; --i) {
      V[--cnt[(temp[i]>>48)]] = temp[i];
    }
}

void addBit(__m256 *mask, int bit) {
    long long *ptr = (long long*)mask;
    ptr[bit>>6]|=1LL<<(bit&63);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d %d", &x[i], &y[i]);
    int small=0, big=n*(n-1)/2;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int dy = y[j]-y[i], dx = x[j]-x[i];
            int dist = dx * dx + dy * dy;
            long long id = ((long long)dist<<32)|(i<<16)|j;
            if (dist < 1000000) V[small++] = id; else V[--big] = id;
        }
    }
    sort(n*(n-1)/2);

    int res = 0;
    for (int i=n*(n-1)/2-1; i>=0; i--) {
        int a = (V[i]>>16)&0xFFFF;
        int b = V[i]&0xFFFF;

        __m256 result =  _mm256_setzero_ps();
        __m256 (&seta)[12] = bitset[a], (&setb)[12] = bitset[b];
        for (int j=(n-1)>>8; j >= 0; --j) {
            __m256 ok = _mm256_and_ps(seta[j], setb[j]);
            result = _mm256_or_ps(result, ok);
        }
        
        long long* c = (long long*)(&result);
        for(int it = 0; it < 4; it++) if (c[it]) {
            printf("%.9f\n", std::sqrt((double)(V[i]>>32)) * 0.5);
            return 0;
        }
        addBit(seta, b);
        addBit(setb, a);
    }

    return 0;
}