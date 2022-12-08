#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;
int n, a, b, x, y;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &n, &a, &b);
        scanf("%d %d", &x, &y);
        if(a+b >= 2*x && 2*n-a-b >= 2*y &&
           !(a+b == 2*x && abs(a-b)%2==1) && !(2*n-a-b == 2*y && abs(a-b)%2==1)) printf("YES\n");
        else printf("NO\n");
    }
}