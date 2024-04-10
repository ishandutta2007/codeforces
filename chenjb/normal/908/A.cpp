#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
char s[2000];
int main() 
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    int ans=0;
    for(int i=1;i<=len;i++)
    {
        if (s[i]>='0'&&s[i]<='9')
        {
        	if ((s[i]-'0')%2!=0) ans ++;
        } 
        else 
        {
            if (s[i] =='a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o'  ||s[i] == 'u')ans ++;
        }
    }
    cout<<ans<<endl;
    return 0;
}