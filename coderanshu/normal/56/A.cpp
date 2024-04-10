#include<bits/stdc++.h>
using namespace std;
// nice concept of 2d array
char s[102];
int match()
{
    char k[11][100]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE","TEQUILA", "VODKA", "WHISKEY", "WINE"};
    for(int i=0;i<11;i++)
    {
        if(strcmp(s,k[i])==0)
        return 1;
    }
    return 0; 
}
int main()
{
    ios_base::sync_with_stdio(0);
    int n,i,count=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        if((s[0]<='9' && strlen(s)==1) || (s[0]=='1' && s[1]<'8' && strlen(s)==2) || match())
        count++;
    }
    cout<<count;
    return 0;
}