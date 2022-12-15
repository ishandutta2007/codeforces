#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        if(n%7==0) printf("%d\n",n);
        else{
            int b=n-n%10;
            for(int i=0;i<10;i++) if((b+i)%7==0){
                    printf("%d\n",b+i);
                    break;
                }
        }
    }
    return 0;
}