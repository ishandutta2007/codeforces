#include <bits/stdc++.h>
using namespace std;
char s[] = 
"1001010111001010"
;
#define lowbit(x) x&-x
int main() 
{
    int n;
    srand(233);
    cin>>n;
    printf("%c\n", s[n-1]);
    return 0;
}