#include<stdio.h>
#include<set>
using namespace std;
int gcd(int x,int y){
    while((x%=y)&&(y%=x));
    return x+y;
}
set<int>H;
main(){
    int a,b,g,x,y,i,n;
    scanf("%d%d",&a,&b);
    g=gcd(a,b);
    for(i=1;i*i<=g;i++){
        if(g%i==0){
            H.insert(i);
            H.insert(g/i);
        }
    }
    set<int>::iterator it;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&x,&y);
        it=H.upper_bound(y);
        if(it==H.begin())puts("-1");
        else{
            it--;
            if(*it>=x)printf("%d\n",*it);
            else puts("-1");
        }
    }
}