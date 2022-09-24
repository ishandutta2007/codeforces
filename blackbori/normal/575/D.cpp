#include <cstdio>

using namespace std;

int main()
{
    int i;
    
    printf("2000\n");
    for(i=1;i<=1000;i++) printf("%d 1 %d 2\n",i,i);
    for(i=1000;i>=1;i--) printf("%d 1 %d 2\n",i,i);
    
    return 0;
}