#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main(){
    char a[60], b[60];
    scanf("%s%s", a, b);
    int pos = 0;
    for(int i = 0; b[i]; ++i)
        if(a[pos] == b[i]) ++pos;
    printf("%d\n", pos+1);
    return 0;
}