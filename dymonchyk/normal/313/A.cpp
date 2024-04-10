#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    if (n>=0) {
        cout << n << endl;
        return 0;
    }
    n*=-1;
    char str1[20],str2[20];
    ltoa(n,str1,10);
    ltoa(n,str2,10);
    str1[strlen(str1)-1]='\0';
    str2[strlen(str2)-2]=str2[strlen(str2)-1];
    str2[strlen(str2)-1]='\0';
    int v1=atoi(str1),v2=atoi(str2);
    cout << max(-v1,-v2) << endl;
    return 0;
}