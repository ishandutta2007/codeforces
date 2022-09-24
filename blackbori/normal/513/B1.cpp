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

int N,M;
int B[53],bl=0,s,e;
int ans[53];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d %d",&N,&M);
    M--;
    int i,j;
    for(i=1; i<=52; i++) B[i] = 0;
    while(M>0){
        B[++bl] = M%2;
        M=M/2;
    }
    //for(i=10; i>0; i--) printf("%d ",B[i]);

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