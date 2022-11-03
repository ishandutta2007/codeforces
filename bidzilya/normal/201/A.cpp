#include <cstdio>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    if (n==3)
       printf("5");
    else
    {
        int i =1;
        while ((i*i+1)/2<n)i+=2;
        printf("%d",i);
    }
    return 0;
}