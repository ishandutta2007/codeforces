#include <cstdio>
#include <cstdlib>
int main(){
    int t;
    for(int i = 0; i < 5; ++i)
        for(int j = 0; j < 5; ++j){
            scanf("%d", &t);
            if(t==1){
                printf("%d\n", abs(i-2) + abs(j-2));
                return 0;}
        }
}