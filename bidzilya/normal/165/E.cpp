#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;

const int max_int = (1<<22)-1;
int a[1000001];
int f[max_int+1];
int n;

int main(){
    cin >> n;
    for (int i=0;i<=max_int;i++)
        f[i] = -1;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        f[a[i]^max_int] = a[i];
    }
    for (int i=max_int;i>=0;i--)
        if (f[i]<0)
            for (int j=0;j<22;j++)
                if (!(i&(1<<j)))
                    if (f[i + (1<<j)]>0){
                        f[i] = f[i+(1<<j)];
                        break;
                    }
    for (int i=1;i<=n;i++)
        cout << f[a[i]] << ' ';
	return 0;
}