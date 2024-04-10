#include <cstdio>
#include <iostream>
using namespace std;
#define M 200010
int last[M]={0}, sz = 1, ad[M]={0};
double sum = 0;
int main(){
    int n; scanf("%d", &n);
    while(n--){
        int op; scanf("%d", &op);
        switch(op){
            case 1:{
                int pos, quan; scanf("%d%d", &pos, &quan);
                ad[pos-1] += quan;
                sum += pos * quan;
                break;
            }
            case 2:{
                int x; scanf("%d", &x);
                last[sz++] = x;
                sum += x;
                break;
            }
            case 3:{
                sz--;
                sum -= (last[sz] + ad[sz]);
                ad[sz-1] += ad[sz];
                ad[sz] = 0;
                break;
            }
        }
        printf("%.10lf\n", sum/sz);
    }
    return 0;
}