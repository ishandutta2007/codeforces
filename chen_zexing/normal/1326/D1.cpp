#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
char s[5005],r[5005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%s",s);
        int l=strlen(s),st,ed,ll=0,lll=0;
        for(int i=l-1;i>=0;i--) r[i]=s[l-i-1];
        for(st=0;st<=l/2-1&&s[st]==r[st];st++);
        ed=l-st-1;
        for(int i=ed-st+1;i>=1;i--)
        {
            int f=1;
            for(int j=st;j<=st+i-1;j++)
                if(s[j]!=s[st*2+i-j-1])
                {
                    f=0;
                    break;
                }
            if(f){
                ll=i;
                break;
            }
            f=1;
            for(int j=ed;j>=ed-i+1;j--)
                if(s[j]!=s[ed*2-i-j+1])
                {
                    f=0;
                    break;
                }
            if(f)
            {
                lll=i;
                break;
            }
        }
        for(int i=0;i<st;i++) printf("%c",s[i]);
        if(ll>=lll) for(int i=st;i<st+ll;i++) printf("%c",s[i]);
        else for(int i=ed-lll+1;i<=ed;i++) printf("%c",s[i]);
        for(int i=ed+1;i<l;i++) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}