#include <iostream>
#include <fstream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
//#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
#define MAX
#define NIL
typedef long long LL;
typedef stack<int> SI;
typedef vector<int> VI;
typedef deque<int> DQI;
typedef priority_queue<int> PQI;
int main()
{
    //freopen("in.txt","r",stdin);
    int n,m;
    while(cin >> n >> m) {
        if(n == 1) printf("1\n");
        else if(2*m > n) {
            printf("%d\n",m-1);
        }
        else {
            printf("%d\n",m+1);
        }
    }
    return 0;
}