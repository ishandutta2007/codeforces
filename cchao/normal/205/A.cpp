#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int min,tmp,no=1;
    cin >> min;
    int flag = 0;
    for(int k=2;k<=n;k++)
    {
        cin >> tmp;
        if(tmp==min) flag = 1;
        if(tmp < min)
        {
            no = k;
            min = tmp;
            flag = 0;
        }
    }
    if(flag == 0)
    {
        cout << no << endl;
    }
    else
        cout << "Still Rozdil" << endl;
    return 0;
}