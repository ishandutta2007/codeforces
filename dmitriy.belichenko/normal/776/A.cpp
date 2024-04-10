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

int main()
{
    string s1 , s2;
    cin >> s1 >> s2;
    int n ;
    cin >> n;
    cout << s1 << " " << s2 << endl;
    for(int i = 0; i < n; i++)
    {
        string t1 , t2;
        cin >> t1 >> t2;
        if(t1 == s1) s1 = t2;
        if(t1 == s2) s2 = t2;
        cout << s1 << " " << s2 << endl;
        
    }
     //cout << s1 << " " << s2 << endl;
    return 0;
}