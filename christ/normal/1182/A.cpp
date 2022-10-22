#include<bits/stdc++.h>
using namespace std;
int main () {
    int n;
    scanf ("%d",&n);
    printf ("%d\n",n&1?0:1<<(n>>1));
    return 0;
}