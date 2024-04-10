#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
int main(){
    LL a,b;
    cin>>a>>b;
    if(a<b)puts("-1");
    else printf("%.12f\n",(a+b)/(2.*((a+b)/(2*b))));
    return 0;
}