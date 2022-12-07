#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    long long an=0;
    string s[2];
    cin>>s[0]>>s[1];
    int q[4]={0, 0, 0, 0};
    for(int a=0; a<n; a++)
    {
        int cu=0;
        if(s[0][a]=='1') cu++;
        if(s[1][a]=='1') cu+=2;
        if(cu==0) an+=q[1]+q[3];
        if(cu==1) an+=q[0]+q[2];
        if(cu==2) an+=q[1];
        if(cu==3) an+=q[0];
        q[cu]++;
    }
    cout<<an;
}