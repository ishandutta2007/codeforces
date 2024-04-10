#include<stdio.h>
#include<set>
using namespace std;
set<int>answer;
main(){
    int n,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&i);
        answer.insert(i);
    }
    if(answer.size()<2)puts("NO");
    else{
        set<int>::iterator it=answer.begin();
        it++;
        printf("%d\n",*it);
    }
}