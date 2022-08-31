#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <string.h>

using namespace std;

int main()
{

    int r,c;
    cin>>r>>c;
    char a[101][101];
    a[r-1][c]='.';
    for(int i=0;i<r;i++)
        cin>>a[i];
    int ans=0;
    for(int i=0;i<c;i++)
    {
        if(a[r-1][i]=='B' and a[r-1][i+1]!='B')
            ans++;

    }
    cout<<ans;
    return 0;
}