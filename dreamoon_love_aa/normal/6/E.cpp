#include<stdio.h>
#include<set>
using namespace std;
multiset<int>H;
int ann,ma,a[100001];
struct Answer{
    int x,y;
}an[100000];
main(){
    int n,k,i,j;
    scanf("%d%d",&n,&k);
    for(i=j=1;i<=n;i++){
        scanf("%d",&a[i]);
        H.insert(a[i]);
        while(*(--H.end())-*(H.begin())>k){
            H.erase(H.find(a[j++]));
        }
        if(i-j+1>ma){
            ma=i-j+1;
            ann=0;
            an[ann++]=(Answer){j,i};
        }
        else if(i-j+1==ma){
            an[ann++]=(Answer){j,i};
        }
    }
    printf("%d %d\n",ma,ann);
    for(i=0;i<ann;i++)printf("%d %d\n",an[i].x,an[i].y);
}