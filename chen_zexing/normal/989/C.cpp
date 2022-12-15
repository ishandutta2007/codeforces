#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int ans[55][55];
int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<"50 50"<<endl;
    for(int i=1;i<=50;i++)
        for(int j=1;j<=50;j++)
            if(i>25)
                ans[i][j]++;
    a--;
    b--;
    for(int i=1;i<=25;i+=2)
        for(int j=1;j<=50;j+=2)
        {
            if(b)
            {
                ans[i][j]=1;
                b--;
            }
            else if(d)
            {
                ans[i][j]=3;
                d--;
            }
            if(b==0&&d==0) break;
        }
    for(int i=27;i<=50;i+=2)
        for(int j=1;j<=50;j+=2)
        {
            if(a)
            {
                ans[i][j]=0;
                a--;
            }
            else if(c)
            {
                ans[i][j]=2;
                c--;
            }
            if(a==0&&c==0) break;
        }
    for(int i=1;i<=50;i++,printf("\n"))
        for(int j=1;j<=50;j++)
            cout<<char(ans[i][j]+'A');
    return 0;
}