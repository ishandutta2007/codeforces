#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int temp;
    int acnt=0,bcnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        acnt+=temp;
    }
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        bcnt+=temp;
    }
    if(acnt>=bcnt)
        puts("Yes");
    else puts("No");

    return 0;
}