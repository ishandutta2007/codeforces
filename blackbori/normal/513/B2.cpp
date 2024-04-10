#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

long long N,M;
bool B[53];
int bl=0,s,e;
int ans[53];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%lld %lld",&N,&M);
    M--;
    int i,j;
    for(i=1; i<=52; i++) B[i] = 0;
    while(M>0){
        B[++bl] = M%2;
        M=M/2;
    }

    s=1; e=N;
    for(i=1; i<=N; i++){
        if(B[N-i]){
            ans[e] = i;
            e--;
        }
        else{
            ans[s] = i;
            s++;
        }
    }

    for(i=1; i<N; i++) printf("%d ",ans[i]);
    printf("%d\n",ans[N]);

    return 0;
}