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
char s[100005];
int a[100005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int x;
        scanf("%s",s);
        cin>>x;
        int l=strlen(s);
        for(int i=0;i<l;i++) a[i]=1;
        for(int i=0;i<l;i++)
        {
            if(s[i]=='0')
            {
                if(i-x>=0) a[i-x]=0;
                if(i+x<l) a[i+x]=0;
            }
        }
        int f=1;
        for(int i=0;i<l;i++)
            if(s[i]=='1')
            {
                int c=0;
                if(i-x>=0&&a[i-x]) c=1;
                if(i+x<l&&a[i+x]) c=1;
                if(c==0){
                    f=0;
                    break;
                }
            }
        if(f)
        {
            for(int i=0;i<l;i++) printf("%d",a[i]);
            printf("\n");
        }
        else printf("-1\n");
    }
    return 0;
}