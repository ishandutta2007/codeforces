#include <bits/stdc++.h>
using namespace std;

long long n,last,kol;
int main(){
    cin>>n;
    last=1;
    while (true){
        if (n%last!=0){
            cout<<(n/last)+1;
            return 0;
        }
        last*=3;
        ++kol;
    }

}