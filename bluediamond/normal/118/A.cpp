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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    char ch;
    while(1)
    {
        ch=cin.get();
        if(ch=='\n')
            break;
        if(ch=='A' or ch=='O' or ch=='Y' or ch=='E' or ch=='U' or ch=='I')
            continue;
        if(ch=='a' or ch=='o' or ch=='y' or ch=='e' or ch=='u' or ch=='i')
            continue;
        cout<<".";
        if('A'<=ch and ch<='Z')
            cout<<char('a'+ch-'A');
        else
            cout<<ch;
    }
    return 0;
}
/**s
**/