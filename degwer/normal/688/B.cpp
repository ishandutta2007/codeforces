#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    cout<<s;
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}