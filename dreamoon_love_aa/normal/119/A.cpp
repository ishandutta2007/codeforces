#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<string.h>
#include<algorithm>
using namespace std;
int main(){
    int i,j,k,a,n,b,now=0;
    scanf("%d%d%d",&a,&b,&n);
    while(n){
        if(!now)n-=__gcd(a,n);
        else n-=__gcd(b,n);
        now^=1;
    }
    printf("%d\n",now^1);
    return 0;
}