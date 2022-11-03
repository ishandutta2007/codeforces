#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main(){
    int n,m;
    long long str[1000],stl[1000];
    cin >> n >> m;
    for (int i=0;i<1000;i++)
    {
        str[i] = 0;
        stl[i] = 0;
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            long long a;
            cin >> a;
            str[i] += a;
            stl[j] += a;
        }
    int iStr, iStl;
    long long minStr = 1000000000000000000LL;
    long long minStl = minStr;
    for (int i=-1;i<m+1;i++)
    {
        long long tmp = 0;
        long long r = 2;
        for (int j=i;j>=0;j--)
        {
            tmp += stl[j]*r*r;    
            r += 4;
        }
        r = 2;
        for (int j=i+1;j<m;j++)
        {
            tmp += stl[j]*r*r;
            r += 4;
        }
        
        if (tmp<minStl)
        {
                       iStl = i+1;
                       minStl = tmp;
        }
    }
    
    for (int i=-1;i<n+1;i++)
    {
        long long tmp = 0;
        long long r = 2;
        for (int j=i;j>=0;j--)
        {
            tmp += str[j]*r*r;
            r += 4;
        }
        r = 2;
        for (int j=i+1;j<n;j++)
        {
            tmp += str[j]*r*r;
            r += 4;
        }
        
        if (tmp<minStr)
        {
                       iStr = i+1;
                       minStr = tmp;
        }
    }
    
    cout << minStr+minStl << endl;
    cout << iStr << " " << iStl;
    return 0;
}