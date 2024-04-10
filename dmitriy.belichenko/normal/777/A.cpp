//
//  main.cpp
//  codegorces
//
//  Created by Dmitry Belichenko on 23.02.17.
//  Copyright  2017 Dmitry Belichenko. All rights reserved.
//

#include<iostream>
#include<set>
#include <map>
#include <vector>
#include<string>
#include <math.h>
#include<algorithm>
using namespace std;
bool pri(int k)
{
    if (k == 1) return false;
    for (int i = 2; i * i <= k; i++)
    {
        
        if (k % i == 0) return false;
    }
    return true;
}
long gcd(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    
    else
    {
        return gcd(b, a % b);
    }
}
long gcc(long a, long b)
{
    if (b == 0)
    {
        return a;
    }
    
    else
    {
        return gcd(b, a % b);
    }
}



using namespace std;

int main()
{
   
    int n, x;
    cin >> n >> x;
    n %= 6;
    int a[3];
    a[x] = 1;
    for (int i = n; i > 0; i--)
    {
        if (i % 2 == 0) swap(a[1], a[2]);
        else swap(a[0], a[1]);
    }
    if (a[0] == 1) cout << 0 << endl;
    else if (a[1] == 1) cout << 1 <<endl;
    else cout << 2 << '\n';
    return 0;
}