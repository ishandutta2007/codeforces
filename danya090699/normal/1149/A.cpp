#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q1=0, q2=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(x==1) q1++;
        else q2++;
    }
    if(q2) cout<<"2 ", q2--;
    if(q1) cout<<"1 ", q1--;
    while(q2) cout<<"2 ", q2--;
    while(q1) cout<<"1 ", q1--;
}