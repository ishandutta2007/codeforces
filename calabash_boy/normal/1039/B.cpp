#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define query(l,r) {printf("%lld %lld\n",l,r);fflush(stdout);scanf("%s",s);}while(0);
#define is_yes (s[0]=='Y')
#define rand(l,r) (l + 1LL*rand()%(r-l+1))
char s[100];
int main(){
    srand(time(0));
    LL n,k;
    scanf("%lld%lld",&n,&k);
    LL l = 1,r = n;
    while (r != l){
        if (r - l <= 50){
            LL pos = rand(l,r);
            query(pos,pos);
            if (is_yes){
                return 0;
            }else{
                l = max(1LL,l - k);
                r = min(n,r+ k);
            }
        }
        LL mid = l+ r >>1;
        query(l,mid);
        if (is_yes){
            r = min(n,mid+k);
            l = max(1LL,l-k);
        }else{
            l = max(1LL,mid+1-k);
            r = min(n,r + k);
        }
    }
    printf("%lld %lld\n",l,l);
    fflush(stdout);
    return 0;
}