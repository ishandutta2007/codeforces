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

int N;
int A[10001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&N);

    int i,j,ans=0;

    scanf("%d",A+2);
    scanf("%d",A+3);

    for(i=4; i<pow(2,N+1); i++){
        scanf("%d",A+i);
    }

    for(i=pow(2,N); i>1; i/=2){
        for(j=i; j<i*2; j+=2){
            A[j/2] += max(A[j],A[j+1]);
            ans += abs(A[j]-A[j+1]);
        }
    }

    printf("%d\n",ans);

    return 0;
}