#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int w1, h1, w2, h2;
    cin>>w1>>h1>>w2>>h2;
    cout<<w1+2+w2+2+(h1+h2)*2+(w1-w2);
}