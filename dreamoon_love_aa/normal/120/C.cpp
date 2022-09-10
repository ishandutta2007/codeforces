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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k,n,an=0,x;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        j=x/k;
        if(j<3)an+=x%k;
        else an+=x-k*3;
    }
    printf("%d\n",an);
    return 0;
}