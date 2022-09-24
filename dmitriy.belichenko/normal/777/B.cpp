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

int main()
{
    int n;
    cin >> n;
    set<int> a;
    set<int> b;
    vector<int> s , h;
    string s1 , s2;
    cin >> s1 >> s2;
    int used[1001];
    int usd[1001];
    
    for(int i = 0; i < n; i++)
    {
        s.push_back((int)s1[i] - '0');
        h.push_back((int)s2[i] - '0');
        used[i] = 0;
        usd[i] = 0;
    }
    
    int mn = n, mx= 0;
    sort(h.begin(), h.end());
    sort(s.begin(), s.end());
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0;  j < n; j++)
        {
            if(h[j] > s[i] && used[j] == 0)
            {
                mx++;
                used[j] = 1;
                break;
            }
        }
    }
    //int mn = n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0;  j < n; j++)
        {
            if(h[j] >= s[i] && usd[j] == 0)
            {
                mn--;
                usd[j] = 1;
                break;
            }
        }
    }
    
    cout << mn << endl;
    cout << mx << endl;
    
    
    
}