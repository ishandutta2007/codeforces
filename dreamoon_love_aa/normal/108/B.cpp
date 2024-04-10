#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
int a[100000];
set<int>H;
main(){
    int n,i,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        H.insert(x);
    }
    if(H.size()>=2){
        set<int>::iterator it1,it2;
        it1=H.begin();
        it2=++H.begin();
        while(it2!=H.end()){
            if(*it2<*it1*2)break;
            it1++;
            it2++;
        }
        if(it2!=H.end())puts("YES");
        else puts("NO");
    }
    else puts("NO");
}