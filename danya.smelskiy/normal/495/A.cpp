#include <bits/stdc++.h>
using namespace std;
long long n;
inline int get(int x){
    if (x==0) return 2;
    else if (x==1) return 7;
    else if (x==2) return 2;
    else if (x==3) return 3;
    else if (x==4) return 3;
    else if (x==5) return 4;
    else if (x==6) return 2;
    else if (x==7) return 5;
    else if (x==8) return 1;
    else if (x==9) return 2;
}
int main(){
    cin>>n;
    cout<<get(n/10)*get(n%10);
}