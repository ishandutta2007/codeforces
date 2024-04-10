#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int base = 20;

int bit(int x, int k){
    for (int i=0;i<k;i++)
        x /= 3;
    return x%3;
}

int main(){
    int a,b,c;
    cin >> a >> c;
    int B[18];
    for (int i=0;i<base;i++){
        int A = bit(a,i);
        int C = bit(c,i);
        for (int j=0;j<3;j++)
            if ((A+j)%3==C){
                B[i]=j;
                break;
            }
    }
    int sum =0,st=1;
    for (int i=0;i<base;i++){
        sum += st*B[i];
        st *= 3;
    }
    cout << sum;
    return 0;
}