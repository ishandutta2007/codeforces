#include <emmintrin.h>
#include <smmintrin.h>
#include <stdio.h>

int n,m;
int arr[100004];

long long sum(int l, int r) {
            long long sum = 0;
            int *start = arr + l, *end = arr + r + 1;
            
            __m128i temp = _mm_setzero_si128();
            
            while ((start < end) && ((int)start & 15) ) {
                sum += *start;
                ++start;
            }
            
            int iterations = 2000;
            
            while (start + 4 < end) {
                temp = _mm_add_epi32(temp, *((__m128i*) start));
                start += 4;
                if (--iterations == 0) {
                    sum += *(((int*)&temp) + 0);
                    sum += *(((int*)&temp) + 1);
                    sum += *(((int*)&temp) + 2);
                    sum += *(((int*)&temp) + 3);
                    temp = _mm_setzero_si128();
                    iterations = 2000;
                }
            }
            
            sum += *(((int*)&temp) + 0);
            sum += *(((int*)&temp) + 1);
            sum += *(((int*)&temp) + 2);
            sum += *(((int*)&temp) + 3);
           /* sum += _mm_extract_epi32(temp, 0);
            sum += _mm_extract_epi32(temp, 1);
            sum += _mm_extract_epi32(temp, 2);
            sum += _mm_extract_epi32(temp, 3);
            */
            while (start < end) {
                sum += *start;
                ++start;
            }
            return sum;
}

void xor(int l, int r, int xorValue) {

            __m128i xor128 = _mm_set_epi32 (xorValue, xorValue, xorValue, xorValue);
            
            int *start = arr + l, *end = arr + r + 1;
            
            while ((start < end) && ((int)start & 15) ) {
                *start^=xorValue;
                ++start;
            }
            
            while (start + 4 < end) {
                _mm_store_si128((__m128i*) start, _mm_xor_si128(*((__m128i*) start), xor128));
                start += 4;
            }
            
            while (start < end) {
                *start^=xorValue;
                ++start;
            }
                
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&m);
    int type,l,r,x;
    for(int t=0;t<m;t++){
        scanf("%d",&type);
        if(type==1){
            scanf("%d %d",&l,&r);
            printf("%I64d\n",sum(l,r));
        } else {
            scanf("%d %d %d",&l,&r,&x);
            xor(l, r, x);
        }
    }
}