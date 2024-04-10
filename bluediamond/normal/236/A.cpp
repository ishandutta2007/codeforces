#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;
#define ll long long
int ap[30];
char ch;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    while(1)
    {
        ch=cin.get();
        if(ch=='\n')
            break;
        ap[ch-'a']=1;
    }
    int s=0;
    for(int i=0;i<26;i++)
        s+=ap[i];
    if(s%2==0)
        cout<<"CHAT WITH HER!";
    else
        cout<<"IGNORE HIM!";
    return 0;
}
/**
**/