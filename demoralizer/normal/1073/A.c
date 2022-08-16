#include <stdio.h>
#include <string.h>
#include <math.h>
#define lli long long int
#define sf scanf
#define pf printf
int main(){
    int n; sf("%d",&n);
    char s[n];
    sf("%s",s);
    for(int i=1;i<n;i++){
        if(s[i-1]!=s[i]){printf("YES\n%c%c",s[i-1],s[i]);return 0;}
    }
pf("NO");
}