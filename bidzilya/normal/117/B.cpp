#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iterator>
using namespace std;

int main(){
    int a,b,mod;

    cin >> a >> b >> mod;
    for (__int64 i=0;i<=min(a,mod);i++){
        __int64 c = (mod-((i*1000000000)%mod))%mod;
        if (b<c){
            cout << 1 << ' ';
            int u=0,a[10];
            while (i>0){
                a[++u]=i%10;
                i /= 10;
            }
            for (int j=u+1;j<=9;j++)
                a[j]=0;
            for (int j=9;j>=1;j--)
                cout << a[j];
            return 0;
        }
    }
    cout << 2;
    return 0;
}