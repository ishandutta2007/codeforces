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

#define maxint (int)1e9
#define eps 1e-9
int n, x[222],y[222];
int main(){
    cin >> n;
    for (int i=1;i<=n;i++)
        cin >> x[i] >> y[i];
    int ans = 0;
    for (int i=1;i<=n;i++){
        bool l=0,r=0,u=0,d=0;
        for (int j=1;j<=n;j++)
            if (x[j]>x[i] && y[j]==y[i])
                r = 1;
            else
            if (x[j]<x[i] && y[j]==y[i])
                l = 1;
            else
            if (x[j]==x[i] && y[j]>y[i])
                u = 1;
            else
            if (x[j]==x[i] && y[j]<y[i])
                d = 1;
        if (l && r && u && d)
            ans++;
    }
    cout << ans << endl;
	return 0;
}