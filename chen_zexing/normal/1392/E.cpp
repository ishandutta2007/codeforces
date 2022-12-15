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
long long a[30][30];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            long long t=1;
            t<<=(i+j);
            a[i][j]=(i%2==0)*t;
        }
    for(int i=1;i<=n;i++,cout<<endl)
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
    fflush(stdout);
    int T;
    cin>>T;
    while(T--)
    {
        long long p;
        int x=1,y=1;
        cin>>p;
        cout<<"1 1"<<endl;
        while(x+y<2*n)
        {
            if(p&(1LL*1<<(x+y+1))&&(x%2)||(!(p&(1LL*1<<(x+y+1))))&&(x%2==0)) x++;
            else y++;
            cout<<x<<" "<<y<<endl;
        }
        fflush(stdout);
    }
    return 0;
}