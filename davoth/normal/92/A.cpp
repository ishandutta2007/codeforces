#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,m,c=0;
    cin >> n >> m;
    while(true){
        c++;
        int a=c%n;
        if(a==0) a=n;
        if(m<a) break;
        m-=a;
    }
    cout << m;
    return 0;
}