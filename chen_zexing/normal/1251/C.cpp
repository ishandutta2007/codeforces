#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
#include <bitset>
#include <vector>
using namespace std;
char s[3000005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int x=0,y=0;
        string ans="";
        scanf("%s",s);
        int l=strlen(s);
        while((s[x]-'0')%2&&x<l) x++;
        while((s[y]-'0')%2==0&&y<l) y++;
        //cout<<x<<" "<<y<<endl;
        while(x<l||y<l)
        {
            if(y>=l)
            {
                ans+=s[x++];
                while((s[x]-'0')%2&&x<l) x++;
            }
            else if(x>=l)
            {
                ans+=s[y++];
                while((s[y]-'0')%2==0&&y<l) y++;
            }
            else if(s[x]<=s[y])
            {
                ans+=s[x++];
                while((s[x]-'0')%2&&x<l) x++;
            }
            else
            {
                ans+=s[y++];
                while((s[y]-'0')%2==0&&y<l) y++;
            }
        }
        cout<<ans<<endl;
    }
}