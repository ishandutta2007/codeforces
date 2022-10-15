#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    char s[105];
    cin.getline(s,105);
    ///Danil", "Olya", "Slava", "Ann" and "Nikita
    int n=strlen(s),sum=0;
    for(int i=0;i<n;i++)
    {
        if(i+4<n and s[i]=='D' and s[i+1]=='a' and s[i+2]=='n' and s[i+3]=='i' and s[i+4]=='l')sum++;
        if(i+5<n and s[i]=='N' and s[i+1]=='i' and s[i+2]=='k' and s[i+3]=='i' and s[i+4]=='t' and s[i+5]=='a')sum++;
        if(i+4<n and s[i]=='S' and s[i+1]=='l' and s[i+2]=='a' and s[i+3]=='v' and s[i+4]=='a')sum++;
        if(i+3<n and s[i]=='O' and s[i+1]=='l' and s[i+2]=='y' and s[i+3]=='a')sum++;
        if(i+2<n and s[i]=='A' and s[i+1]=='n' and s[i+2]=='n')sum++;
    }
    if(sum==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}