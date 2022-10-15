#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[20];
    cin.getline(s,20);
    int n=strlen(s),i,j,sum=0;
    for(i=0;i<n/2;i++)
        if(int{s[i]}!=int{s[n-i-1]})
               sum++;
    if(sum==0 and n%2==1)
        sum=1;
    if(sum==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}